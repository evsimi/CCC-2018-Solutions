#include <cstdint>
#include <cmath>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

// Cache of known results of count() to avoid recalculating entire
// recursion trees
map<uint64_t, uint64_t> countMap{{0, 0}, {1, 1}};

uint64_t count(uint64_t n) {
    auto mapping = countMap.find(n);
    if (mapping != countMap.end())
        return mapping->second;
    uint64_t value = 0;
    for (uint64_t i = 2; i <= n; ++i) {
        value += count((uint64_t) floor((double) n / i));
    }
    countMap[n] = value;
    return value;
}

int main() {
    uint64_t n;
    cin >> n;
    cout << count(n);
}
