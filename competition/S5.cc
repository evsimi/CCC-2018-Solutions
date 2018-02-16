#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;

// This was written during the competition, but never completed

// Represents a specification for flights
struct flight {
    int a, b, c;

    int from(int f) const {
        return a == f ? b : b == f ? a : 0;
    }
};

// Represents a specification for portals
struct portal {
    int x, y, z;

    int from(int e) const {
        return x == e ? y : y == e ? x : 0;
    }
};

// Represents a possible step in a route
struct node {
    int city;
    flight *_flight;
    node *prev;
};

int main() {
    // Read the specs
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    list<flight> flights;
    list<portal> portals;
    for (int i = 0; i < p; ++i) {
        flight _flight;
        cin >> _flight.a >> _flight.b >> _flight.c;
        flights.push_back(_flight);
    }
    for (int i = 0; i < q; ++i) {
        portal _portal;
        cin >> _portal.x >> _portal.y >> _portal.z;
        portals.push_back(_portal);
    }
    // Recursive algorithm (incomplete) to remove the costliest unnecessary flight/portal
    function<void(node *,vector<flight>&)> optimize([&](node *n, vector<flight>& checked) {
        vector<flight *> _flights;
        transform(flights.begin(), flights.end(), back_inserter(_flights), [](flight& _flight){return &_flight;});
        remove_if(_flights.begin(), _flights.end(), [n](flight *_flight){return !_flight->from(n->city);});
        vector<node> _nodes;
        transform(_flights.cbegin(), _flights.cend(), back_inserter(_nodes), [n](flight *_flight){return node{_flight->from(n->city), _flight, n};});

    });
    // Start optimizing
    for (int i = 0; i < m; ++i) {
        node _node{i, nullptr, nullptr};
        vector<flight> checked;
        optimize(&_node, checked);
    }
}
