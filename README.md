# Template For C Projects

![C](https://img.shields.io/badge/C-89%2F99%2F11%2F17-blue)
![License](https://camo.githubusercontent.com/890acbdcb87868b382af9a4b1fac507b9659d9bf/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f6c6963656e73652d4d49542d626c75652e737667)
![Build CI Test](https://github.com/franneck94/CProjectTemplate/workflows/Ubuntu%20CI%20Test/badge.svg)
[![codecov](https://codecov.io/gh/franneck94/CProjectTemplate/branch/master/graph/badge.svg)](https://codecov.io/gh/franneck94/CProjectTemplate)

This is a template for C projects. What you get:

- Library, executable and test code separated in distinct folders.
- Use of modern CMake for building and compiling.
- External libraries fetched by CMake or cloned by Git.
- Unit testing using [Unity](https://github.com/ThrowTheSwitch/Unity)
- General purpose libraries:
  - [log](https://github.com/rxi/log.c)
  - [argparse](https://github.com/cofyc/argparse)
- Continuous integration testing with Github Actions.
- Code coverage reports, including automatic upload to [Codecov](https://codecov.io).
- Code documentation with [Doxygen](http://www.stack.nl/~dimitri/doxygen/).

## Structure

``` text
├── CMakeLists.txt
├── app
│   ├── CMakesLists.txt
│   └── main.c
├── cmake
│   └── cmake modules
├── docs
│   ├── Doxyfile
│   └── html/
├── external
│   ├── CMakesLists.txt
│   ├── ...
├── src/my_lib
│   ├── CMakesLists.txt
│   ├── my_lib.h
│   └── my_lib.c
└── tests
    ├── CMakeLists.txt
    └── main.c
```

Library code goes into [src/](src/), main program code in [app/](app) and tests go in [tests/](tests/).

## Software Requirements

- CMake 3.16+
- GNU Makefile
- Doxygen
- MSVC 2017 (or higher), GCC 9 (or higher), Clang 9 (or higher)
- Code Coverage (only on GNU|Clang): lcov, gcovr

## Building

First, clone this repo and do the preliminary work:

```shell
git clone --recursive https://github.com/franneck94/CProjectTemplate
make prepare
```

- App Executable

```shell
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release --target main
cd app
./main
```

- Unit testing

```shell
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --config Debug --target unit_tests
cd tests
./unit_tests
```

- Documentation

```shell
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --config Debug --target docs
```

- Code Coverage (Unix only)

```shell
cd build
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_COVERAGE=ON ..
cmake --build . --config Debug --target coverage
```

For more info about CMake see [here](./CMakeGuide.md).
