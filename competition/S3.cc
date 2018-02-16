#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Represents a possible step for the robot
struct node {
    int i, j, len;
};

// Represents a position in the map
struct element {
    char c;
    int len;
};

// Preprocessor macros to avoid repetition without having to work with std::function<>
#define CHECK(i, j) \
{ \
    if (map[i][j].c == 'C') \
        valid = false; \
    else if (map[i][j].c != 'W') \
        continue; \
    break; \
}

#define PROCESS(i, j) \
{ \
    element& e = map[i][j]; \
    if (e.len == -1) { \
        bool valid = true; \
        if (e.c == '.') { \
            for (int _i = (i) - 1; _i >= 0; --_i) \
                CHECK(_i, j) \
            for (int _i = (i) + 1; _i < n; ++_i) \
                CHECK(_i, j) \
            for (int _j = (j) - 1; _j >= 0; --_j) \
                CHECK(i, _j) \
            for (int _j = (j) + 1; _j < m; ++_j) \
                CHECK(i, _j) \
        } \
        if (valid) { \
            e.len = v.len + (e.c == '.'); \
            next.push_back(node{i, j, e.len}); \
        } \
    } \
}

int main() {
    // Read in the map
    int n, m;
    cin >> n >> m;
    element map[n][m];
    node start{};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char &c = map[i][j].c;
            cin >> c;
            if (c == 'S')
                start = {i, j, 0};
            map[i][j].len = (c != 'W' && c != 'S') ? -1 : 0;
        }
        while (cin.get() != '\n');
    }

    // Generate next steps until there are no more
    vector<node> cur{start};
    vector<node> next;
    do {
        for (node& v : cur) {
            char c = map[v.i][v.j].c;
            if (c == 'S' ||c == '.' || c == 'U')
                PROCESS(v.i - 1, v.j);
            if (c == 'S' ||c == '.' || c == 'D')
                PROCESS(v.i + 1, v.j);
            if (c == 'S' ||c == '.' || c == 'L')
                PROCESS(v.i, v.j - 1);
            if (c == 'S' ||c == '.' || c == 'R')
                PROCESS(v.i, v.j + 1);
        }
        swap(cur, next);
        next.clear();
    } while (!cur.empty());

    // Print out the lengths to all empty cells
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (map[i][j].c == '.')
                cout << map[i][j].len << endl;
}
