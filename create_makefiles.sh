#!/bin/bash
DIR=./build
[ -d "$DIR" ] && [ -f "$DIR/CmakeCache.txt" ] && rm "$DIR/CmakeCache.txt" || mkdir -p $DIR
cd $DIR

cmake -DCMAKE_INSTALL_PREFIX=deploy/ -DCMAKE_PREFIX_PATH=$QT5DIR/lib/cmake -G "Unix Makefiles" ../

cmake --build ./ --target ExternalDependencies

cd ../
