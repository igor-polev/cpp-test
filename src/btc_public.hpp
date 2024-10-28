// Class btc_public definition.
// Derived from bc::wallet::ec_public,
// added BECH32 string generation.

#ifndef BTC_PUBLIC_HPP
#define BTC_PUBLIC_HPP

#include "btc_global.h"
#include <bitcoin/system.hpp>

using namespace bc::system;
using namespace wallet;
using namespace chain;

class btc_public : public ec_public {

public:

    inline btc_public() :
        ec_public() {};
    inline btc_public(const ec_public& other) : 
        ec_public(other.encoded()) {};

    string to_bech32_string() const;

protected:

    bool is_initialized() const;

};

#endif