// Copyright (c) 2011-2017 The Cryptonote developers
// Copyright (c) 2017-2018 The Circle Foundation & invert Devs
// Copyright (c) 2018-2020 Karbo developers
// Copyright (c) 2018-2021 invert Network & invert Devs
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <string>
#include <unordered_map>
#include <map>
#include <parallel_hashmap/phmap.h>
#include "crypto/hash.h"
#include "CryptoNoteBasic.h"
using phmap::flat_hash_map;
namespace CryptoNote {

class ISerializer;

class PaymentIdIndex {
public:
  PaymentIdIndex() = default;

  bool add(const Transaction& transaction);
  bool remove(const Transaction& transaction);
  bool find(const Crypto::Hash& paymentId, std::vector<Crypto::Hash>& transactionHashes);
  void clear();

  void serialize(ISerializer& s);

  template<class Archive> 
  void serialize(Archive& archive, unsigned int version) {
    archive & index;
  }
private:
  std::unordered_multimap<Crypto::Hash, Crypto::Hash> index;
};

class TimestampBlocksIndex {
public:
  TimestampBlocksIndex() = default;

  bool add(uint64_t timestamp, const Crypto::Hash& hash);
  bool remove(uint64_t timestamp, const Crypto::Hash& hash);
  bool find(uint64_t timestampBegin, uint64_t timestampEnd, uint32_t hashesNumberLimit, std::vector<Crypto::Hash>& hashes, uint32_t& hashesNumberWithinTimestamps);
  void clear();

  void serialize(ISerializer& s);

  template<class Archive> 
  void serialize(Archive& archive, unsigned int version) {
    archive & index;
  }
private:
  std::multimap<uint64_t, Crypto::Hash> index;
};

class TimestampTransactionsIndex {
public:
  TimestampTransactionsIndex() = default;

  bool add(uint64_t timestamp, const Crypto::Hash& hash);
  bool remove(uint64_t timestamp, const Crypto::Hash& hash);
  bool find(uint64_t timestampBegin, uint64_t timestampEnd, uint64_t hashesNumberLimit, std::vector<Crypto::Hash>& hashes, uint64_t& hashesNumberWithinTimestamps);
  void clear();

  void serialize(ISerializer& s);

  template<class Archive>
  void serialize(Archive& archive, unsigned int version) {
    archive & index;
  }
private:
  std::multimap<uint64_t, Crypto::Hash> index;
};

class GeneratedTransactionsIndex {
public:
  GeneratedTransactionsIndex();

  bool add(const Block& block);
  bool remove(const Block& block);
  bool find(uint32_t height, uint64_t& generatedTransactions);
  void clear();

  void serialize(ISerializer& s);

  template<class Archive> 
  void serialize(Archive& archive, unsigned int version) {
    archive & index;
    archive & lastGeneratedTxNumber;
  }
private:
  flat_hash_map<uint32_t, uint64_t> index;
  uint64_t lastGeneratedTxNumber;
};

class OrphanBlocksIndex {
public:
  OrphanBlocksIndex() = default;

  bool add(const Block& block);
  bool remove(const Block& block);
  bool find(uint32_t height, std::vector<Crypto::Hash>& blockHashes);
  void clear();
private:
  std::unordered_multimap<uint32_t, Crypto::Hash> index;
};

}
