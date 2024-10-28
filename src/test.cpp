// Console test program

#include "btc_global.h"
#include "btc_key.hpp"
#include "btc_func.hpp"

const string test_input   = "bitcoin is awesome";
const string test_private = "23d4a09295be678b21a5f1dceae1f634a69c1b41775f680ebf8165266471401b";
const string test_WIFc    = "KxRMt7KypfEsLNSikhxTPYepDMBizHNmH5Bii3wssgesxrkHNJg6";
const string test_WIFu    = "5J64pq77XjeacCezwmAr2V1s7snvvJkuAz8sENxw7xCkikceV6e";
const string test_P2PKHc  = "1JRW4d8vHZseMEtYbgJ7MwPG1TasHUUVNq";
const string test_P2PKHu  = "14NWDXkQwcGN1Pd9fboL8npVynD5SfyJAE";
const string test_P2SHc   = "3LtPxQEqqo1sYGF7VTEufzBUki6pFiDVa1";
const string test_BECH32c = "bc1qhuwxrtqe2akhr4rz8vv97waw9g75ma4unk5vnf";

int main(int argc, char* argv[]) {

    btc_key test_key(test_input);
    test_ostream test_log("test_results.txt");

    test_log << "------ Testing program ------\n\n";
    test_log << string(test_key) << "\n";

    test_log << "Private key test ... " <<
    ((test_private == test_key.get_private()) ? "OK" : "ERROR") << "\n";

    test_log << "WIFc test        ... " <<
    ((test_WIFc    == test_key.get_WIFc())    ? "OK" : "ERROR") << "\n";

    test_log << "WIFu test        ... " <<
    ((test_WIFu    == test_key.get_WIFu())    ? "OK" : "ERROR") << "\n";

    test_log << "P2PKHc test      ... " <<
    ((test_P2PKHc  == test_key.get_P2PKHc())  ? "OK" : "ERROR") << "\n";

    test_log << "P2PKHu test      ... " <<
    ((test_P2PKHu  == test_key.get_P2PKHu())  ? "OK" : "ERROR") << "\n";

    test_log << "P2SHc test       ... " <<
    ((test_P2SHc   == test_key.get_P2SHc())   ? "OK" : "ERROR") << "\n";

    test_log << "BECH32c test     ... " <<
    ((test_BECH32c == test_key.get_BECH32c()) ? "OK" : "ERROR") << "\n";

    test_log << "\n------ Tests finished ------\n";

    return 0;
}
