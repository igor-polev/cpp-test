// Service functions

#ifndef BTC_FUNC_HPP
#define BTC_FUNC_HPP

#include "btc_global.h"
#include <bitcoin/system.hpp>
#include <iostream>
#include <fstream>

using namespace bc::system;

data_chunk convert_bits(
    const data_chunk& data,
    uint frombits,
    uint tobits,
    bool pad = true
);

// Dual output stream for tests logs.

class test_ostream {

private:

    std::fstream _fout;

public:

    test_ostream(const string& filename) : 
        _fout(std::fstream(filename, std::fstream::out)) {};
    ~test_ostream() { _fout.close(); };

    test_ostream& operator << (const string& output_str) {
        std::cout << output_str;
        _fout     << output_str;
        return *this;
    };
};

#endif