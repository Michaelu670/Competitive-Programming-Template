#include <algorithm>
#include <stack>
#include <utility>
// DSU With Rank Compression and Rollback Support

const int NMAX = 200005;

int par[NMAX];
int sz[NMAX];
std::stack<std::pair<int, std::pair<int, int>>> rollb;

int getpar(int x) {
    if (par[x] == x) return x;
    return getpar(par[x]);
}

void init(int cnt = NMAX) {
    // call this
    for(int i = 0; i < cnt; ++i) {
        par[i] = i;
        sz[i] = 1;
    }
}

bool isSame(int u, int v) {
    return getpar(u) == getpar(v);
}

void merge(int u, int v) {
    u = getpar(u), v = getpar(v);
    if (u == v) {
        return;
    }

    if (sz[u] < sz[v]) {
        std::swap(u, v);
    }

    rollb.push({v, {par[v], sz[v]}});
    rollb.push({u, {par[u], sz[u]}});
    par[v] = u;
    sz[u] += sz[v];
}

void rollback() {
    par[rollb.top().first] = rollb.top().second.first;
    sz[rollb.top().first] = rollb.top().second.second;
    rollb.pop();
    par[rollb.top().first] = rollb.top().second.first;
    sz[rollb.top().first] = rollb.top().second.second;
    rollb.pop();
}
