SHELL := /bin/bash

FONT_BOLD := `tput bold`
FONT_CYAN := `tput setaf 6`
FONT_RED := `tput setaf 1`
FONT_RESET := `tput sgr0`

TIS_ANALYZER := tis-analyzer
FILES := test_driver.c check_all_zeros.cpp
COMPILER := gcc
TIS_OPTS = -tis-config-load tis.json -tis-report

.PHONY: test cov clean tis_l1 tis_l2 tis_l1_report tis_l2_report tis_l1_gui tis_l2_gui test1 test2 test-int report

all:
	@echo -e "$(FONT_CYAN)$(COMPILER) -I. $(FILES) -o smart_meter && ./smart_meter$(FONT_RESET)"
	@$(COMPILER) -I. $(FILES) -o smart_meter && ./smart_meter

cov:
	@echo -e "$(FONT_CYAN)$(COMPILER) -I. -fprofile-arcs -ftest-coverage $(FILES) -o smart_meter && ./smart_meter$(FONT_RESET)"
	@$(COMPILER) -I. -fprofile-arcs -ftest-coverage $(FILES) -o smart_meter && ./smart_meter
	@echo ""
	@echo -e "$(FONT_CYAN)gcov $(TARGET).c $(FONT_RESET)"
	@gcov smart_meter.c

tis:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) --tis-config-select 1"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select 1 -wp-fct _ZN1AILi10EE15check_all_zerosEv

tis_gui:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER)  $(TIS_OPTS) -gui"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select 1 -gui -wp-fct _ZN1AILi10EE15check_all_zerosEv

report:
	@printf "Compiling report from past executed tests:\n"
	@rm -f _results/analysis-*.json
	@ls _results/*.json | sed 's/_results\.json//'
	@tis-report _results/ --skip-file test_driver.c
	@printf "\n\nCheck generated test report $(FONT_CYAN)tis_report.html$(FONT_RESET)\n\n"

break_build:
	@! cat _results/*_results.json|jq '{status: .alarms.status}'|grep -H '"status": "NOT OK"'

clean:
	@rm -rf a.out a.out.dSYM smart_meter smart_meter.dSYM *.gcov *.gcda *.gcno _results tis_report.html tis_misra_report *.log */*.log
