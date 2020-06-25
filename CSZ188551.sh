#!/bin/bash
if [ "$#" == 4 ]; then
    if [ "$3" == "-apriori" ]; then
        ./apriori "$2" "$1" "$4"
    fi
    if [ "$3" == "-fptree" ]; then
        ./fptree "$2" "$1" "$4"
    fi
fi

if [ "$#" == 2 ];then
    if [ "$2" == "-plot" ]; then
        python3 plot.py "$1"
    fi
fi




