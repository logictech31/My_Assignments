#ifndef _yy_defines_h_
#define _yy_defines_h_

#define SIN 257
#define COS 258
#define TAN 259
#define NAME 260
#define NUMBER 261
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
  char *fchar;
  double fval;
  int intval;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
