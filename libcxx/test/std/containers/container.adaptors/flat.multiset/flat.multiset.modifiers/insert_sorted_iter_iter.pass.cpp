//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++03, c++11, c++14, c++17, c++20

// <flat_set>

// template <class InputIterator>
//   void insert(sorted_equivalent_t, InputIterator first, InputIterator last);

#include <flat_set>
#include <cassert>
#include <functional>
#include <deque>

#include "MinSequenceContainer.h"
#include "../helpers.h"
#include "test_macros.h"
#include "test_iterators.h"
#include "min_allocator.h"

// test constraint InputIterator
template <class M, class... Args>
concept CanInsert = requires(M m, Args&&... args) { m.insert(std::forward<Args>(args)...); };

using Set = std::flat_multiset<int>;

static_assert(CanInsert<Set, std::sorted_equivalent_t, int*, int*>);
static_assert(CanInsert<Set, std::sorted_equivalent_t, cpp17_input_iterator<int*>, cpp17_input_iterator<int*>>);
static_assert(!CanInsert<Set, std::sorted_equivalent_t, int, int>);
static_assert(!CanInsert<Set, std::sorted_equivalent_t, cpp20_input_iterator<int*>, cpp20_input_iterator<int*>>);

template <class KeyContainer>
void test_one() {
  using Key = typename KeyContainer::value_type;
  using M   = std::flat_multiset<Key, std::less<Key>, KeyContainer>;

  int ar1[] = {1, 2, 2, 3};

  int ar2[] = {0, 2, 4, 4};

  M m;
  m.insert(std::sorted_equivalent,
           cpp17_input_iterator<int*>(ar1),
           cpp17_input_iterator<int*>(ar1 + sizeof(ar1) / sizeof(ar1[0])));
  assert(m.size() == 4);
  M expected{1, 2, 2, 3};
  assert(m == expected);

  m.insert(std::sorted_equivalent,
           cpp17_input_iterator<int*>(ar2),
           cpp17_input_iterator<int*>(ar2 + sizeof(ar2) / sizeof(ar2[0])));
  assert(m.size() == 8);
  M expected2{0, 1, 2, 2, 2, 3, 4, 4};
  assert(m == expected2);
}

void test() {
  test_one<std::vector<int>>();
  test_one<std::deque<int>>();
  test_one<MinSequenceContainer<int>>();
  test_one<std::vector<int, min_allocator<int>>>();
}

void test_exception() {
  auto insert_func = [](auto& m, const auto& newValues) {
    m.insert(std::sorted_equivalent, newValues.begin(), newValues.end());
  };
  test_insert_range_exception_guarantee(insert_func);
}

int main(int, char**) {
  test();
  test_exception();

  return 0;
}
