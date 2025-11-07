 # -------------------------------------------------------------------
 #            Arquivo: Makefile
 # -------------------------------------------------------------------
 #              Autor: Bruno Müller Junior
 #               Data: 08/2007
 #      Atualizado em: [09/08/2020, 19h:01m]
 #
 # -------------------------------------------------------------------

$DEPURA=1

all: compiladores

compiladores: lex.yy.c compilador.tab.c compilador.h
	gcc lex.yy.c compilador.tab.c -o compilador -ll -ly -lc -g -W -Wall -Wunused

lex.yy.c: compilador.l compilador.h
	flex compilador.l

compilador.tab.c: compilador.y compilador.h
	bison compilador.y -d -v

test_1: compiladores
	./compilador teste1.pas
	cat teste1.pas
	diff -wy MEPA MEPA.1 || true

test_2: compiladores
	./compilador teste2.pas
	cat teste2.pas
	diff -wy MEPA MEPA.2 || true

test_3: compiladores
	./compilador teste3.pas
	cat teste3.pas
	diff -wy MEPA MEPA.3 || true

test_4: compiladores
	./compilador teste4.pas
	cat teste4.pas
	diff -wy MEPA MEPA.4 || true

test_5: compiladores
	./compilador teste5.pas
	cat teste5.pas
	diff -wy MEPA MEPA.5 || true

test_6: compiladores
	./compilador teste6.pas
	cat teste6.pas
	diff -wy MEPA MEPA.6 || true

test_7: compiladores
	./compilador teste7.pas
	cat teste7.pas
	diff -wy MEPA MEPA.7 || true

test_8: compiladores
	./compilador teste8.pas
	cat teste8.pas
	diff -wy MEPA MEPA.8 || true

test_while: compiladores
	./compilador aula8.pas
	cat aula8.pas
	diff -wy MEPA aula8.mepa || true

test_if: compiladores
	./compilador aula9.pas
	cat aula9.pas
	diff -wy MEPA aula9.mepa || true

test_procedure: compiladores
	./compilador aula10.pas
	cat aula10.pas
	diff -wy MEPA aula10.mepa || true

test_value: compiladores
	./compilador aula11.pas
	cat aula11.pas
	diff -wy MEPA aula11.mepa || true

test_reference: compiladores
	./compilador aula12.pas
	cat aula12.pas
	diff -wy MEPA aula12.mepa || true

test_function: compiladores
	./compilador aula13.pas
	cat aula13.pas
	diff -wy MEPA aula13.mepa || true

clean:
	rm -f compilador.tab.* lex.yy.c compilador.o compilador compilador.output
