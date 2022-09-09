SHELL := /bin/bash

FONT_BOLD := `tput bold`
FONT_CYAN := `tput setaf 6`
FONT_RED := `tput setaf 1`
FONT_RESET := `tput sgr0`
TIS_ANALYZER := tis-analyzer
TIS_VAL_OPTS = -64 -I. -val -slevel 100 caesar.c main.c -no-val-print

.PHONY: all cov tis tis_gui tis_report
all:
	@echo -e "$(FONT_CYAN)gcc -I. caesar.c main.c -o caesar && ./caesar$(FONT_RESET)"
	@gcc -I. caesar.c main.c -o caesar && ./caesar


cov:
	@echo -e "$(FONT_CYAN)gcc -I. -fprofile-arcs -ftest-coverage caesar.c main.c -o caesar && ./caesar$(FONT_RESET)"
	@gcc -I. -fprofile-arcs -ftest-coverage caesar.c
	@gcc -I. -fprofile-arcs -ftest-coverage main.c
	@gcc -I. caesar.o main.o -o caesar && ./caesar
	@echo ""
	@echo -e "$(FONT_CYAN) gcov caesar.c $(FONT_RESET)"
	@gcov caesar.c

tis:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_VAL_OPTS) -tis-report$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_VAL_OPTS) -tis-report

tis_gui:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_VAL_OPTS) -gui$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_VAL_OPTS) -gui

tis_report: tis
	tis-report _results/
	xdg-open tis_report.html

.PHONY: clean
clean:
	rm -rf a.out a.out.dSYM caesar caesar.dSYM *.gcov *.gcda *.gcno
