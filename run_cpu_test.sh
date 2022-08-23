if [ ! -d 'test' ]; then mkdir 'test'; fi
if [ ! -d 'out' ]; then mkdir 'out'; fi

if [ -f ./testcases/$@.data ]; then 
    cp ./testcases/$@.data ./test/test.data; 
fi

./riscv-simulator/build/cpu out/cpu_metadata.json <./test/test.data 1> out/cpu_metadata.txt
