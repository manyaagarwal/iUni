#!/bin/bash
if [ -d ./$3 ]
then
    echo "directory existed"
    cp $2 ./$3/
else
    mkdir ./$3
    echo "Created directory"
    cp $2 ./$3/
fi
