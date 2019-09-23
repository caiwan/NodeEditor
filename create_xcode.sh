#!/bin/bash
DIR=./xcode
[ -d "$DIR" ] && [ -f "$DIR/CmakeCache.txt" ] && rm $DIR/CmakeCache.txt || mkdir -p $DIR
cd $DIR

cmake -DCMAKE_INSTALL_PREFIX=deploy/ -DQT5DIR=$QT5DIR -DCMAKE_PREFIX_PATH=$QT5DIR -G "Xcode" ../

cmake --build ./ --target ExternalDependencies --config Debug
cmake --build ./ --target ExternalDependencies --config MinSizeRel

cd ../
