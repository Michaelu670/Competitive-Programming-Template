#include <bits/stdc++.h>
#include "../Template/DSU.cpp"

using namespace std;

#define int long long
#define forn(i,n) for(int i = 0; i <(int)n; ++i)
#define vi vector<int>
#define debug(x)    cout << #x << " : " << x << endl;

const int MOD = 1000000007;
//const int MOD = 998244353;

void solve() {
    init();
    forn(i, 100000) assert(par[i] == i && "Initial par value is correct");
    forn(i, 100000) assert(sz[i] == 1 && "Initial size is correct");

    assert(isSame(1, 1) == true && "Same element is in the same group");
    assert(isSame(1, 2) == false && "Different element initially in the different group");

    merge(1, 2);
    merge(2, 3);
    merge(3, 4);
    assert(sz[getpar(3)] == 4 && "Size correct after update");
    assert(isSame(1, 3) == true && "Same group after update");
    
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