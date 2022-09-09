SHELL := /bin/bash

FONT_BOLD := `tput bold`
FONT_CYAN := `tput setaf 6`
FONT_RED := `tput setaf 1`
FONT_MAGENTA := `tput setaf 5`
FONT_RESET := `tput sgr0`

TIS_ANALYZER := tis-analyzer++
TIS_VAL_OPTS = -64 -cpp-extra-args=\"-I.\" -val -slevel 100 caesar.cpp main.cpp -no-val-print
COMPILER := g++
CPPFLAGS := -std=c++11

.PHONY: all cov tis_run tis tis_gui clean

all:
	@echo -e "$(FONT_CYAN)$(COMPILER) $(CPPFLAGS) -I. caesar.cpp main.cpp -o caesar && ./caesar$(FONT_RESET)"
	$(COMPILER) $(CPPFLAGS) -I. caesar.cpp main.cpp -o caesar && ./caesar

cov:
	@echo -e "$(FONT_CYAN)$(COMPILER) -I. -fprofile-arcs -ftest-coverage caesar.cpp main.cpp -o caesar && ./caesar$(FONT_RESET)"
	@$(COMPILER) -I. -fprofile-arcs -ftest-coverage caesar.cpp main.cpp -o caesar && ./caesar
	@echo ""
	@echo -e "$(FONT_CYAN) gcov caesar.cpp $(FONT_RESET)"
	@gcov caesar.cpp

tis_run:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_VAL_OPTS) -tis-report -gui$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_VAL_OPTS) -tis-report | sed '/stack:.*main.cpp/q'
	
tis_gui:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_VAL_OPTS) -gui$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_VAL_OPTS) -gui | sed '/stack:.*main.cpp/q'

tis: tis_run
	tis-report _results/
	@printf "\n\nCheck generated test report $(FONT_CYAN)file:/`pwd`/tis_report.html$(FONT_RESET)\n\n"

clean:
	rm -rf a.out a.out.dSYM caesar caesar.dSYM *.gcov *.gcda *.gcno compile_commands.json tis_report.html _results
