#!/bin/sh
echo Making build dir...
mkdir build
cd build
echo Running cmake...
cmake ..
echo building...
make
echo buil documentation
cd ..
doxygen doxy.config 
cd build
echo running...
./hellowt --docroot . --http-address 0.0.0.0 --http-port 8080
