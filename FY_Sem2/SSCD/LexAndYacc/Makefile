FLEX_SRC := compound.l
YACC_SRC := compound.y
C_SRC := lex.yy.c compound.tab.c
BINARY_NAME := compiler

all: $(BINARY_NAME)

$(BINARY_NAME): $(C_SRC)
	gcc -o $(BINARY_NAME) $(C_SRC)

$(C_SRC): $(FLEX_SRC) $(YACC_SRC)
	flex $(FLEX_SRC)
	bison -d $(YACC_SRC)

clean:
	rm -f $(BINARY_NAME) *.tab.* *.yy.c

.PHONY: all clean
