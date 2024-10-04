#include <bits/stdc++.h>
#include "../Template/SegmentTree.cpp"

using namespace std;

#define int long long
#define forn(i,n) for(int i = 0; i <(int)n; ++i)
#define vi vector<int>
#define debug(x)    cout << #x << " : " << x << endl;

const int MOD = 1000000007;
//const int MOD = 998244353;



void solve() {
    int n = 100000;
    assert(query(0, 30, n).val == 0 && "Initial value is zero");

    update(10, 100, 5, n);

    assert(query(0, 50, n).val == 205 && "Value after update is correct");

    update(0, 100, -5, n);

    assert(query(0, 50, n).val == -50 && "Value after negative update is correct");

    cout << "OK: ALL TEST PASSED!" << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int tc = 1;
    // cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}