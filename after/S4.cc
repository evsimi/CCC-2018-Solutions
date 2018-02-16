#include <cstdint>
#include <cmath>
#include <iostream>
#include <cstring>

using namespace std;

int64_t *countMap;
uint64_t n;

int64_t count(uint64_t w) {
    int64_t value = countMap[w];
    if (value == -1) {
        value = 0;
        for (uint64_t i = 2; i <= w; ++i) {
            value += count((uint64_t) floor((double) w / i));
        }
        countMap[w] = value;
    }
    return value;
}

int main() {
    cin >> n;
    countMap = new int64_t[n + 1];
    memset(countMap, 255, (n + 1) * sizeof(int64_t));
    countMap[0] = 0;
    countMap[1] = 1;
    cout << count(n);
}
