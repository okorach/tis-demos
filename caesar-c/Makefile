SHELL := /bin/bash

FONT_BOLD := `tput bold`
FONT_CYAN := `tput setaf 6`
FONT_RED := `tput setaf 1`
FONT_RESET := `tput sgr0`
TIS_ANALYZER := tis-analyzer
FILES := test_driver.c caesar.c
TISA_L2_OPTS = -tis-config-load tis-l2.json
TISA_L1_OPTS = -tis-config-load tis-l1.json

.PHONY: test cov clean tis_l1 tis_l2 tis_l1_report tis_l2_report tis_l1_gui tis_l2_gui test1 test2 test-int

all:
	@echo -e "$(FONT_CYAN)gcc -I. $(FILES) -o caesar && ./caesar$(FONT_RESET)"
	@gcc -I. $(FILES) -o caesar && ./caesar

cov:
	@echo -e "$(FONT_CYAN)gcc -I. -fprofile-arcs -ftest-coverage $(FILES) -o caesar && ./caesar$(FONT_RESET)"
	@gcc -I. -fprofile-arcs -ftest-coverage $(FILES) -o caesar && ./caesar
	@echo ""
	@echo -e "$(FONT_CYAN)gcov caesar.c $(FONT_RESET)"
	@gcov caesar.c

tis_l1_report:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TISA_L1_OPTS) -tis-report -info-json-results _results/caesar.json -info-csv-all _results/caesar$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TISA_L1_OPTS) -tis-report -main test1 -info-json-results _results/positive-shift_results.json -info-csv-all _results/positive-shift
	@$(TIS_ANALYZER) $(TISA_L1_OPTS) -tis-report -main test2 -info-json-results _results/negative-shift_results.json -info-csv-all _results/negative-shift
	tis-report _results/

tis_l2_report:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) -D LEVEL2=1  $(TISA_L2_OPTS) -tis-report$(FONT_RESET)"
	@$(TIS_ANALYZER) -D LEVEL2=1 $(TISA_L2_OPTS) -main test_generalized_int -tis-report -info-json-results _results/generalized-shift.json -info-csv-all _results/generalized-shift
	@tis-report _results/
	@printf "\n\nCheck generated test report $(FONT_CYAN)tis_report.html$(FONT_RESET)\n\n"
#	@printf "\n\nCheck generated test report $(FONT_CYAN)file:/`pwd`/tis_report.html$(FONT_RESET)\n\n"

tis_l2_gui:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) -D LEVEL2=1  $(TISA_L2_OPTS) -tis-report -gui$(FONT_RESET)"
	@$(TIS_ANALYZER) -D LEVEL2=1 $(TISA_L2_OPTS) -main test_generalized_int -tis-report -info-json-results _results/generalized-shift.json -info-csv-all _results/generalized-shift -gui

tis_l2_step2_gui:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) -D LEVEL2=1  $(TISA_L2_OPTS) -gui$(FONT_RESET)"
	@$(TIS_ANALYZER) -D LEVEL2_STEP2=1 $(TISA_L2_OPTS) -gui

tis_l1_gui:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TISA_L1_OPTS) -gui$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TISA_L1_OPTS) -gui | sed '/stack:.*main.c/q'

tis_l1: tis_l1_report
	tis-report _results/
	@printf "\n\nCheck generated test report $(FONT_CYAN)tis_report.html$(FONT_RESET)\n\n"

tis_l2: tis_l2_gui

tis_l2_step2: tis_l2_step2_gui

clean:
	@rm -rf a.out a.out.dSYM caesar caesar.dSYM *.gcov *.gcda *.gcno _results tis_report.html
