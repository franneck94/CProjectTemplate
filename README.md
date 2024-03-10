# Template For C Projects

![C++](https://img.shields.io/badge/C%2B%2B-11%2F14%2F17%2F20%2F23-blue)
![License](https://img.shields.io/github/license/franneck94/CProjectTemplate)
![Linux Build](https://github.com/franneck94/CProjectTemplate/workflows/Ubuntu%20CI%20Test/badge.svg)

This is a template for C++ projects. What you get:

- Library, executable and test code separated in distinct folders.
- Use of modern CMake for building and compiling.
- External libraries fetched by CMake or cloned by Git.
- Unit testing using [Unity](https://github.com/ThrowTheSwitch/Unity)
- General purpose libraries:
  - [log](https://github.com/rxi/log.c)
  - [argparse](https://github.com/cofyc/argparse)
- Continuous integration testing and coverage reports with Github Actions.
- Code documentation with [Doxygen](http://www.stack.nl/~dimitri/doxygen/).
- Tooling: Clang-Format, Cmake-Format, Clang-tidy, Sanitizers

## Structure

``` text
├── CMakeLists.txt
├── app
│   ├── CMakesLists.txt
│   └── main.cc
├── cmake
│   └── cmake modules
├── docs
│   ├── Doxyfile
│   └── html/
├── external
│   ├── CMakesLists.txt
│   ├── ...
├── src
│   ├── CMakesLists.txt
│   ├── foo/
│   └── bar/
└── tests
    ├── CMakeLists.txt
    └── main.c
```

Library code goes into [src/](src/), main program code in [app/](app) and tests go in [tests/](tests/).

## Software Requirements

- CMake 3.21+
- GNU Makefile
- Doxygen
- Conan or VCPKG
- MSVC 2017 (or higher), G++9 (or higher), Clang++9 (or higher)
- Optional: Code Coverage (only on GNU|Clang): gcovr
- Optional: Makefile, Doxygen, Conan, VCPKG

## Building

First, clone this repo and do the preliminary work:

```shell
git clone --recursive https://github.com/franneck94/CppProjectTemplate
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

For more info about CMake see [here](./README_cmake.md).
