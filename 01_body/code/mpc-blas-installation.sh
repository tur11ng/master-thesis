#!/bin#bash

mkdir YOUR_PROJECT_NAME
cd !!:$
git init .
mkdir extern
git submodule add https://github.com/st1064870/mpc-blas ./extern
