# Bitcoin address generation - C++ test task 

## Description

This program solves the problems stated for testing C++ programming skills. It receives line of text with passphrase and generates a set of Bitcoin addresses. Simple Qt6 GUI is implemented. Separate console program for test data example check was build (see [/src/test.cpp](https://github.com/igor-polev/cpp-test/blob/main/src/test.cpp)). Executables was built for Windows* and Linux.

Problem statement is given in [task folder](https://github.com/igor-polev/cpp-test/tree/main/task) together with solution details description, test log files and short video of working program as requested by task author.

## Dependencies

Compiled executables do not require any extra software or installation. Just [download](https://github.com/igor-polev/cpp-test/tree/main/release)  and run. To build from sources you will need libraries:

[libbitcoin-system](https://github.com/libbitcoin/libbitcoin-system),
[Boost](https://www.boost.org/),
[secp256k1](https://github.com/libbitcoin/secp256k1),
[libbech32](https://github.com/dcdpr/libbech32),
[Qt](https://doc.qt.io/).

Boost and secp256k1 can be installed using libbitcoin-system installation script (see [libbitcoin installation](https://github.com/libbitcoin/libbitcoin-system#installation)).

## Development toolchain

The code was written using [VS Code](https://code.visualstudio.com/) IDE for Linux. It was built using standard GNU C++ compiler (for Linux) and Visual C++ (for Windows)*. [CMake](https://cmake.org/) build management toolset was used.

## Acknowledgements

Special thanks to Pieter Wuille whose [python code](https://github.com/libbitcoin/electrum/blob/master/electrum/segwit_addr.py) was translated into C++ for 8-to-5 bit data conversion function (see [/src/btc_func.cpp](https://github.com/igor-polev/cpp-test/blob/main/src/btc_func.cpp)). It saved me some valuable time.

### Notes

* Not fully implemented yet.