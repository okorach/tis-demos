SHELL := /bin/bash

FONT_BOLD := `tput bold`
FONT_CYAN := `tput setaf 6`
FONT_RED := `tput setaf 1`
FONT_RESET := `tput sgr0`
TIS_ANALYZER := tis-analyzer
FILES = ../caesar.c gen_test.c
TISA_OPTS = -64 -cpp-extra-args="-I."
TISA_L2_OPTS = -val -slevel 100 $(TISA_OPTS)
TISA_L1_OPTS = --interpreter $(TISA_OPTS)

.PHONY: multiple_tests

multiple_tests:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TISA_L1_OPTS) -tis-report -info-json-results _results/caesar.json -info-csv-all _results/caesar$(FONT_RESET)"
	$(TIS_ANALYZER) $(TISA_L1_OPTS) $(FILES) test1.c -tis-report -info-json-results _results/caesar-1_results.json -info-csv-all _results/caesar1
	$(TIS_ANALYZER) $(TISA_L1_OPTS) $(FILES) test2.c -tis-report -info-json-results _results/caesar-2_results.json -info-csv-all _results/caesar2
	$(TIS_ANALYZER) $(TISA_L2_OPTS) $(FILES) test-int.c -tis-report -info-json-results _results/caesar-int_results.json -info-csv-all _results/caesar-int
	@tis-report _results/
	@mv tis_report.html ..
	@printf "\n\nCheck generated test report $(FONT_CYAN)tis_report.html$(FONT_RESET)\n\n"

clean:
	@rm -rf a.out a.out.dSYM caesar caesar.dSYM *.gcov *.gcda *.gcno _results tis_report.html
