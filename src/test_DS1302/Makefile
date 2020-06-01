PROGRAM = main
SRC_DIR = ./
INC_DIR = ../../include
# LIB_DIR = $(shell realpath ../../lib) # not recongized by sdcc in Windows OS
LIB_DIR = d:/C51/sdcc_c51_test/lib

CFLAGS = -mmcs51 -DDEBUG -I $(SRC_DIR) -I $(INC_DIR) -L $(LIB_DIR)

# egrep "^\s*#include\s+\"(lib_.*)\"" *.c | sed 's|#include\s\+"\(.*\)".*|\1|g'
LIB_HEADERS = $(shell grep '^\s*\#include\s\+"\(lib_.*\)"' *.c | sed 's|\#include\s\+"\(.*\)".*|\1|g' )
COMM_LIBS = $(patsubst %.h,%.lib,$(LIB_HEADERS))

C_OBJS = $(patsubst %.c,%.rel,$(wildcard $(SRC_DIR)/*.c))

CC = sdcc   # C Compiler
AC = sdas   # Assembler Compiler
LN = sdld   # Linker
HEX_MAKER = packihx # Object-HEX Converter
LIB_MAKER = sdar    # Library Maker

default-target: all

$(C_OBJS): %.rel: %.c
	$(CC) $(CFLAGS) -c $<

$(PROGRAM).ihx: $(C_OBJS)
	$(CC) $(CFLAGS) $(PROGRAM).rel $(filter-out .//$(PROGRAM).rel,$(C_OBJS)) $(COMM_LIBS)

$(PROGRAM).hex: $(PROGRAM).ihx
	$(HEX_MAKER) $< > $@

all: $(PROGRAM).hex

tst:
	echo $(LIB_HEADERS)
	echo $(COMM_LIBS)

clean:
	$(RM) *.hex *.ihx *.lk *.map *.mem *.rst *.rel *.asm *.lst *.sym

.PHONY: default-target all clean