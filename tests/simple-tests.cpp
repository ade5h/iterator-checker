#include <bits/stdc++.h>

// Test 1
void EraseRemoveIdiomsWithIteratorChecks(std::vector<int>& v) {
    auto it = v.begin();
    while (it != v.end()) {
        if (*it % 2 == 0) {
            it = v.erase(it);
        } else {
            ++it;
        }
    }
}

// Test 2
void EraseRemoveIdiomsWithoutIteratorChecks(std::vector<int>& v) {
    for (auto it = v.begin(); it != v.end(); /* no ++it */) {
        if (*it % 2 == 0) {
            it = v.erase(it);
        } else {
            ++it;
        }
    }
}

// Test 3
void InsertInvalidatesIterators(std::vector<int>& v) {
    auto it = v.begin();
    v.insert(it, 42);
    *it; // Invalid
}

// Test 4
void InsertWithCheck(std::vector<int>& v) {
    auto it = v.begin();
    it = v.insert(it, 42);
    if (it != v.end()) {
        *it; // Valid
    }
}

// Test 5
void ReverseInvalidatesIterators(std::vector<int>& v) {
    auto it = v.begin();
    std::reverse(v.begin(), v.end());
    *it; // Invalid
}

// Test 6
void ReverseWithNewIterator(std::vector<int>& v) {
    auto it = v.begin();
    std::reverse(v.begin(), v.end());
    it = v.begin();
    if (it != v.end()) {
        *it; // Valid
    }
}

// Test 7
void SortInvalidatesIterators(std::vector<int>& v) {
    auto it = v.begin();
    std::sort(v.begin(), v.end());
    *it; // Invalid
}

// Test 8
void SortWithNewIterator(std::vector<int>& v) {
    auto it = v.begin();
    std::sort(v.begin(), v.end());
    it = std::find(v.begin(), v.end(), 42);
    if (it != v.end()) {
        *it; // Valid
    }
}

// Test 9
void RemoveIfInvalidatesIterators(std::vector<int>& v) {
    auto it = v.begin();
    v.erase(std::remove_if(v.begin(), v.end(), [](int i) { return i % 2 == 0; }), v.end());
    *it; // Invalid
}

// Test 10
void RemoveIfWithNewIterator(std::vector<int>& v) {
    auto it = v.begin();
    it = v.erase(std::remove_if(v.begin(), v.end(), [](int i) { return i % 2 == 0; }), v.end());
    if (it != v.end()) {
        *it; // Valid
    }
}

// Test 11
void RangeForLoopWithErase(std::vector<int>& v) {
    for (auto it = v.begin(); it != v.end(); /* no ++it */) {
        if (*it % 2 == 0) {
            it = v.erase(it);
        } else {
            ++it;
        }
    }
}

// Test 12
void RangeForLoopWithEraseInvalid(std::vector<int>& v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (*it % 2 == 0) {
            v.erase(it); // Invalid
        }
    }
}

// Test 13
void RangeForLoopWithInsert(std::vector<int>& v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (*it % 2 == 0) {
            it = v.insert(it, 42); // Updates iterator
            ++it; // Moves to next element
        }
    }
}

// Test 14
void RangeForLoopWithInsertInvalid(std::vector<int>& v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (*it % 2 == 0) {
            v.insert(it, 42); // Invalidates iterator
        }
    }
}

// Test 15
void ListIteratorWithErase(std::list<int>& l) {
    auto it = l.begin();
    while (it != l.end()) {
        if (*it % 2 == 0) {
            it = l.erase(it);
        } else {
            ++it;
        }
    }
}

// Test 16
void ListIteratorWithEraseInvalid(std::list<int>& l) {
    for (auto it = l.begin(); it != l.end(); ++it) {
        if (*it % 2 == 0) {
            l.erase(it); // Invalid
        }
    }
}

// Test 17
void SetIteratorWithErase(std::set<int>& s) {
    auto it = s.begin();
    while (it != s.end()) {
        if (*it % 2 == 0) {
            it = s.erase(it);
        } else {
            ++it;
        }
    }
}

// Test 18
void SetIteratorWithEraseInvalid(std::set<int>& s) {
    for (auto it = s.begin(); it != s.end(); ++it) {
        if (*it % 2 == 0) {
            s.erase(it); // Invalid
        }
    }
}

// Test 19
void MapIteratorWithErase(std::map<int, int>& m) {
    auto it = m.begin();
    while (it != m.end()) {
        if (it->second % 2 == 0) {
            it = m.erase(it);
        } else {
            ++it;
        }
    }
}

// Test 20
void MapIteratorWithEraseInvalid(std::map<int, int>& m) {
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second % 2 == 0) {
            m.erase(it); // Invalid
        }
    }
}