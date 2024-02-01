clang_xx_bin = 'which clang++'
clang_bin = 'which clang'

if [ -z "$clang_bin" ]; then
    clang_ver = `dpkg --get-selections | grep clang | grep -v -m1 libclang | cut -f1 | cut -d '-' -f2`
    clang_bin = `which clang-$clang_ver`
    clang_xx_bin = `which clang++-$clang_ver`
fi

echo "Using $clang_xx_bin as C++ compiler"

mkdir -p build.clang && cd build.clang && cmake -DCMAKE_CXX_COMPILER="/usr/bin/clang++" -DCMAKE_C_COMPILER="/usr/bin/clang" .. && make -j4 && cd ..