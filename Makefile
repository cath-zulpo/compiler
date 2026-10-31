# -------------------------------------------------------------------
#            Arquivo: Makefile
# -------------------------------------------------------------------
#              Autor: Bruno Müller Junior
#               Data: 08/2007
#      Atualizado em: [09/08/2020, 19h:01m]
#
# -------------------------------------------------------------------

all: compiladores

compiladores: lex.yy.c compilador.tab.c compilador.h
	gcc lex.yy.c compilador.tab.c -o compilador -ll -ly -lc -g -W -Wall -Wunused

lex.yy.c: compilador.l compilador.h
	flex compilador.l

compilador.tab.c: compilador.y compilador.h
	bison compilador.y -d -v

# --- Dynamic Tests Configuration ---
TEST_DIR = tests

test_all: compiladores
	@echo "Running all tests in $(TEST_DIR)/..."
	@for file in $(TEST_DIR)/*.pas; do \
		base=$$(basename $$file .pas); \
		echo "\n========================================"; \
		echo "Testing: $$base.pas"; \
		echo "========================================"; \
		./compilador $$file; \
		cat $$file; \
		if [ -f "$(TEST_DIR)/MEPA.$${base#teste}" ] && [ "$${base#teste}" != "$$base" ]; then \
			diff -wy MEPA $(TEST_DIR)/MEPA.$${base#teste} || true; \
		elif [ -f "$(TEST_DIR)/$$base.mepa" ]; then \
			diff -wy MEPA $(TEST_DIR)/$$base.mepa || true; \
		else \
			echo "Warning: No expected MEPA output file found for $$base.pas"; \
		fi; \
	done

clean:
	rm -f compilador.tab.* lex.yy.c compilador.o compilador compilador.output MEPA
