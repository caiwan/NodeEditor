mkdir -p build/
cd build 
cmake -DCMAKE_INSTALL_PREFIX=deploy/ -DCMAKE_PREFIX_PATH=$QT5DIR -G "Unix Makefiles" ../ 
cd ../

