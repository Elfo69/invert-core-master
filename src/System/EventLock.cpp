// Copyright (c) 2011-2017 The Cryptonote developers
// Copyright (c) 2017-2018 The Circle Foundation & invert Devs
// Copyright (c) 2018-2019 invert Network & invert Devs
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "EventLock.h"
#include <System/Event.h>

namespace System {

EventLock::EventLock(Event& event) : event(event) {
  while (!event.get()) {
    event.wait();
  }

  event.clear();
}

EventLock::~EventLock() {
  event.set();
}

}
