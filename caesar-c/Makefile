SHELL := /bin/bash

FONT_BOLD := `tput bold`
FONT_CYAN := `tput setaf 6`
FONT_RED := `tput setaf 1`
FONT_RESET := `tput sgr0`
TIS_ANALYZER := tis-analyzer
TISA_OPTS = -64 -cpp-extra-args="-I." caesar.c main.c
TISA_L2_OPTS = -val -slevel 100 $(TISA_OPTS)
TISA_L1_OPTS = --interpreter $(TISA_OPTS)

.PHONY: test cov clean tis_l1 tis_l2 tis_l1_report tis_l2_report tis_l1_gui tis_l2_gui

all:
	@echo -e "$(FONT_CYAN)gcc -I. caesar.c main.c -o caesar && ./caesar$(FONT_RESET)"
	@gcc -I. caesar.c main.c -o caesar && ./caesar

cov:
	@echo -e "$(FONT_CYAN)gcc -I. -fprofile-arcs -ftest-coverage caesar.c main.c -o caesar && ./caesar$(FONT_RESET)"
	@gcc -I. -fprofile-arcs -ftest-coverage caesar.c main.c -o caesar && ./caesar
	@echo ""
	@echo -e "$(FONT_CYAN)gcov caesar.c $(FONT_RESET)"
	@gcov caesar.c

tis_l1_report:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TISA_L1_OPTS) -tis-report -info-json-results _results/caesar.json -info-csv-all _results/caesar$(FONT_RESET)"
	$(TIS_ANALYZER) $(TISA_L1_OPTS) -tis-report -info-json-results _results/caesar.json -info-csv-all _results/caesar

tis_l2_report:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) -D LEVEL2=1  $(TISA_L2_OPTS) -tis-report$(FONT_RESET)"
	@$(TIS_ANALYZER) -D LEVEL2=1 $(TISA_L2_OPTS) -tis-report -info-json-results _results/caesar.json -info-csv-all _results/caesar
	@tis-report _results/
	@printf "\n\nCheck generated test report $(FONT_CYAN)tis_report.html$(FONT_RESET)\n\n"
#	@printf "\n\nCheck generated test report $(FONT_CYAN)file:/`pwd`/tis_report.html$(FONT_RESET)\n\n"

tis_l2_gui:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) -D LEVEL2=1  $(TISA_L2_OPTS) -gui$(FONT_RESET)"
	@$(TIS_ANALYZER) -D LEVEL2=1 $(TISA_L2_OPTS) -gui

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
