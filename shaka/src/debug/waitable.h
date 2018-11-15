// Copyright 2018 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef SHAKA_EMBEDDED_DEBUG_WAITABLE_H_
#define SHAKA_EMBEDDED_DEBUG_WAITABLE_H_

#include <string>
#include <thread>

namespace shaka {

class Thread;

/**
 * The base class for objects that a thread can wait on.  These represent
 * resources that a thread needs to block for another thread to provide.  This
 * can be an explicit event (like a seek event) or it could be a lock that
 * another thread needs to release.
 */
class Waitable {
 public:
  explicit Waitable(const std::string& name);
  virtual ~Waitable();

  /** @return The name of this thing, used for debugging. */
  std::string name() const {
    return name_;
  }

  /**
   * @return The thread that will be providing the thing.  This can return
   *   id() if it is unknown.
   */
  virtual std::thread::id GetProvider() const = 0;

 private:
  const std::string name_;
};

}  // namespace shaka

#endif  // SHAKA_EMBEDDED_DEBUG_WAITABLE_H_
