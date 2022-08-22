# copy test input
if [ -f ./testcases/$@.c ]; then cp ./testcases/$@.c ./test/test.c; cp ./testcases/io.inc ./test/; fi
# copy test output
#if [ -f ./testcase/$@.ans ]; then cp ./testcase/$@.ans ./test/test.ans; fi
# add your own test script here
# Example:
./sparse/test-call-graph test/test.c

#> ${path}/cpu.out

#tail -n +2 ${path}/my.tmp > ${path}/my.out

#cat ${path}/my.out

# - diff ./test/test.ans ./test/test.out