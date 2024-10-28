// Class btc_key implementation

#include "btc_key.hpp"
#ifndef NDEBUG
#include <iostream>
#endif

using namespace wallet;

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

void btc_key::_reset() {

    _passphrase           = string();
    _sha256_hash          = hash_digest();
    _uncompressed_private = ec_private();
    _compressed_private   = ec_private();
    _compressed_public    = btc_public();
    _uncompressed_p2pkh   = btc_address();
    _compressed_p2pkh     = btc_address();
    _compressed_p2sh      = btc_address();
    _compressed_bech32    = string();

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

void btc_key::changeValue(const QString& user_input) {

    string new_pass = user_input.toStdString(); 
    if (new_pass == _passphrase) return;

    if (new_pass.length() < _min_pass_length)
        if (_passphrase.empty())
            return;
        else
            _reset();
    else
        _init_with(new_pass);

    emit newPrivate (QString::fromStdString(get_private()));
    emit newWIFc    (QString::fromStdString(get_WIFc()   ));
    emit newWIFu    (QString::fromStdString(get_WIFu()   ));
    emit newP2PKHc  (QString::fromStdString(get_P2PKHc() ));
    emit newP2PKHu  (QString::fromStdString(get_P2PKHu() ));
    emit newP2SHc   (QString::fromStdString(get_P2SHc()  ));
    emit newBECH32c (QString::fromStdString(get_BECH32c()));

    #ifndef NDEBUG
    std::cout << string(*this) << std::endl;
    #endif
};