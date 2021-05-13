#!/bin/bash
g++ mst.cpp -std=c++11 -o mst
./mst > my_results.txt
echo "My Results"
echo
./mst
echo
echo "Solutions"
echo
cat HW4solution.txt
echo
diff -y -B -b --report-identical-files --suppress-common-lines my_results.txt HW4solution.txt
echo

