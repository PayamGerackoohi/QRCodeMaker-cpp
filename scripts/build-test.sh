set -e
cmake --build build
pushd build/test > /dev/null
ctest
popd > /dev/null
