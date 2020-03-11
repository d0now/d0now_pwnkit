#
# Makefile
#

ARCH 	= x86
CC      = gcc
CFLAGS  = -w -fno-stack-protector -nostdlib -nostartfiles -nostdinc -fPIC
LFLAGS  = -w -fno-stack-protector -nostdlib -nostartfiles -nostdinc -fPIC -shared
INC_DIR = include
SRC_DIR = source

ARCH_OBJS = $(SRC_DIR)/arch/$(ARCH)/internal.o

OBJS  = $(SRC_DIR)/syscall_common.o
OBJS += $(SRC_DIR)/syscall_vfs.o
OBJS += $(SRC_DIR)/util_common.o
OBJS += $(ARCH_OBJS)

TARGET = libtiny.so

ifeq ($(ARCH), x86)
	CFLAGS += -m32
	LFLAGS += -m32
endif

libc: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LFLAGS) -I$(INC_DIR) -I$(INC_DIR)/dummy -o $(TARGET) $(OBJS)

$(OBJS):
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(INC_DIR)/dummy -c $*.c -o $@

clean:
	rm -f $(SRC_DIR)/*.o
	rm -f $(SRC_DIR)/arch/x86/*.o