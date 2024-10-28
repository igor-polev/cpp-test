// Class btc_public implementation.

#include "btc_public.hpp"
#include "btc_func.hpp"
#include <bech32.h>
#include <cassert>

string btc_public::to_bech32_string() const {

    if (!is_initialized()) return "";

    data_chunk data;
    to_data(data);
    auto hash = bitcoin_short_hash(data);
    data = data_chunk(hash.begin(), hash.end());
    data = convert_bits(data, 8, 5);
    data.insert(data.begin(), 0x00);

    return bech32::encodeUsingOriginalConstant(
        "bc",
        std::vector<unsigned char>(data.begin(), data.end())
    );

}

bool btc_public::is_initialized() const {
    bool not_empty = (*this != btc_public());
    assert(not_empty && "instance not initialized");
    return not_empty;
}
