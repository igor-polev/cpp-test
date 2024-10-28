// Class btc_address implementation.

#include "btc_address.hpp"
#include <cassert>

btc_address btc_address::to_p2sh() const {

    if (!is_initialized()) return btc_address();

    operations ops = output_script().ops();
    ops[0] = operation(opcode::push_size_0);
    ops[1] = ops[2];
    ops.resize(2);

    return btc_address(script(ops));

}

bool btc_address::is_initialized() const {
    bool not_empty = bool(*this);
    assert(not_empty && "instance not initialized");
    return not_empty;
}
