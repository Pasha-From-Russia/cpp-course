#!/bin/bash

IGNORES=$(cat .gitignore)

for dir in $(ls); do
    [ ! -d ${dir} ] && continue
    cd ${dir}
    for i in ${IGNORES}; do
        rm -rf ${i}
    done
    cd ..
done
