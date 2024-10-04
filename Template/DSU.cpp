#include <algorithm>
// DSU With Path Compression and Rank Compression

const int NMAX = 200005;

int par[NMAX];
int sz[NMAX];

int getpar(int x) {
    if (par[x] == x) return x;
    return par[x] = getpar(par[x]);
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

    par[v] = u;
    sz[u] += sz[v];
}
