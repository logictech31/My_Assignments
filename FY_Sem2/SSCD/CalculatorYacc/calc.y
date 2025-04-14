%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int yylex();
void yyerror(const char *s);
%}

%union {
  char *fchar;
  double fval;
  int intval;
}

%token SIN COS TAN
%token <fchar> NAME
%token <intval> NUMBER
%type <fval> exp
%left '+' '-'
%left '*' '/'
%left '^'

%%
stmt:
    NAME '=' exp { printf("stmt: %s = %f\n", $1, $3); free($1); }
    | exp { printf("exp = %f\n", $1); }
    ;

exp:
    exp '+' exp { $$ = $1 + $3; }
    | exp '-' exp { $$ = $1 - $3; }
    | exp '*' exp { $$ = $1 * $3; }
    | exp '/' exp {
        if ($3 == 0) {
            yyerror("Division by zero");
            $$ = 0;
        } else {
            $$ = $1 / $3;
        }
    }
    | SIN '(' exp ')' { $$ = sin($3 * M_PI / 180); }
    | COS '(' exp ')' { $$ = cos($3 * M_PI / 180); }
    | TAN '(' exp ')' { $$ = tan($3 * M_PI / 180); }
    | NUMBER { $$ = $1; }
    | '(' exp ')' { $$ = $2; }
    ;
%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter expressions:\n");
    yyparse();
    return 0;
}
