#!/bin/bash
DIR=./xcode
[ -d "$DIR" ] && [ -f "$DIR/CmakeCache.txt" ] && rm $DIR/CmakeCache.txt || mkdir -p $DIR
cd $DIR

cmake -DCMAKE_INSTALL_PREFIX=deploy/ -DCMAKE_PREFIX_PATH="$MAKE_PREFIX_PATH;$QT5_DIR" -G "Xcode" ../

cmake --build ./ --target ExternalDependencies --config Debug
cmake --build ./ --target ExternalDependencies --config MinSizeRel

cd ../
