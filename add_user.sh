#!/bin/bash
if [[ -d Users/$1 ]]; then
  rm -r Users/$1
fi
mkdir Users/$1
touch Users/$1/info.txt
echo -e "$2\n$3\n$4\n$5\n$6" > Users/$1/info.txt
