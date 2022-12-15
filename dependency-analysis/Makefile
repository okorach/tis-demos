SHELL := /bin/bash

FONT_BOLD := `tput bold`
FONT_CYAN := `tput setaf 6`
FONT_RED := `tput setaf 1`
FONT_RESET := `tput sgr0`

TIS_ANALYZER := tis-analyzer
FILES := test_driver.c smart_meter.c
COMPILER := gcc
TIS_OPTS = -tis-config-load tis.json 

.PHONY: test cov clean tis_l1 tis_l2 tis_l1_report tis_l2_report tis_l1_gui tis_l2_gui test1 test2 test-int report

all:
	@echo -e "$(FONT_CYAN)$(COMPILER) -I. $(FILES) -o smart_meter && ./smart_meter$(FONT_RESET)"
	@$(COMPILER) -I. $(FILES) -o smart_meter && ./smart_meter

cov:
	@echo -e "$(FONT_CYAN)$(COMPILER) -I. -fprofile-arcs -ftest-coverage $(FILES) -o smart_meter && ./smart_meter$(FONT_RESET)"
	@$(COMPILER) -I. -fprofile-arcs -ftest-coverage $(FILES) -o smart_meter && ./smart_meter
	@echo ""
	@echo -e "$(FONT_CYAN)gcov smart_meter.c $(FONT_RESET)"
	@gcov smart_meter.c

tis:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS)$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS)

tis_gui:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER)  $(TIS_OPTS) -gui$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -gui

clean:
	@rm -rf a.out a.out.dSYM smart_meter smart_meter.dSYM *.gcov *.gcda *.gcno _results tis_report.html tis_misra_report *.log */*.log
