#!/bin/bash

#Create a build directory and navigate into it
rm -rf build
mkdir build

build_type=Debug 

#Generate the Makefile using CMake
cmake -S . -B build/$build_type -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=$build_type
cmake --build build/$build_type --target ParticleSystem


#Check if the compilation was successful
if [ $? -eq 0 ]; then
	echo "Compilation successful. Running the ParticleSystem..."
	#Execute the ParticleSystem binary
	./build/*/ParticleSystem
else
	echo "Compilation failed. Please check the error messages."
fi