#!/bin/bash

#Create a build directory and navigate into it
rm -rf cmake-build-debug
mkdir cmake-build-debug
cd cmake-build-debug

cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
cmake --build . --config Debug

#build the project using CMake
make

#Check if the compilation was successful
if [ $? -eq 0 ]; then
	echo "Compilation successful. Running the ParticleSystem..."
	#Execute the ParticleSystem binary
	./ParticleSystem
else
	echo "Compilation failed. Please check the error messages."
fi