#!/bin/bash

FONT_BOLD=`tput bold`
FONT_CYAN=`tput setaf 6`
FONT_RED=`tput setaf 1`
FONT_RESET=`tput sgr0`

MSG="Press [Enter] to proceed: "
H1="================================================================================"
H2="--------------------------------------------------------------------------------"

steps=true
while getopts ":s" opt; do
    case "$opt" in
        s)
            steps=false
            ;;
        *)
            usage
            ;;
    esac
done

clear
printf "\n\n$FONT_CYAN$H1\n"
printf "           WHAT IS AN UNDEFINED BEHAVIOR (UB)?\n"
printf "$H1$FONT_RESET\n\n"

printf "Here a simple program, and we'll see it can have 2 behaviors because of an UB\n\n"

cat toy-ub.c

printf "\n"

[ "$steps" = "true" ] && read -p "$MSG" c

clear
printf "\n$H2\n${FONT_CYAN}Let's run the program after -O2 compilation\n"
sleep 2
printf "clang -O2 toy-ub.c && ./a.out${FONT_RESET}\n"

clang -O2 toy-ub.c && ./a.out

printf "\nThe value returned is ${FONT_CYAN}1${FONT_RESET}\n\n"
[ "$steps" = "true" ] && read -p "$MSG" c

printf "\n$H2\n${FONT_CYAN}Now let's run with different compilation options\n"
sleep 2
printf "clang     toy-ub.c && ./a.out${FONT_RESET}\n"

clang toy-ub.c && ./a.out

printf "\nThe value returned is ${FONT_CYAN}1073741824${FONT_RESET}\n"
printf "This value is different due to an ${FONT_RED}invisible undefined behavior${FONT_RESET}\n\n"
[ "$steps" = "true" ] && read -p "$MSG" c

clear
printf "\n$H2\nLet's now analyze with TrustInSoft Analyzer\n"
[ "$steps" = "true" ] && read -p "$MSG" c
printf "\nSimply run ${FONT_CYAN}tis-analyzer toy-ub.c -sa --interpreter${FONT_RESET}\n"
sleep 2
tis-analyzer toy-ub.c -sa --interpreter

cat << EOF
$H2
The above log:
${FONT_CYAN}warning: The pointer q has type float *. It violates strict aliasing rules by
accessing a cell with effective type int.${FONT_RESET}
demonstrates that the TrustInSoft Analyzer has found a ${FONT_RED}strict aliasing Undefined Behavior${FONT_RESET}
$H2
EOF