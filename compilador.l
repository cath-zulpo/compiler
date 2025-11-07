
/* -------------------------------------------------------------------
 *            Arquivo: compilador.l
 * -------------------------------------------------------------------
 *              Autor: Bruno Muller Junior
 *               Data: 08/2007
 *      Atualizado em: [09/08/2020, 19h:01m]
 *
 * -------------------------------------------------------------------
 *
 * Tipos, protótipos e variáveis globais do compilador (via extern)
 *
 * ------------------------------------------------------------------- */

%{
#include "compilador.h"
#include "compilador.tab.h"

//#define PRINT(STR) {};
#define PRINT(STR) printf("%s    # %s \n", STR, token);

int nl = 1;

%}

%option nounput
%option noinput

new_line [\n]

discard [\t ]+

ident [a-zA-Z][a-zA-Z0-9]*

number [0-9]+

comment "(*".*"*)"

%%

{new_line} {nl++;}

{discard}

{comment}

program { symbol  = symb_program;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT("program ");
          return PROGRAM;
		}

var     { symbol = symb_var;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT("var  ");
          return VAR;
		}

procedure { symbol = symb_procedure;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT("procedure  ");
          return PROCEDURE;
		  }

function { symbol = symb_function;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT("function  ");
          return FUNCTION;
		 }

begin   { symbol = symb_begin;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT("begin ");
          return T_BEGIN;
		}

end     { symbol = symb_end;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT("end  ");
          return T_END;
		}

true    { symbol = symb_true;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" true  ");
          return TRUE;
		}

false   { symbol = symb_false;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" false  ");
          return FALSE;
		}

read    { symbol = symb_read;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" read  ");
          return READ;
		}

readln  { symbol = symb_read;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" readln  ");
          return READ;
		}

write   { symbol = symb_write;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" write  ");
          return WRITE;
		}

writeln { symbol = symb_write;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" writeln  ");
          return WRITE;
		}

and     { symbol = symb_and;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" and  ");
          return '&';
        }

or      { symbol = symb_or;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" or  ");
          return '|';
        }

not     { symbol = symb_not;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" not  ");
          return '!';
        }

div     { symbol = symb_div;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" div  ");
          return DIV;
        }

while	{ symbol = symb_while;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" while  ");
          return WHILE;
        }

do		{ symbol = symb_do;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" do  ");
          return DO;
        }

if		{ symbol = symb_if;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" if  ");
          return IF;
        }

then	{ symbol = symb_then;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" then  ");
          return THEN;
        }

else	{ symbol = symb_else;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" else  ");
          return ELSE;
        }

:=      { symbol = symb_assignment;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" assignment  ");
          return ASSIGNMENT;
 }

\;      { symbol = symb_semicolon;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" semicolon  ");
          return ';';
		}

\:      { symbol = symb_colon;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" colon ");
          return ':';
		}

\,      { symbol = symb_comma;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" comma  ");
          return ',';
		}

\.      { symbol = symb_period;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" period  ");
          return '.';
		}

\(      { symbol = symb_open_parenthesis;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" open_parenthesis  ");
          return '(';
		}

\)      { symbol = symb_close_parenthesis;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" close_parenthesis ");
          return ')';
		}

{ident} { symbol = symb_identifier;
          strncpy (token, yytext, TOKEN_SIZE);
          strncpy (lastIdent, yytext, TOKEN_SIZE);
          PRINT(" ident  ");
          return IDENT;
        }

{number} { symbol = symb_number;
           strncpy (token, yytext, TOKEN_SIZE);
           PRINT(" number  ");
           return NUM;
         }

\+      { symbol = symb_plus;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" plus  ");
          return '+';
        }

-       { symbol = symb_minus;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" minus  ");
          return '-';
        }

\*      { symbol = symb_asterisk;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" asterisk  ");
          return '*';
        }

\/      { symbol = symb_slash;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" slash  ");
          return '/';
        }

=       { symbol = symb_equal;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" equal  ");
          return '=';
        }

\<>     { symbol = symb_different;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" different  ");
          return DIFFERENT;
        }

\<      { symbol = symb_less;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" less  ");
          return '<';
        }

>       { symbol = symb_greater;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" greater  ");
          return '>';
        }

\<=     { symbol = symb_less_equal;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" less or equal  ");
          return LESS_EQUAL;
        }

>=      { symbol = symb_greater_equal;
          strncpy (token, yytext, TOKEN_SIZE);
          PRINT(" greater or equal  ");
          return GREATER_EQUAL;
        }

%%
