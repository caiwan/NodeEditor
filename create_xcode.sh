mkdir -p xcode/
cd xcode 
cmake -DCMAKE_INSTALL_PREFIX=deploy/ -DCMAKE_PREFIX_PATH=../externals/ -G "Xcode" ../ 
cd ../

