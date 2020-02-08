sample :
	g++ samples/Samples.cpp \
	-std=c++14 -Iinclude/   \
	-o Sample

gtests :
	g++ tests/Tests.cpp    \
	-std=c++14 -Iinclude/  \
	-lgtest -pthread       \
	-o GTests
