// Testar se funciona corretamente o empilhamento de parâmetros
// passados por valor ou por referência.

%{
#include "compilador.h"

#define DEBUG 0
#define COMMENTS 0
#define YYDEBUG 0
#define VAR(var) #var

int varCount, varTotal[STACK_SIZE], argCount, lastArgCount;
int labelCount = -1;
int lexLevel = -1;
int shift;

struct symbolTable symbolTable = {.top = -1};
struct symbolTableNode* lastSym[STACK_SIZE];
struct symbolTableNode* lastCall;
symbols symbol, relation;

char definedVars[MAX_VARS][TOKEN_SIZE+1];
char definedArgs[MAX_VARS][TOKEN_SIZE+1];
char lastSubroutine[TOKEN_SIZE+1];
char token[TOKEN_SIZE+1], lastIdent[TOKEN_SIZE+1];

char* catToStr[] = {"variable", "parameter", "procedure"};
char* typeToStr[] = {"integer", "real", "character", "boolean"};

int assignmentShift, varLexLevel;
enum category assignmentCategory;
bool assignmentRef;

enum type lElem;
struct typeStack ts1 = {.top = -1}, ts2 = {.top = -1}, ts3 = {.top = -1}, ts4 = {.top = -1};

struct labelStack ls = {.top = -1};
char nLabel[STACK_SIZE][LABEL_SIZE+1];
int lIndex = -1;

int mIndex = -1;
bool ref, minus[STACK_SIZE] = { [0 ... STACK_SIZE-1] = false};

enum type argsType[MAX_PARAM];
bool argsRef[MAX_PARAM];

%}

%token PROGRAM VAR PROCEDURE FUNCTION
%token '(' ')' ',' ':' ';' '.'
%token T_BEGIN T_END
%token READ WRITE IDENT NUM DIV
%token TRUE FALSE
%token ASSIGNMENT '+' '-' '*' '/'
%token '=' DIFFERENT '<' '>' LESS_EQUAL
%token GREATER_EQUAL '&' '|' '!'
%token WHILE DO IF THEN ELSE

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

program		: { generateCode(-1, "INPP"); }
			  PROGRAM IDENT main_args ';'
			  { ++lexLevel; } block '.'
			  { --lexLevel;
			    generateCode(-1, "PARA");
				#if DEBUG == 2
				printStack(&ts1);
				printStack(&ts2);
				printStack(&ts3);
				printStack(&ts4);
				#endif
			  }
;

main_args	: '(' main_idents ')'
			|
;

main_idents		: main_idents ',' IDENT
				| IDENT
;

block	   	: var
			  sub_routines
			  composite_command { if(varTotal[lexLevel] > 0)
									  generateCode(-1, "DMEM", varTotal[lexLevel]); }
;

var			: VAR { varTotal[lexLevel] = 0; shift = 0; }
				declare_vars { generateCode(-1, "AMEM", varTotal[lexLevel]); }
			|
;

declare_vars	: declare_vars declare_var
				| declare_var
;

declare_var 	: { varCount = 0; } list_id_var ':' IDENT
				  { varTotal[lexLevel] += varCount;
					enum type type = strToType(lastIdent);
					for(int i = 0; i < varCount; ++i, ++shift)
						insert(definedVars[i], variable, type, shift); }
				  ';'
;

list_id_var		: list_id_var ',' IDENT { strncpy(definedVars[varCount], lastIdent, TOKEN_SIZE); ++varCount; }
				| IDENT { strncpy(definedVars[varCount], lastIdent, TOKEN_SIZE); ++varCount; }
;

sub_routines	: sub_routines sub_routine
				|
;

sub_routine		: procedure
				| function
;

procedure		: PROCEDURE IDENT { strncpy(lastSubroutine, lastIdent, TOKEN_SIZE); argCount = 0; } args ';'
								  { generateCode(-1, "DSVS", newLabel());
									#if COMMENTS == 1
									generateCode(-1, "//", lastSubroutine);
									#endif
									generateCode(newLabel(), "ENPR", lexLevel+1);
									lastSym[lexLevel] = insert(lastSubroutine, procedure, popLabel());
									++lexLevel; }
				 				block ';'
								  { --lexLevel;
									generateCode(-1, "RTPR", lexLevel+1, ((struct procedure*)lastSym[lexLevel]->data)->argNum);
									#if COMMENTS == 1
									generateCode(-1, "//end", lastSym[lexLevel]->ident);
									#endif
									generateCode(popLabel(), "NADA"); }
;

function		: FUNCTION IDENT { strncpy(lastSubroutine, lastIdent, TOKEN_SIZE); argCount = 0; } args ':' IDENT ';'
								 { generateCode(-1, "DSVS", newLabel());
								   #if COMMENTS == 1
								   generateCode(-1, "//", lastSubroutine);
								   #endif
								   generateCode(newLabel(), "ENPR", lexLevel+1);
								   lastSym[lexLevel] = insert(lastSubroutine, function, popLabel(), strToType(lastIdent), -argCount-4);
								   ++lexLevel; }
		  						block ';'
								 { --lexLevel;
								   generateCode(-1, "RTPR", lexLevel+1, ((struct function*)lastSym[lexLevel]->data)->argNum);
								   #if COMMENTS == 1
								   generateCode(-1, "//end", lastSym[lexLevel]->ident);
								   #endif
								   generateCode(popLabel(), "NADA"); }
;

args			: '(' { argCount = 0; lastArgCount = 0; } list_args ')'
	   				  { for(int i = 0, shift = 0; i < argCount; ++i, ++shift)
							//printf("\t%s %s %d %s\n", definedArgs[i], typeToStr[argsType[argCount]], shift-argCount-3, argsRef[argCount]?"reference":"value"),
							insert(definedArgs[i], parameter, argsType[i], shift-argCount-3, argsRef[i]); }
				|
;

list_args		: ref list_idents ':' IDENT { enum type type = strToType(lastIdent);
											  for(int i = lastArgCount; i < argCount; ++i) {
												  argsType[i] = type;
												  argsRef[i] = ref;
											  }
											  lastArgCount = argCount; } ';' list_args
				| ref list_idents ':' IDENT { enum type type = strToType(lastIdent);
											  for(int i = lastArgCount; i < argCount; ++i) {
												  argsType[i] = type;
												  argsRef[i] = ref;
											  }
											  lastArgCount = argCount; }
;

list_idents		: list_idents ',' IDENT { strncpy(definedArgs[argCount], lastIdent, TOKEN_SIZE); ++argCount; }
				| IDENT { strncpy(definedArgs[argCount], lastIdent, TOKEN_SIZE); ++argCount; }
;

ref				: VAR { ref = true; /*printf("\treference\n");*/ }
				| { ref = false; /*printf("\tvalue\n");*/ }
;

composite_command: T_BEGIN {
						#if DEBUG == 1
						print();
						#endif
					} commands T_END

commands		: command ';' commands
				| command who_cares
;

who_cares		: ';'
				|
;

command			: assignment
				| read
				| write
				| while
				| if
				| procedure_call
;

assignment		: IDENT { struct symbolTableNode* sym = search(lastIdent);
						  if(sym == NULL)
							  printError("symbol not found", __LINE__);
						  varLexLevel = sym->lexLevel;
						  assignmentShift = ((struct variable*)sym->data)->shift;
						  lElem = ((struct variable*)sym->data)->type;
						  assignmentCategory = sym->category;
						  if(sym->category == parameter && ((struct parameter*)sym->data)->ref) {
							  assignmentRef = ((struct parameter*)sym->data)->ref;
						  } else {
							  assignmentRef = false;
						  } } ASSIGNMENT expression
						{ enum type t = popType(&ts1);
						  #if DEBUG == 2
						  printf("\t%d %d ", lElem, t);
						  printf("%s %s\n", typeToStr[lElem], typeToStr[t]);
						  #endif
						  if(lElem == t) {
							  if(assignmentCategory == function)
								  generateCode(-1, "ARMZ", varLexLevel+1, assignmentShift);
							  else if(assignmentCategory == parameter && assignmentRef)
								  generateCode(-1, "ARMI", varLexLevel, assignmentShift);
							  else
								  generateCode(-1, "ARMZ", varLexLevel, assignmentShift);
						  } else
							  printError("wrong type", __LINE__); }
;

read			: READ '(' list_args_read ')'
;

list_args_read	: IDENT { struct symbolTableNode* sym = search(lastIdent);
						  if(sym == NULL)
							  printError("variable not found", __LINE__);
						  struct variable* var = sym->data;
						  generateCode(-1, "LEIT");
						  if(sym->category == function)
							  generateCode(-1, "ARMZ", sym->lexLevel+1, var->shift);
						  else if(sym->category == parameter && ((struct parameter*)sym->data)->ref)
							  generateCode(-1, "ARMI", sym->lexLevel, var->shift);
						  else
							  generateCode(-1, "ARMZ", sym->lexLevel, var->shift); } ',' list_args_read
				| IDENT { struct symbolTableNode* sym = search(lastIdent);
						  if(sym == NULL)
							  printError("variable not found", __LINE__);
						  struct variable* var = sym->data;
						  generateCode(-1, "LEIT");
						  if(sym->category == function)
							  generateCode(-1, "ARMZ", sym->lexLevel+1, var->shift);
						  else if(sym->category == parameter && ((struct parameter*)sym->data)->ref)
							  generateCode(-1, "ARMI", sym->lexLevel, var->shift);
						  else
							  generateCode(-1, "ARMZ", sym->lexLevel, var->shift); }
;

write			: WRITE '(' list_args_write ')'
;

list_args_write	: list_args_write ',' expression { popType(&ts1); generateCode(-1, "IMPR"); }
				| expression { popType(&ts1); generateCode(-1, "IMPR"); }
;

while			: WHILE { 
						  #if COMMENTS == 1
						  generateCode(-1, "//", "while");
						  #endif
						  generateCode(newLabel(), "NADA"); } expression { if(popType(&ts1) != boolean) printError("wrong type", __LINE__); generateCode(-1, "DSVF", newLabel()); } DO
					nested_commands
				{ int label = popLabel();
				  #if COMMENTS == 1
				  generateCode(-1, "//", "end while");
				  #endif
				  generateCode(-1, "DSVS", popLabel());
				  generateCode(label, "NADA"); }
;

if				: if_then else { --lIndex;
								 #if COMMENTS == 1
								 generateCode(-1, "//", "end if");
								 #endif
							   }
;

if_then			: IF {
					   #if COMMENTS == 1
					   generateCode(-1, "//", "if");
					   #endif
					 } expression { if(popType(&ts1) != boolean) printError("wrong type", __LINE__); generateCode(-1, "DSVF", newLabel()); } THEN
					  nested_commands { generateCode(-1, "DSVS", newLabel()); strncpy(nLabel[++lIndex], ls.ls[popLabel()], LABEL_SIZE); generateCode(popLabel(), "NADA"); }
;

else			: ELSE {
						 #if COMMENTS == 1
	   					 generateCode(-1, "//", "else");
						 #endif
					   }
					  nested_commands { generateCode(-2, "NADA"); }
				| %prec LOWER_THAN_ELSE
;

nested_commands	: T_BEGIN commands T_END
				| command
;

procedure_call	: IDENT { lastCall = search(lastIdent);
						  if(lastCall == NULL)
							  printError("symbol not found", __LINE__); }
					  exp_args
						{ if(argCount != ((struct procedure*)lastCall->data)->argNum)
							  printError("wrong number of arguments", __LINE__);
						  generateCode(-1, "CHPR", ((struct procedure*)lastCall->data)->label, lexLevel); }
;

exp_args	: '(' { argCount = 0; } expression_list ')'
			|
;

expression_list : expression { if(lastCall->category == procedure) {
								   if(((struct procedure*)lastCall->data)->argsType[argCount] != popType(&ts1)) printError("wrong type", __LINE__); ++argCount;
							   } else {
								   if(((struct function*)lastCall->data)->argsType[argCount] != popType(&ts1)) printError("wrong type", __LINE__); ++argCount;
							   } } ',' expression_list
				| expression { if(lastCall->category == procedure) {
								   if(((struct procedure*)lastCall->data)->argsType[argCount] != popType(&ts1)) printError("wrong type", __LINE__); ++argCount;
							   } else {
								   if(((struct function*)lastCall->data)->argsType[argCount] != popType(&ts1)) printError("wrong type", __LINE__); ++argCount;
							   } }
;

expression		: simple_expression '=' simple_expression			{ if(popType(&ts2) != popType(&ts2)) printError("wrong type", __LINE__); pushType(&ts1, boolean); generateCode(-1, "CMIG"); }
				| simple_expression DIFFERENT simple_expression		{ if(popType(&ts2) != popType(&ts2)) printError("wrong type", __LINE__); pushType(&ts1, boolean); generateCode(-1, "CMDG"); }
				| simple_expression '<' simple_expression			{ if(popType(&ts2) != popType(&ts2)) printError("wrong type", __LINE__); pushType(&ts1, boolean); generateCode(-1, "CMME"); }
				| simple_expression '>' simple_expression			{ if(popType(&ts2) != popType(&ts2)) printError("wrong type", __LINE__); pushType(&ts1, boolean); generateCode(-1, "CMMA"); }
				| simple_expression LESS_EQUAL simple_expression	{ if(popType(&ts2) != popType(&ts2)) printError("wrong type", __LINE__); pushType(&ts1, boolean); generateCode(-1, "CMEG"); }
				| simple_expression GREATER_EQUAL simple_expression { if(popType(&ts2) != popType(&ts2)) printError("wrong type", __LINE__); pushType(&ts1, boolean); generateCode(-1, "CMAG"); }
				| simple_expression									{ pushType(&ts1, popType(&ts2)); }
;

simple_expression	: simple_expression '+' term { if(popType(&ts2) != popType(&ts3)) printError("wrong type", __LINE__); pushType(&ts2, integer); generateCode(-1, "SOMA"); }
					| simple_expression '-' term { if(popType(&ts2) != popType(&ts3)) printError("wrong type", __LINE__); pushType(&ts2, integer); generateCode(-1, "SUBT"); }
					| simple_expression '|' term { if(popType(&ts2) != popType(&ts3)) printError("wrong type", __LINE__); pushType(&ts2, boolean); generateCode(-1, "DISJ"); }
					| term						 { pushType(&ts2, popType(&ts3)); }
;

term			: term '*' factor	{ if(popType(&ts3) != popType(&ts4)) printError("wrong type", __LINE__); pushType(&ts3, integer); generateCode(-1, "MULT"); }
				| term DIV factor	{ if(popType(&ts3) != popType(&ts4)) printError("wrong type", __LINE__); pushType(&ts3, integer); generateCode(-1, "DIVI"); }
				| term '&' factor	{ if(popType(&ts3) != popType(&ts4)) printError("wrong type", __LINE__); pushType(&ts3, boolean); generateCode(-1, "CONJ"); }
				| factor			{ pushType(&ts3, popType(&ts4)); }
;

factor			: '!' factor { if(popType(&ts4) != boolean) printError("wrong type", __LINE__); pushType(&ts4, boolean); generateCode(-1, "NEGA"); }
				| sign factor { if(popType(&ts4) != integer) printError("wrong type", __LINE__); pushType(&ts4, integer);
								if(minus[mIndex]) { generateCode(-1, "INVR"); minus[mIndex] = false; } --mIndex; }
				| IDENT { struct symbolTableNode* sym = search(lastIdent);
						  if(sym == NULL)
							  printError("symbol not found", __LINE__);
						  if(sym->category == function) {
							  generateCode(-1, "AMEM", 1);
			 				  lastCall = search(lastIdent);
							  if(lastCall == NULL)
								  printError("symbol not found", __LINE__);
							  pushType(&ts4, ((struct function*)lastCall->data)->type);
							  generateCode(-1, "CHPR", ((struct function*)lastCall->data)->label, lexLevel);
						  }
						  else if(sym->category == parameter && ((struct parameter*)sym->data)->ref) {
							  if(lastCall && lastCall->category == procedure && ((struct procedure*)lastCall->data)->argsRef[argCount])
								  generateCode(-1, "CRVL", sym->lexLevel, ((struct variable*)sym->data)->shift);
							  else if(lastCall && lastCall->category == function && ((struct function*)lastCall->data)->argsRef[argCount])
								  generateCode(-1, "CRVL", sym->lexLevel, ((struct variable*)sym->data)->shift);
							  else
								  generateCode(-1, "CRVI", sym->lexLevel, ((struct variable*)sym->data)->shift);
						  } else {
							  if(lastCall && lastCall->category == procedure && ((struct procedure*)lastCall->data)->argsRef[argCount])
								  generateCode(-1, "CREN", sym->lexLevel, ((struct variable*)sym->data)->shift);
							  else if(lastCall && lastCall->category == function && ((struct function*)lastCall->data)->argsRef[argCount])
								  generateCode(-1, "CREN", sym->lexLevel, ((struct variable*)sym->data)->shift);
							  else
								  generateCode(-1, "CRVL", sym->lexLevel, ((struct variable*)sym->data)->shift);
						  }
						  if(sym->category == variable)
							  pushType(&ts4, ((struct variable*)sym->data)->type);
						  else if(sym->category == parameter)
							  pushType(&ts4, ((struct parameter*)sym->data)->type);
						  else if(sym->category == function)
							  pushType(&ts4, ((struct function*)sym->data)->type); }
				| NUM { generateCode(-1, "CRCT", token); pushType(&ts4, integer); }
				| TRUE	{ generateCode(-1, "CRCT", "1"); pushType(&ts4, boolean); }
				| FALSE { generateCode(-1, "CRCT", "0"); pushType(&ts4, boolean); }
				| '(' expression ')' { pushType(&ts4, popType(&ts1)); }
				| IDENT { generateCode(-1, "AMEM", 1);
			 				   lastCall = search(lastIdent);
							   if(lastCall == NULL)
								   printError("symbol not found", __LINE__);
							   pushType(&ts4, ((struct function*)lastCall->data)->type); }
						'(' { argCount = 0; } expression_list ')'
							 { if(argCount != ((struct function*)lastCall->data)->argNum)
								   printError("wrong number of arguments", __LINE__);
							   generateCode(-1, "CHPR", ((struct function*)lastCall->data)->label, lexLevel); }
;

sign			: '+'
				| '-' { minus[++mIndex] = true; }
;

%%

FILE* fp = NULL;
void generateCode(int label, char* command, ...) {
	va_list ap;

	va_start(ap, command);

	if(fp == NULL)
		fp = fopen ("MEPA", "w");

	if(label >= 0)
		fprintf(fp, "%s:", ls.ls[label]);
	else if(label == -2)
		fprintf(fp, "%s:", nLabel[lIndex]);
	else
		fprintf(fp, "    ");

	if(strcasecmp(command, "CRCT") == 0) {
		fprintf(fp, "%s %s\n", command, va_arg(ap, char*));
	} else if(strcasecmp(command, "DSVS") == 0 || strcasecmp(command, "DSVF") == 0) {
		fprintf(fp, "%s %s\n", command, ls.ls[va_arg(ap, int)]);
	} else if(strcasecmp(command, "AMEM") == 0 || strcasecmp(command, "DMEM") == 0 || strcasecmp(command, "ENPR") == 0) {
		fprintf(fp, "%s %d\n", command, va_arg(ap, int));
	} else if(strcasecmp(command, "ARMZ") == 0 || strcasecmp(command, "ARMI") == 0 || strcasecmp(command, "CRVL") == 0 ||
			  strcasecmp(command, "CRVI") == 0 || strcasecmp(command, "CREN") == 0 || strcasecmp(command, "RTPR") == 0) {
		int lex = va_arg(ap, int);
		fprintf(fp, "%s %d, %d\n", command, lex, va_arg(ap, int));
	} else if(strcasecmp(command, "CHPR") == 0) {
		char* label = va_arg(ap, char*);
		fprintf(fp, "%s %s, %d\n", command, label, va_arg(ap, int));
	} else if(strncmp(command, "//", 2) == 0) {
		fprintf(fp, "%s %s\n", command, va_arg(ap, char*));
	} else {
		fprintf(fp, "%s\n", command);
	}
	fflush(fp);
	va_end(ap);
}

int printError(char* error, int line) {
	printf("compilador.y line %d \u2551 Error in line %d - %s\n", line, nl, error);
	exit(-1);
}

struct symbolTableNode* insert(char* ident, enum category category, ...) {
	++symbolTable.top;
	struct symbolTableNode* node = &symbolTable.st[symbolTable.top];
	strncpy(node->ident,ident,TOKEN_SIZE);
	node->category = category;
	node->lexLevel = lexLevel;

	#if DEBUG == 1
	printf("inserting: %s\n", ident);
	#endif

	va_list ap;
	va_start(ap, category);

	switch(category) {
		case variable:
			node->data = malloc(sizeof(struct variable));
			struct variable* var = node->data;
			var->type = va_arg(ap, enum type);
			var->shift = va_arg(ap, int);
			break;

		case parameter:
			++node->lexLevel;
			node->data = malloc(sizeof(struct parameter));
			struct parameter* par = node->data;
			par->type = va_arg(ap, enum type);
			par->shift = va_arg(ap, int);
			par->ref = va_arg(ap, int);
			break;

		case procedure:
			node->data = malloc(sizeof(struct procedure));
			struct procedure* proc = node->data;
			strncpy(proc->label, ls.ls[va_arg(ap, int)], LABEL_SIZE);
			proc->argNum = argCount;
			for(int i = 0; i < proc->argNum; ++i) {
				proc->argsType[i] = argsType[i];
				proc->argsRef[i] = argsRef[i];
			}
			break;

		case function:
			node->data = malloc(sizeof(struct function));
			struct function* func = node->data;
			strncpy(func->label, ls.ls[va_arg(ap, int)], LABEL_SIZE);
			func->argNum = argCount;
			for(int i = 0; i < func->argNum; ++i) {
				func->argsType[i] = argsType[i];
				func->argsRef[i] = argsRef[i];
			}
			func->type = va_arg(ap, enum type);
			func->shift = va_arg(ap, int);
			break;
	}
	va_end(ap);
	return node;
}

struct symbolTableNode* search(char* ident) {
	for(int i = symbolTable.top; i >= 0; --i) {
		#if DEBUG == 1
		printf("comparing: %s with %s\n",symbolTable.st[i].ident,ident);
		#endif
		if(strncasecmp(symbolTable.st[i].ident,ident,TOKEN_SIZE) == 0 && symbolTable.st[i].lexLevel <= lexLevel) {
			#if DEBUG == 1
			printf("\tsearch success\n");
			#endif
			return &symbolTable.st[i];
		}
	}
	#if DEBUG == 1
	printf("\tsearch failed\n");
	#endif
	return NULL;
}

void remov(int n) {
	for(int i = 0; i < n; ++i, --symbolTable.top)
		free(symbolTable.st[symbolTable.top].data);
}

void print() {
	printf("print: top == %d\n", symbolTable.top);
	for(int i = symbolTable.top; i >= 0; --i) {
		printf("print: %s %s %d, ", symbolTable.st[i].ident, catToStr[symbolTable.st[i].category], symbolTable.st[i].lexLevel);
		if(symbolTable.st[i].category == variable) {
			struct variable* data = symbolTable.st[i].data;
			printf("%d\n", data->shift);
		} else if(symbolTable.st[i].category == parameter) {
			struct parameter* data = symbolTable.st[i].data;
			printf("%d %s\n", data->shift, data->ref?"reference":"value");
		} else if(symbolTable.st[i].category == procedure) {
			struct procedure* data = symbolTable.st[i].data;
			printf("%s %d\n", data->label, data->argNum);
		}
	}
}

void pushType(struct typeStack* ts, enum type type) {
	++ts->top;
	ts->ts[ts->top] = type;
	#if DEBUG == 2
	printf("%p: pushing %s to postion %d\n", ts, typeToStr[type], ts->top);
	#endif
}

enum type popType(struct typeStack* ts) {
	#if DEBUG == 2
	printf("%p: popping %s on postion %d\n", ts, typeToStr[ts->ts[ts->top]], ts->top);
	#endif
	--ts->top;
	return ts->ts[ts->top+1];
}

void printStack(struct typeStack* ts) {
	printf("print: top == %d\n", ts->top);
	for(int i = ts->top; i >= 0; --i) {
		printf("print: %s\n", typeToStr[ts->ts[i]]);
	}
}

enum type strToType(char* str) {
	if(strncasecmp(str, "integer", TOKEN_SIZE) == 0)
		return integer;
	else if(strncasecmp(str, "real", TOKEN_SIZE) == 0)
		return real;
	else if(strncasecmp(str, "character", TOKEN_SIZE) == 0)
		return character;
	else if(strncasecmp(str, "boolean", TOKEN_SIZE) == 0)
		return boolean;

	printError("strToType: invalid argument\n", __LINE__);
	return integer;
}

int newLabel() {
	++ls.top;
	snprintf(ls.ls[ls.top], LABEL_SIZE, "R%02d", ++labelCount);
	#if DEBUG == 3
	printf("new label: %s\n", ls.ls[ls.top]);
	printf("pushing %s to postion %d\n", ls.ls[ls.top], ls.top);
	#endif
	return ls.top;
}

int popLabel() {
	#if DEBUG == 3
	printf("poping %s on postion %d\n", ls.ls[ls.top], ls.top);
	#endif
	--ls.top;
	return ls.top+1;
}


int main(int argc, char** argv) {
	FILE* fp;
	extern FILE* yyin;

	#if YYDEBUG == 1
	yydebug = 1;
	#endif

	if (argc != 2) {
		 printf("usage: ./compilador <arq.pas>\n");
		 return -1;
	}

	fp = fopen (argv[1], "r");
	if (fp == NULL) {
		printf("usage ./compilador <arq.pas>\n");
		return -1;
	}

	yyin = fp;
	yyparse();

	return 0;
}
