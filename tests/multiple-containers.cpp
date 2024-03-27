#include <bits/stdc++.h>

// Test 1
void MultipleContainersWithTernaryOperator(std::vector<int>& v1, std::list<int>& l1, std::vector<int>& v2) {
    auto it1 = v1.begin();
    auto it2 = l1.begin();
    auto it3 = (v2.empty() ? v1.end() : v2.begin());

    if (it1 != v1.end() && it2 != l1.end() && it3 != v2.end()) {
        *it1 = 1; // Valid
        *it2 = 2; // Valid
        *it3 = 3; // Potentially invalid if v2 is empty
    }
}

// Test 2
void MultipleContainersWithComplexBranches(std::vector<int>& v1, std::list<int>& l1, std::set<int>& s1) {
    auto it1 = v1.begin();
    auto it2 = l1.begin();
    auto it3 = s1.begin();

    bool condition1 = !v1.empty();
    bool condition2 = !l1.empty();
    bool condition3 = !s1.empty();

    if (condition1) {
        if (condition2 && condition3) {
            *it1 = 1; // Valid
            *it2 = 2; // Valid
            *it3 = 3; // Valid
        } else if (condition2) {
            *it1 = 1; // Valid
            *it2 = 2; // Valid
            // it3 is potentially invalid
        } else {
            *it1 = 1; // Valid
            // it2 and it3 are potentially invalid
        }
    } else {
        // All iterators are potentially invalid
    }
}

// Test 3
void MultipleContainersWithLoops(std::vector<int>& v1, std::list<int>& l1, std::set<int>& s1) {
    auto it1 = v1.begin();
    auto it2 = l1.begin();
    auto it3 = s1.begin();

    while (it1 != v1.end() && it2 != l1.end() && it3 != s1.end()) {
        *it1 = 1; // Valid
        *it2 = 2; // Valid
        *it3 = 3; // Valid
        ++it1;
        ++it2;
        ++it3;
    }
}

// Test 4
void MultipleContainersWithInsert(std::vector<int>& v1, std::list<int>& l1) {
    auto it1 = v1.begin();
    auto it2 = l1.begin();

    if (it1 != v1.end() && it2 != l1.end()) {
        v1.insert(it1, 1); // Invalidates it1
        l1.insert(it2, 2); // Invalidates it2
        *it1; // Invalid
        *it2; // Invalid
    }
}

// Test 5
void MultipleContainersWithInsertAndCheck(std::vector<int>& v1, std::list<int>& l1) {
    auto it1 = v1.begin();
    auto it2 = l1.begin();

    if (it1 != v1.end() && it2 != l1.end()) {
        it1 = v1.insert(it1, 1); // Updates it1
        it2 = l1.insert(it2, 2); // Updates it2
        *it1; // Valid
        *it2; // Valid
    }
}

// Test 6
void MultipleContainersWithErase(std::vector<int>& v1, std::list<int>& l1) {
    auto it1 = v1.begin();
    auto it2 = l1.begin();

    while (it1 != v1.end() && it2 != l1.end()) {
        if (*it1 % 2 == 0) {
            it1 = v1.erase(it1);
        } else {
            ++it1;
        }

        if (*it2 % 2 == 0) {
            it2 = l1.erase(it2);
        } else {
            ++it2;
        }
    }
}

// Test 7
void MultipleContainersWithEraseInvalid(std::vector<int>& v1, std::list<int>& l1) {
    auto it1 = v1.begin();
    auto it2 = l1.begin();

    for (; it1 != v1.end(); ++it1) {
        for (; it2 != l1.end(); ++it2) {
            if (*it1 % 2 == 0) {
                v1.erase(it1); // Invalid
            }
            if (*it2 % 2 == 0) {
                l1.erase(it2); // Invalid
            }
        }
    }
}

// Test 8
void MultipleContainersWithSort(std::vector<int>& v1, std::list<int>& l1) {
    auto it1 = v1.begin();
    auto it2 = l1.begin();

    std::sort(v1.begin(), v1.end()); // Invalidates it1
    std::sort(l1.begin(), l1.end()); // Invalidates it2

    it1 = std::find(v1.begin(), v1.end(), 42); // Updates it1
    it2 = std::find(l1.begin(), l1.end(), 42); // Updates it2

    if (it1 != v1.end()) {
        *it1; // Valid
    }
    if (it2 != l1.end()) {
        *it2; // Valid
    }
}

// Test 9
void MultipleContainersWithSortInvalid(std::vector<int>& v1, std::list<int>& l1) {
    auto it1 = v1.begin();
    auto it2 = l1.begin();

    std::sort(v1.begin(), v1.end()); // Invalidates it1
    std::sort(l1.begin(), l1.end()); // Invalidates it2

    *it1; // Invalid
    *it2; // Invalid
}

// Test 10
void MultipleContainersWithReverse(std::vector<int>& v1, std::list<int>& l1) {
    auto it1 = v1.begin();
    auto it2 = l1.begin();

    std::reverse(v1.begin(), v1.end()); // Invalidates it1
    std::reverse(l1.begin(), l1.end()); // Invalidates it2

    it1 = v1.begin(); // Updates it1
    it2 = l1.begin(); // Updates it2

    if (it1 != v1.end()) {
        *it1; // Valid
    }
    if (it2 != l1.end()) {
        *it2; // Valid
    }
}

// Test 11
void MultipleContainersWithReverseInvalid(std::vector<int>& v1, std::list<int>& l1) {
    auto it1 = v1.begin();
    auto it2 = l1.begin();

    std::reverse(v1.begin(), v1.end()); // Invalidates it1
    std::reverse(l1.begin(), l1.end()); // Invalidates it2

    *it1; // Invalid
    *it2; // Invalid
}

// Test 12
void MultipleContainersWithRemoveIf(std::vector<int>& v1, std::list<int>& l1) {
    auto it1 = v1.begin();
    auto it2 = l1.begin();

    it1 = v1.erase(std::remove_if(v1.begin(), v1.end(), [](int i) { return i % 2 == 0; }), v1.end()); // Updates it1
    it2 = l1.erase(std::remove_if(l1.begin(), l1.end(), [](int i) { return i % 2 == 0; }), l1.end()); // Updates it2

    if (it1 != v1.end()) {
        *it1; // Valid
    }
    if (it2 != l1.end()) {
        *it2; // Valid
    }
}

// Test 13
void MultipleContainersWithRemoveIfInvalid(std::vector<int>& v1, std::list<int>& l1) {
    auto it1 = v1.begin();
    auto it2 = l1.begin();

    v1.erase(std::remove_if(v1.begin(), v1.end(), [](int i) { return i % 2 == 0; }), v1.end()); // Invalidates it1
    l1.erase(std::remove_if(l1.begin(), l1.end(), [](int i) { return i % 2 == 0; }), l1.end()); // Invalidates it2

    *it1; // Invalid
    *it2; // Invalid
}

// Test 14
void MultipleContainersWithSwap(std::vector<int>& v1, std::vector<int>& v2) {
    auto it1 = v1.begin();
    auto it2 = v2.begin();

    if (it1 != v1.end() && it2 != v2.end()) {
        v1.swap(v2); // Swaps the container values, but iterators remain valid
        *it1; // Valid
        *it2; // Valid
    }
}

// Test 15
void MultipleContainersWithSwapInvalid(std::vector<int>& v1, std::vector<int>& v2) {
    auto it1 = v1.begin();
    auto it2 = v2.begin();

    v1.swap(v2); // Swaps the container values, but iterators remain valid

    if (it1 != v2.end() || it2 != v1.end()) { // Wrong container check
        *it1; // Invalid
        *it2; // Invalid
    }
}

// Test 16
void MultipleContainersWithResize(std::vector<int>& v1, std::list<int>& l1) {
    auto it1 = v1.begin();
    auto it2 = l1.begin();

    v1.resize(10); // Invalidates it1
    l1.resize(5); // Invalidates it2

    it1 = v1.begin(); // Updates it1
    it2 = l1.begin(); // Updates it2

    if (it1 != v1.end()) {
        *it1; // Valid
    }
    if (it2 != l1.end()) {
        *it2; // Valid
    }
}

// Test 17
void MultipleContainersWithResizeInvalid(std::vector<int>& v1, std::list<int>& l1) {
    auto it1 = v1.begin();
    auto it2 = l1.begin();

    v1.resize(10); // Invalidates it1
    l1.resize(5); // Invalidates it2

    *it1; // Invalid
    *it2; // Invalid
}

// Test 18
void MultipleContainersWithClear(std::vector<int>& v1, std::list<int>& l1) {
    auto it1 = v1.begin();
    auto it2 = l1.begin();

    if (it1 != v1.end() && it2 != l1.end()) {
        v1.clear(); // Invalidates it1
        l1.clear(); // Invalidates it2
        *it1; // Invalid
        *it2; // Invalid
    }
}

// Test 19
void MultipleContainersWithClearAndCheck(std::vector<int>& v1, std::list<int>& l1) {
    auto it1 = v1.begin();
    auto it2 = l1.begin();

    if (it1 != v1.end() && it2 != l1.end()) {
        v1.clear(); // Invalidates it1
        l1.clear(); // Invalidates it2
    } else {
        *it1; // Valid
        *it2; // Valid
    }
}

// Test 20
void MultipleContainersWithFind(std::vector<int>& v1, std::list<int>& l1) {
    auto it1 = std::find(v1.begin(), v1.end(), 42);
    auto it2 = std::find(l1.begin(), l1.end(), 42);

    if (it1 != v1.end()) {
        *it1; // Valid
    }
    if (it2 != l1.end()) {
        *it2; // Valid
    }
}

// Test 21
void MultipleContainersWithFindAndErase(std::vector<int>& v1, std::list<int>& l1) {
    auto it1 = std::find(v1.begin(), v1.end(), 42);
    auto it2 = std::find(l1.begin(), l1.end(), 42);

    if (it1 != v1.end()) {
        v1.erase(it1); // Invalidates it1
    }
    if (it2 != l1.end()) {
        l1.erase(it2); // Invalidates it2
    }

    *it1; // Invalid
    *it2; // Invalid
}

// Test 22
void MultipleContainersWithFindAndInsert(std::vector<int>& v1, std::list<int>& l1) {
    auto it1 = std::find(v1.begin(), v1.end(), 42);
    auto it2 = std::find(l1.begin(), l1.end(), 42);

    if (it1 != v1.end()) {
        it1 = v1.insert(it1, 1); // Updates it1
        *it1; // Valid
    }
    if (it2 != l1.end()) {
        it2 = l1.insert(it2, 2); // Updates it2
        *it2; // Valid
    }
}
