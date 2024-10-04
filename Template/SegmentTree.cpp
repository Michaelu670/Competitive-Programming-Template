// Change this!
const int NMAX = 200005;

struct Node {
    int val;
    int lazy;

    Node(int val = 0, int lazy = 0): val(val), lazy(lazy) {}
};
const Node ZERO = Node(0, 0);
Node merge(Node a, Node b) {
    return Node(a.val + b.val);
}
Node seg[NMAX * 4];


void pushLazy(int idx, int l, int r) {
    if (!seg[idx].lazy) {
        return;
    }
    int mid = (l + r) / 2, lc = idx * 2, rc = idx * 2 + 1;
    
    seg[lc].lazy += seg[idx].lazy;
    seg[rc].lazy += seg[idx].lazy;
    seg[lc].val += seg[idx].lazy * (mid - l + 1);
    seg[rc].val += seg[idx].lazy * (r - mid);

    seg[idx].lazy = 0;
}


Node query(int idx, int l, int r, int x, int y) {
    if (l > y || x > r) return ZERO;
    if (x <= l && r <= y) return seg[idx];
    int mid = (l + r) / 2, lc = idx * 2, rc = idx * 2 + 1;
    pushLazy(idx, l, r);

    return merge(query(lc, l, mid, x, y), query(rc, mid+1, r, x, y));   
}

Node query(int x, int y, int n) {
    return query(1, 0, n-1, x, y);
    // return query(1, 1, n, x, y);
}

void update(int idx, int l, int r, int x, int y, int v) {
    if (l > y || x > r) return;
    if (x <= l && r <= y) {
        seg[idx].val += v * (r - l + 1);
        seg[idx].lazy += v;
        return;
    }
    int mid = (l + r) / 2, lc = idx * 2, rc = idx * 2 + 1;
    pushLazy(idx, l, r);

    update(lc, l, mid, x, y, v);
    update(rc, mid+1, r, x, y, v);
    seg[idx] = merge(seg[lc], seg[rc]);
}

void update(int x, int y, int v, int n) {
    update(1, 0, n-1, x, y, v);
    // update(1, 1, n, x, y, v);
}

