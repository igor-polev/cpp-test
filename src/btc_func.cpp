// Service function implementation

#include "btc_func.hpp"
#include <stdexcept>

// Convert data between 2^x bases. Used in BECH32 encoding.
// Adopted from python version written by Pieter Wuille:
// https://github.com/libbitcoin/electrum/blob/master/electrum/segwit_addr.py

data_chunk convert_bits(
    const data_chunk& data,
    uint frombits,
    uint tobits,
    bool pad
) {

    data_chunk data_out;

    uint max_val = (1u << tobits) - 1u;
    uint max_acc = (1u << (frombits + tobits - 1u)) - 1u;

    uint acc  = 0u;
    uint bits = 0u;
    for (uint next_byte : data) {
        acc   = ((acc << frombits) | next_byte) & max_acc;
        bits += frombits;
        while (bits >= tobits) {
            bits -= tobits;
            data_out.push_back((uint8_t) (acc >> bits) & max_val);
        }
    }

    if (pad)
        if (bits)
            data_out.push_back((uint8_t) (acc << (tobits - bits)) & max_val);

    else if (bits >= frombits || ((acc << (tobits - bits)) & max_val))
        throw std::overflow_error("Bit base conversion failure!");

    return data_out;

}

