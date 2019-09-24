@echo off

if not exist msvc md msvc
if exist msvc\CMakeCache.txt del msvc\CMakeCache.txt

cd msvc
cmake -DCMAKE_PREFIX_PATH=%CMAKE_PREFIX_PATH%;%QT5_DIR% -DCMAKE_GENERATOR_PLATFORM=x64 ../
cmake --build ./ --target ExternalDependencies --config Debug
cmake --build ./ --target ExternalDependencies --config MinSizeRel
cd ..
