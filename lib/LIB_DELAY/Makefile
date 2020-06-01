PROGRAM = lib_delay.lib
SRC_DIR = ./
INC_DIR = ../../include

CFLAGS = -mmcs51 -I $(SRC_DIR) -I $(INC_DIR)

C_OBJS = $(patsubst %.c,%.rel,$(wildcard $(SRC_DIR)/*.c))

CC = sdcc   # C Compiler
AC = sdas   # Assembler Compiler
LN = sdld   # Linker
HEX_MAKER = packihx # Object-HEX Converter
LIB_MAKER = sdar    # Library Maker

default-target: all

$(C_OBJS): %.rel: %.c
	$(CC) $(CFLAGS) -c $<

$(PROGRAM): $(C_OBJS)
	$(LIB_MAKER) -rc $@ $^

all: $(PROGRAM)
	cp $(PROGRAM) ../

clean:
	$(RM) $(PROGRAM) *.rel *.asm *.lst *.sym

.PHONY: default-target all clean
