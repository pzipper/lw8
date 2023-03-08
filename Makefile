CXX = g++
CXX_FLAGS = -Iinclude -Wall -Wextra -Werror -pedantic

build:
	$(CXX) $(CXX_FLAGS) src/chars.cpp -c -o target/chars.o
	$(CXX) $(CXX_FLAGS) src/codepoint.cpp -c -o target/codepoint.o
	$(CXX) $(CXX_FLAGS) src/slice.cpp -c -o target/slice.o
	ar rc target/liblw8.lib target/chars.o target/codepoint.o target/slice.o

test:
	$(CXX) $(CXX_FLAGS) src/test.cpp target/liblw8.lib -o target/test