yacc -d calc.y   # Generates y.tab.c and y.tab.h
lex calc.l       # Generates lex.yy.c
gcc -g -o calculator y.tab.c lex.yy.c -lm   # Compiles everything with math library

