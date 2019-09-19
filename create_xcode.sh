mkdir -p xcode/
cd xcode 
cmake -DCMAKE_INSTALL_PREFIX=deploy/ -DQt5_DIR=$QT5DIR -DCMAKE_PREFIX_PATH=$QT5DIR -G "Xcode" ../ 
cd ../

