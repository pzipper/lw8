# LW8
A lightweight UTF-8 implementation for C++.

## Building
Requires (`make`):

```sh
mkdir target # Make the binary output directory
make
```

### Run the example
```sh
g++ -Iinclude src/test.cpp -Ltarget -llw8 -o test
test
```