#!/bin/bash

ME=$(basename $0)
CONFIG="$(dirname $0)/tis.json"
export CONFIG

function run_analysis {
   analysis_nbr="$1"
   opt=(
      -tis-config-load "${CONFIG}"
      -tis-config-select "${analysis_nbr}"
      -save "_results/${analysis_nbr}.save"
   )
   tis-analyzer "${opt[@]}"
}

function usage {

   cat << EOF
Usage: $ME [-n <n>] [-h]
Description: Runs multiple TrustInSoft analysis in parallel

-n: Defines the max number of parallel analysis, defaults to 1
-h: Displays this help and exits

Example:
$ME -n 5
EOF
   exit 1
}

export -f run_analysis
nbr_parallel_tests=1

while getopts "n:h" opt; do
   case "$opt" in
      n)
         nbr_parallel_tests=${OPTARG}
         ;;
      *)
         usage
   esac
done

nbr_tests=$(jq '. | length' < ${CONFIG})

echo "Main config file = $CONFIG"
echo "Total nbr of tests to run = $nbr_tests"
echo "Nbr of tests to run in parallel = $nbr_parallel_tests"
parallel -j $nbr_parallel_tests run_analysis ::: $(seq 1 $nbr_tests)

