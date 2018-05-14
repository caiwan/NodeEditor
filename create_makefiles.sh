mkdir -p build/
cd build 
cmake -DCMAKE_INSTALL_PREFIX=deploy/ -DCMAKE_PREFIX_PATH=../externals/ -G "Unix Makefiles" ../ 
cd ../

