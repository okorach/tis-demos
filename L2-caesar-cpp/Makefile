SHELL := /bin/bash

FONT_BOLD := `tput bold`
FONT_CYAN := `tput setaf 6`
FONT_RED := `tput setaf 1`
FONT_RESET := `tput sgr0`

ANALYZER := tis-analyzer++
COMPILER := g++
CPPFLAGS := -std=c++11

.PHONY: all cov tis tis_gui clean

all:
	@echo -e "$(FONT_CYAN)$(COMPILER) $(CPPFLAGS) -I. caesar.cpp main.cpp -o caesar && ./caesar$(FONT_RESET)"
	$(COMPILER) $(CPPFLAGS) -I. caesar.cpp main.cpp -o caesar && ./caesar

cov:
	@echo -e "$(FONT_CYAN)$(COMPILER) -I. -fprofile-arcs -ftest-coverage caesar.c main.c -o caesar && ./caesar$(FONT_RESET)"
	@$(COMPILER) $(CPPFLAGS) -I. -fprofile-arcs -ftest-coverage caesar.cpp
	@$(COMPILER) $(CPPFLAGS) -I. -fprofile-arcs -ftest-coverage main.cpp
	@$(COMPILER) $(CPPFLAGS) -I. caesar.o main.o -o caesar && ./caesar
	@echo ""
	@echo -e "$(FONT_CYAN) gcov caesar.cpp $(FONT_RESET)"
	@gcov caesar.cpp

tis:
	@echo -e "$(FONT_CYAN)$(ANALYZER) -64 $(CPPFLAGS) -I. -val -slevel 100 caesar.cpp main.cpp -no-val-print$(FONT_RESET)"
	@$(ANALYZER) $(CPPFLAGS) -64 -I.-val -slevel 100 caesar.cpp main.cpp -no-val-print

tis_gui:
	@echo -e "$(FONT_CYAN)$(ANALYZER) $(CPPFLAGS) -64 -I . -val -slevel 100 caesar.c main.c -no-val-print -gui$(FONT_RESET)"
	@$(ANALYZER) $(CPPFLAGS) -64 -I. -val -slevel 100 caesar.cpp main.cpp -no-val-print -gui

clean:
	rm -rf a.out a.out.dSYM caesar caesar.dSYM *.gcov *.gcda *.gcno
