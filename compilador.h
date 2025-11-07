/* -------------------------------------------------------------------
 *            Arquivo: compilador.h
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
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

#define TOKEN_SIZE 16
#define STACK_SIZE 128
#define LABEL_SIZE 4
#define MAX_PARAM 16
#define MAX_VARS 32

typedef enum symbols {
  symb_program, symb_var, symb_begin, symb_end,
  symb_procedure, symb_function, symb_read, symb_write,
  symb_input, symb_output, symb_identifier, symb_number,
  symb_int, symb_bool, symb_true, symb_false,
  symb_period, symb_comma, symb_semicolon, symb_colon,
  symb_assignment, symb_open_parenthesis, symb_close_parenthesis,
  symb_plus, symb_minus, symb_asterisk, symb_slash,
  symb_equal, symb_different, symb_less, symb_greater, symb_less_equal,
  symb_greater_equal, symb_and, symb_or, symb_not, symb_div,
  symb_while, symb_do, symb_if, symb_then, symb_else
} symbols;

enum category {
	variable, parameter, procedure, function
};

enum type {
	integer, real, character, boolean
};

struct variable {
	enum type type;
	int shift;
};

struct parameter {
	enum type type;
	int shift;
	bool ref;
};

struct procedure {
	char label[LABEL_SIZE];
	int argNum;
	enum type argsType[MAX_PARAM];
	bool argsRef[MAX_PARAM];
};

struct function {
	enum type type;
	int shift;
	char label[LABEL_SIZE];
	int argNum;
	enum type argsType[MAX_PARAM];
	bool argsRef[MAX_PARAM];
};

struct symbolTableNode {
	char ident[TOKEN_SIZE+1];
	enum category category;
	int lexLevel;
	void* data;
};

struct symbolTable {
	int top;
	struct symbolTableNode st[STACK_SIZE];
};

struct typeStack {
	int top;
	enum type ts[STACK_SIZE];
};

struct labelStack {
	int top;
	char ls[STACK_SIZE][LABEL_SIZE+1];
};

/* -------------------------------------------------------------------
 * variáveis globais
 * ------------------------------------------------------------------- */

extern symbols symbol, relation;
extern char token[];
extern char lastIdent[];
extern int lexLevel;
extern int shift;
extern int nl;
extern char declaredVars[][TOKEN_SIZE+1];
extern struct symbolTable symbolTable;

/* -------------------------------------------------------------------
 * prototipos globais
 * ------------------------------------------------------------------- */

struct symbolTableNode*  insert(char* , enum category, ...);
struct symbolTableNode* search(char* );
void remov(int );
void print();

void pushType(struct typeStack*, enum type);
enum type popType(struct typeStack*);
void printStack(struct typeStack*);

enum type strToType(char*);

int newLabel();
int popLabel();

int printError(char*, int);
void generateCode(int, char*, ...);
int yylex();
void yyerror(const char* s);
