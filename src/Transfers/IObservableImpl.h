// Copyright (c) 2011-2017 The Cryptonote developers
// Copyright (c) 2017-2018 The Circle Foundation & invert Devs
// Copyright (c) 2018-2019 invert Network & invert Devs
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include "Common/ObserverManager.h"

namespace CryptoNote {

template <typename Observer, typename Base>
class IObservableImpl : public Base {
public:

  virtual void addObserver(Observer* observer) override {
    m_observerManager.add(observer);
  }

  virtual void removeObserver(Observer* observer) override {
    m_observerManager.remove(observer);
  }

protected:
  Tools::ObserverManager<Observer> m_observerManager;
};

}
