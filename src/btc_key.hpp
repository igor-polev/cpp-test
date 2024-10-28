// Class btc_key definition.
// Generating several types of Bitcoin addresses
// using libbitcoin-system library.

#ifndef BTC_KEY_HPP
#define BTC_KEY_HPP

#include "btc_global.h"
#include "btc_public.hpp"
#include "btc_address.hpp"
#include <bitcoin/system.hpp>
#include <QObject>

using namespace bc::system;

class btc_key : public QObject {

    Q_OBJECT

public:

    inline btc_key() {
        _init_with("no-input");
    };
    inline btc_key(const string& passphrase) {
        _init_with(passphrase);
    };
    operator string() const;

public slots:

    void changeValue(QString user_input);

private:

    string             _passphrase;
    hash_digest        _sha256_hash;
    wallet::ec_private _uncompressed_private;
    wallet::ec_private _compressed_private;
    btc_public         _compressed_public;
    btc_address        _uncompressed_p2pkh;
    btc_address        _compressed_p2pkh;
    btc_address        _compressed_p2sh;
    string             _compressed_bech32;

    void _init_with(const string& pass_phrase);

public:

    inline string get_private() const {
        return encode_base16(_sha256_hash);
    };
    inline string get_WIFc() const {
        return _compressed_private.encoded();
    };
    inline string get_WIFu() const {
        return _uncompressed_private.encoded();
    };
    inline string get_P2PKHc() const {
        return _compressed_p2pkh.encoded();
    };
    inline string get_P2PKHu() const {
        return _uncompressed_p2pkh.encoded();
    };
    inline string get_P2SHc() const {
        return _compressed_p2sh.encoded();
    };
    inline string get_BECH32c() const {
        return _compressed_bech32;
    };

};

#endif