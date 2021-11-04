// Copyright (c) 2011-2017 The Cryptonote developers
// Copyright (c) 2017-2018 The Circle Foundation & invert Devs
// Copyright (c) 2018-2019 invert Network & invert Devs
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <future>

namespace System {

namespace Detail {

template<class T> using Future = std::future<T>;

template<class T> Future<T> async(std::function<T()>&& operation) {
  return std::async(std::launch::async, std::move(operation));
}

}

}
