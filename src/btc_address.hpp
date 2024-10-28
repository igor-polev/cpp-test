// Class btc_address definition.
// Derived from bc::wallet::payment_address, added P2SH conversion.

#ifndef BTC_ADDRESS_HPP
#define BTC_ADDRESS_HPP

#include "btc_global.h"
#include <bitcoin/system.hpp>

using namespace bc::system;
using namespace wallet;
using namespace chain;

class btc_address : public payment_address {

public:

    inline btc_address() :
        payment_address() {};
    inline btc_address(const payment_address& other) : 
        payment_address(other.to_payment()) {};

    btc_address to_p2sh() const;

protected:

    bool is_initialized() const; 

};

#endif