if not exist msvc md msvc
cd msvc

cd msvc
cmake -DCMAKE_INSTALL_PREFIX=deploy/dev -DCMAKE_PREFIX_PATH=%CMAKE_PREFIX_PATH% -G "Visual Studio 15 2017 Win64" ../ 
cd ..