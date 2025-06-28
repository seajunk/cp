#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// euclidean metric for (a, b), (c, d)
long double dist(ll a, ll b, ll c, ll d){
    return sqrt((a - c)*(a - c) + (b - d)*(b - d));
}

void solve(){
    /*

       a sequence of cells is valid if

       (1) each cell is a hold
       (2) first hold is in first layer
       (3) last hold is in last layer
       (4) each hold is same layer or one layer above previous hold
       (5) hold cant be same layer as previous and next hold
       (6) each hold is at most d apart from next hold


       maybe we have like 
       dp[row, col][0] = # of ways to get to (row, col) as first hold in layer
       dp[row, col][1] = # of ways to get to (row, col) as second hold in layer

       then ans = sum(dp[row, col][0] + dp[row, col][1] : row = 1, (row, col) is a hold)

       with like a directed graph or something where each node is a hold and for holds i, j, edge (i -> j) exists if dist(i, j) <= d and either i and j are same layer or j is one layer above i

       issues
       (1) cycles can form, eg two close holds in same layer can each go from one to the other
       (2) too expensive to have an explicit list of edges


       solutions (?)
       (1) instead of a hold being a node, a hold is two nodes
       one node correpsonds to the hold being the first of its layer, the second corresponds to the hold being the second of its layer.
       if holds i and j both are on the same layer, edge i -> j exists only if i is first and j is second. a hold which is the second of it s layer can only go to holds above it.


       (2) somehow figure out a way to represent graph implicitly ?
       current issue is that, 
       for some hold mountain[i][j], we need to check every hold in 
       mountain[i] and mountain[i + 1] to see if an edge exists.
       this is O(N) per hold -> O(N^3) for whole mountain. N = max(n, m) <= 2000 so too expensive.


       super crackhead idea, represent each row as a lazy segtree and spam range updates ?????
    */

    ll MOD = 998244353;
    ll n, m; cin >> n >> m;
    long double d; cin >> d;

    vector<vector<char>> mountain(n, vector<char>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> mountain[i][j];
    }


    vector<vector<ll>> st(2*n, vector<ll>(2*m, 0));
    vector<vector<ll>> lazy(2*n, vector<ll>(m, 0));
    vector<vector<ll>> sz(2*n, vector<ll>(2*m, 0));

    for(int i = 0; i < 2*n; i++){
        for(int j = 0; j < m; j++) sz[i][j + m] = 1;
        for(int j = m - 1; j > 0; j--) sz[i][j] = sz[i][2*j] + sz[i][2*j+1];
    }
    ll h = 64 - __builtin_clzll(m) - 1; // height of tree ie max distance from root to leaf


    // called with p = leaves only. fixes every node on path from p to root
    auto fix = [&](ll i, ll p){
        for(; p > 1; p /= 2) st[i][p/2] = (st[i][p] + st[i][p^1] + sz[i][p/2]*lazy[i][p/2]) % MOD;
    };

    // apply update to p and update its lazy value if p is internal node
    auto apply = [&](ll i, ll p, ll x){
        st[i][p] += (x * sz[i][p]);
        st[i][p] %= MOD;
        if(p < m) lazy[i][p] += x; 
    };

    // propgates updates for nodes on path from root to p
    auto push = [&](ll i, ll p){
        for(int s = h; s > 0; s--){
            // p >> s is the sth ancestor of p?
            if(lazy[i][p>>s] != 0){
                apply(i, 2*(p>>s), lazy[i][p>>s]);
                apply(i, 2*(p>>s)+1, lazy[i][p>>s]);
                lazy[i][p>>s] = 0;
            }
        }
    };

    auto update = [&](ll i, ll l, ll r, ll x){
        l += m, r += m;
        ll l0 = l, r0 = r;
        for(; l < r; l/=2, r/=2){
            if(l&1) apply(i, l++, x);
            if(r&1) apply(i, --r, x);
        }
        fix(i, l0);
        fix(i, r0 - 1);
    };

    auto query = [&](ll i, ll l, ll r){
        l += m, r += m;
        push(i, l);
        push(i, r - 1);
        ll ans = 0;
        for(; l < r; l/=2, r/=2){
            if(l&1) ans += st[i][l++];
            if(r&1) ans += st[i][--r];
        }
        return ans % MOD;
    };



    // pray to god lazy seg tree was implemented correctly



    /*
       idea is

       # of ways to get to row i - 1 can be determined with # of ways to get to row i and i + n 



    */


    // base case, i = n - 1
    for(int j = 0; j < m; j++){
        if(mountain[n-1][j] == 'X') update(n-1, j, j + 1, 1);
    }


    for(int i = n - 1; i >= 0; i--){
        // assuming st[i] is calculated

        // calculating st[i + n]
        for(int j = 0; j < m; j++){
            if(mountain[i][j] != 'X') continue;

            // there might be some funky trig way to do this in O(1) time but i cant be bothered
            ll leftmost, rightmost; // left most index that we can reach, rightmost index that we can reach
            ll lo, hi;

            // minimize leftmost over [0, j]
            lo = 0, hi = j + 1;
            while(lo < hi){
                ll mid = (hi - lo)/2 + lo;
                if(dist(i, j, i, mid) > d) lo = mid + 1;
                else hi = mid;
            }
            assert(lo != j + 1);
            leftmost = lo;

            // maximize rightmost over [j, m - 1]
            lo = j - 1, hi = m - 1;
            while(lo < hi){
                ll mid = (hi - lo + 1)/2 + lo;
                if(dist(i, j, i, mid) > d) hi = mid - 1;
                else lo = mid;
            }
            assert(lo != j - 1);
            rightmost = lo;

            // (i, j) can reach (i, leftmost) to (i, rightmost)
            //cout << leftmost << ' ' << rightmost + 1 << '\n';

            update(i + n, leftmost, rightmost + 1, query(i, j, j + 1));
            update(i + n, j, j + 1, -1*query(i, j, j + 1)); // hold cant go to it self
        }



        if(i == 0) break;
        // calculating st[i - 1]
        for(int j = 0; j < m; j++){
            if(mountain[i][j] != 'X') continue;

            ll leftmost, rightmost; // left most index that we can reach, rightmost index that we can reach
            ll lo, hi;

            // minimize leftmost over [0, j]
            lo = 0, hi = j + 1;
            while(lo < hi){
                ll mid = (hi - lo)/2 + lo;
                if(dist(i, j, i-1, mid) > d) lo = mid + 1;
                else hi = mid;
            }
            assert(lo != j + 1);
            leftmost = lo;

            // maximize rightmost over [j, m - 1]
            lo = j - 1, hi = m - 1;
            while(lo < hi){
                ll mid = (hi - lo + 1)/2 + lo;
                if(dist(i, j, i-1, mid) > d) hi = mid - 1;
                else lo = mid;
            }
            assert(lo != j - 1);
            rightmost = lo;

            // (i, j) can reach (i, leftmost) to (i, rightmost)

            update(i - 1, leftmost, rightmost + 1, query(i, j, j + 1));
            update(i - 1, leftmost, rightmost + 1, query(i + n, j, j + 1));
        }
    }









    /*
    vector<vector<ll>> first(n, vector<ll>(m, 0));
    vector<vector<ll>> second(n, vector<ll>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mountain[i][j] != 'X') continue;
            first[i][j] = query(i, j, j + 1);
            second[i][j] = query(i + n, j, j + 1);
        }
    }
    for(auto row : first){
        for(auto e : row) cout << e << ' ';
        cout << '\n';
    }
    cout << '\n';

    for(auto row : second){
        for(auto e : row) cout << e << ' ';
        cout << '\n';
    }
    */




    ll ans = 0;
    for(int j = 0; j < m; j++){
        if(mountain[0][j] != 'X') continue;
        ans += query(0, j, j + 1);
        ans += query(n, j, j + 1);
    }

    cout << ans % MOD << '\n';



    /*
       O(n*m*log(m)) n, m <= 2000

       Honestly this was more for practicing implementing lazy segtree than anything else.

    */

}

int main(){

    ll t; cin >> t;
    while(t--) solve();
}
