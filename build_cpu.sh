root=$(pwd)
prefix=$root/riscv-simulator

echo ${prefix}
if [ ! -d $prefix/build ]; then
    mkdir $prefix/build     
fi

cd ${prefix}'/build'
cmake ..
make
cd ${root}