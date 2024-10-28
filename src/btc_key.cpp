// Class btc_key implementation

#include "btc_key.hpp"

using namespace wallet;

void btc_key::changeValue(QString user_input) {

    _init_with(user_input.toStdString());

    #ifndef NDEBUG
    #endif
};

void btc_key::_init_with(const string& passphrase) {

    _passphrase           = passphrase;
    _sha256_hash          = sha256_hash(_passphrase);
    _uncompressed_private = ec_private(_sha256_hash, ec_private::mainnet, false);
    _compressed_private   = ec_private(_sha256_hash, ec_private::mainnet, true);
    _compressed_public    = _compressed_private  .to_public();
    _uncompressed_p2pkh   = _uncompressed_private.to_payment_address();
    _compressed_p2pkh     = _compressed_private  .to_payment_address();
    _compressed_p2sh      = _compressed_p2pkh    .to_p2sh();
    _compressed_bech32    = _compressed_public   .to_bech32_string();

}

btc_key::operator string() const {

    string output;

    output += "Passphrase          : " + _passphrase   + "\n";
    output += "Private key         : " + get_private() + "\n";
    output += "WIF    uncompressed : " + get_WIFu()    + "\n";
    output += "WIF    compressed   : " + get_WIFc()    + "\n";
    output += "P2PKH  uncompressed : " + get_P2PKHu()  + "\n";
    output += "P2PKH  compressed   : " + get_P2PKHc()  + "\n";
    output += "P2SH   compressed   : " + get_P2SHc()   + "\n";
    output += "BECH32 compressed   : " + get_BECH32c() + "\n";

    return output;

}