SYMTAB:
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, m = 0;

struct symtab {
    char name[200];
    char type[200];
} sym[40];

%}

L [a-zA-Z]+
D [0-9]+
ws [ \t]+
datatype int|float|char|double|real|void|short|long
loop_kw if|for|while|do|switch|case|default|break|continue
id {L}({L}|{D})*
preproc \#include|\#define|\#ifdef|\#ifndef|\#endif|\#undef|\main
%%
{preproc} {printf("This is a Preprocessor statement: %s\n", yytext);}
#define{ws}+{id}{ws}+({L}|{D})* {printf("This is a Preprocessor directive for variable substitution: %s\n", yytext);}
{datatype} {printf("This is a Datatype: %s\n", yytext);}
{loop_kw} {printf("This is a Looping Keyword: %s\n", yytext);}
{id} {printf("This is an Identifier: %s\n", yytext);
    strcpy(sym[m].name, yytext);
    strcpy(sym[m].type, "VARIABLE");
    m++;
}

{id}"["{D}+"]" {printf("This is an Array Declaration with size: %s\n", yytext);
    strcpy(sym[m].name, yytext);
    strcpy(sym[m].type, "ARRAY");
    m++;
}

{id}"[]" {printf("This is an Array Declaration: %s\n", yytext);
    strcpy(sym[m].name, yytext);
    strcpy(sym[m].type, "ARRAY");
    m++;
}

[ \t\n]+ {/* ignore whitespace */}
. {printf("Unknown character: %s\n", yytext);}

%%
int main() {
    yyin = fopen("sample.txt", "r");
    if (!yyin) {
        fprintf(stderr, "Error: Could not open sample.txt\n");
        return 1;
    }

    yylex();
    fclose(yyin);

    for (i = 0; i < m; i++) {
        printf("Name: %s, \t Type: %s \n", sym[i].name, sym[i].type);
    }

    return 0;
}

int yywrap() {
    return 1;
}
