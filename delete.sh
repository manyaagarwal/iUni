#!/bin/bash
if [[ -d ./$2 ]]
then
    cd ./$2
    rm $1
fi
