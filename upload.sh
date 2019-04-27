#!/bin/bash
if [[ -d ./$3 ]]
then
    cp $2 ./$3/$1
else
    mkdir ./#3
    cp $2 ./$3/$1
fi
