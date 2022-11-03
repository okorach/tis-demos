#!/bin/bash

ME=$(basename $0)
DIR=$(dirname $0)
CONFIG="${DIR}/tis.json"
export CONFIG

function run_analysis {
   echo "Params = $*"
   analysis_name="$1"
   config_file="$CONFIG"
   opt=(
      -tis-config-load "${config_file}"
      -tis-config-select "${analysis_name}"
      -tis-report
      -save "_results/${analysis_name}.save"
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

nbrParallelTests=1

while getopts ":nh" opt; do
   case "$opt" in
      n)
         nbrParallelTests=${OPTARG}
         ;;
      *)
         usage
   esac
done

nbrTests=$(jq '. | length' < ${CONFIG})

echo "Main config file = $CONFIG"
echo "Total nbr of tests to run = $nbrTests"
echo "Nbr of tests to run in parallel = $nbrParallelTests"
parallel -j $nbrParallelTests run_analysis ::: $(seq 1 $nbrTests)

