// Copyright (c) 2011-2017 The Cryptonote developers
// Copyright (c) 2017-2018 The Circle Foundation & invert Devs
// Copyright (c) 2018-2019 invert Network & invert Devs
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <string>

#include "CryptoNoteCore/Currency.h"

namespace CryptoNote {

bool validateAddress(const std::string& address, const CryptoNote::Currency& currency);
void throwIfKeysMissmatch(const Crypto::SecretKey& secretKey, const Crypto::PublicKey& expectedPublicKey, const std::string& message = "");
}
