SRC_L := calc.l
SRC_Y := calc.y
CC := gcc
CFLAGS := -g -o
BINARY_NAME := calculator
SRC_C := y.tab.c lex.yy.c
CLEANUP_GEN := lex.yy.c

build:
	$(CC) $(CFLAGS) $(BINARY_NAME) $(SRC_C)

bison:
	@echo "Compiling YACC..."
	@bison -d $(SRC_Y)

flex:
	@echo "Generating LEX..."
	@flex $(SRC_L)



.DEFAULT_GOAL = build
clean:
	rm -fr $(CLEANUP_GEN)
.PHONY: flex bison all clean
