#!/usr/bin/python

import os
import sys
import shutil
import logging
import argparse
import configparser

description = '''
Deploy pwnkit template to given path.
'''

root_path      = os.path.abspath(os.path.dirname(__file__))
templates_path = os.path.join(root_path, "templates")
sources        = {"scripts": os.path.join(root_path, "scripts"),
                  "samples": os.path.join(root_path, "samples"),
                  "etc"    : os.path.join(root_path, "etc")}

def template_check(name):
    ''' Check template exist and return its path.
    '''

    file = name + ".template"

    if file in os.listdir(templates_path):
        return os.path.join(templates_path, file)

    return False

def source_check(source, name):
    ''' Check source exists and return its path.
    '''

    if not source in sources:
        return False

    if not name in os.listdir(sources[source]):
        return False
        
    return os.path.join(sources[source], name)

def build_dir(config, path):
    ''' Build directory of template.
    '''

    if config['path'].find('..') != -1:
        return None
    elif config['path'].startswith('/'):
        to_path = path + config['path']
    else:
        to_path  = os.path.join(path, config['path'])

    if not os.path.exists(to_path):
        os.mkdir(to_path, 0777)

    copylist = []

    for s in sources:
        if not ((s in config) and (config[s])):
            continue
        for e in map(str, config[s].split(" ")):
            e_path = source_check(s, e)
            if not e_path:
                logging.warning("%s %s not exist.", s, e)
                continue
            copylist.append((e_path, str(os.path.join(to_path, e))))

    return copylist

def deploy(template, path):
    ''' Deploy template to path
    '''

    # Get template path
    template_path = template_check(template)
    if not template_path:
        raise FileNotFoundError("Template %s not exist." % template)

    # Parse template
    config = configparser.ConfigParser()
    config.read(template_path)
    
    # Print default.
    default_config = config['DEFAULT']
    logging.info("%s - %s", default_config['name'], default_config['description'])

    # Build copytrees
    dirlist = config.keys()
    dirlist.pop(dirlist.index("DEFAULT"))
    copylist = []
    for d in dirlist:
        copylist += build_dir(config[d], path)

    # Copy
    for src, dest in copylist:
        if os.path.isfile(src):
            shutil.copy(src, dest)
        if os.path.isdir(src):
            shutil.copytree(src, dest)

    logging.info("Template %s deployed to %s.", template, path)
    return 0

if __name__ == "__main__":

    # Parse arguments
    parser = argparse.ArgumentParser(description=description)
    parser.add_argument('template', metavar='TEMPLATE',
                        help='template name to deploy.')
    parser.add_argument('path', metavar='PATH',
                        help='Path to deploy.')
    parser.add_argument('--force', action='store_true', 
                        help='Force to deploy template.')
    parser.add_argument('--debug', action='store_true',
                        help='Debug this script.')

    args = parser.parse_args()

    # Logging
    logging.basicConfig(level=logging.INFO, format='[%(levelname)s] %(message)s')
    logging.addLevelName(logging.INFO,    "\033[1;36m*\033[1;0m")
    logging.addLevelName(logging.WARNING, "\033[1;33m!\033[1;0m")
    logging.addLevelName(logging.ERROR,   "\033[1;31m-\033[1;0m")

    # Check
    pd = os.path.dirname(args.path)
    if not os.path.isdir(pd):
        logging.error("Invalid path: %s", args.path)

    if os.path.isfile(args.path):
        if not args.force:
            logging.error("File exists: %s (use --force?)", args.path)
            exit(-1)
        else:
            os.remove(args.path)

    elif os.path.isdir(args.path):
        if not args.force:
            logging.error("Directory exists: %s (use --force?)", args.path)
            exit(-1)
        else:
            shutil.rmtree(args.path)

    os.mkdir(args.path, 0777)

    # Action
    if not args.debug:
        try:
            err = deploy(args.template, args.path)
        except Exception as e:
            logging.error("Unexpected error: %s", e.message)
            shutil.rmtree(args.path)
            err = -1
    else:
        err = deploy(args.template, args.path)

    exit(err)