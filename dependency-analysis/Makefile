SHELL := /bin/bash

FONT_BOLD := `tput bold`
FONT_CYAN := `tput setaf 6`
FONT_RED := `tput setaf 1`
FONT_RESET := `tput sgr0`

TIS_ANALYZER := tis-analyzer
FILES := test_driver.c $(TARGET).c
TARGET := smart_meter
COMPILER := gcc
TIS_OPTS = -tis-config-load tis.json 

.PHONY: test clean tis tis_gui

all:
	@echo -e "$(FONT_CYAN)$(COMPILER) -I. $(FILES) -o $(TARGET) && ./$(TARGET)"
	@$(COMPILER) -I. $(FILES) -o $(TARGET) && ./$(TARGET)

tis:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -gui

tis_cli:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER)  $(TIS_OPTS) -gui"
	@$(TIS_ANALYZER) $(TIS_OPTS)

clean:
	@rm -rf a.out a.out.dSYM $(TARGET) $(TARGET).dSYM *.gcov *.gcda *.gcno _results tis_report.html tis_misra_report *.log */*.log
