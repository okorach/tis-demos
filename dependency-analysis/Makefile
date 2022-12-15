SHELL := /bin/bash

FONT_BOLD := `tput bold`
FONT_CYAN := `tput setaf 6`
FONT_RED := `tput setaf 1`
FONT_RESET := `tput sgr0`

TIS_ANALYZER := tis-analyzer
FILES := test_driver.c smart_meter.c
COMPILER := gcc
TIS_OPTS = -tis-config-load tis.json 

.PHONY: test clean tis tis_gui

all:
	@echo -e "$(FONT_CYAN)$(COMPILER) -I. $(FILES) -o smart_meter && ./smart_meter$(FONT_RESET)"
	@$(COMPILER) -I. $(FILES) -o smart_meter && ./smart_meter

tis:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS)$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -gui

tis_cli:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER)  $(TIS_OPTS) -gui$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS)

clean:
	@rm -rf a.out a.out.dSYM smart_meter smart_meter.dSYM *.gcov *.gcda *.gcno _results tis_report.html tis_misra_report *.log */*.log
