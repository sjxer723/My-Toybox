# copy test input
if [ ! -d 'test/' ]; then mkdir 'test/'; fi
if [ ! -d 'out/' ]; then mkdir 'out/'; fi
if [ -f ./testcases/$@.c ]; then cp ./testcases/$@.c ./test/test.c; cp ./testcases/io.inc ./test/; fi

./sparse/test-call-graph test/test.c 1> out/sparse_metadata.txt