#!/bin/bash
BUILD_DIR=./build
[ -d "$BUILD_DIR" ] && [ -f "$BUILD_DIR/CMakeCache.txt" ] && rm "$BUILD_DIR/CMakeCache.txt" || mkdir -p $BUILD_DIR
cd $BUILD_DIR

echo $BUILD_DIR $PWD

echo "cmake -DCMAKE_INSTALL_PREFIX=deploy/ -DCMAKE_PREFIX_PATH=$CMAKE_PREFIX_PATH;$QT5_DIR -G \"Unix Makefiles\" ../"

cmake -DCMAKE_INSTALL_PREFIX=deploy/ -DCMAKE_PREFIX_PATH="$CMAKE_PREFIX_PATH;$QT5_DIR" -G "Unix Makefiles" ../
cmake --build ./ --target ExternalDependencies

cd ../
