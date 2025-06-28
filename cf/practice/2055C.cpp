#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m; cin >> n >> m;
    string s; cin >> s;
    vector<vector<ll>> a(n, vector<ll>(m));

    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++) cin >> a[r][c];
    }

    // pick any arbitrary target sum
    // if next guy is down, fix row 
    // if next guy is right, fix column
    // last row & column should have same sum so last guy is trivial

    // 0 2 3
    // 0 0 0
    // 3 1 0

    // 5 2 3
    // 2 7 1
    // 3 1 6

    vector<ll> rowsum(n, 0);
    vector<ll> colsum(m, 0);
    for(int r = 0; r < n; r++){
        ll sum = 0;
        for(int c = 0; c < m; c++) sum += a[r][c];
        rowsum[r] = sum;
    }
    for(int c = 0; c < m; c++){
        ll sum = 0;
        for(int r = 0; r < n; r++) sum += a[r][c];
        colsum[c] = sum;
    }

    ll target = 0; 
    ll r = 0, c = 0; // current row, column

    for(int i = 0; i < n + m - 2; i++){
        if(s[i] == 'D'){
            ll needed = target - rowsum[r]; 
            a[r][c] = needed;
            rowsum[r] += needed;
            colsum[c] += needed;
            r++;
        }
        if(s[i] == 'R'){
            ll needed = target - colsum[c];
            a[r][c] = needed;
            rowsum[r] += needed;
            colsum[c] += needed;
            c++;
        }
    }

    ll needed = target - rowsum[n - 1];
    a[n - 1][m - 1] = needed;

    cout << '\n';

    for(auto row : a){
        for(auto e : row) cout << e << ' ';
        cout << '\n';
    }






}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
