#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m, k; cin >> n >> m >> k;

    char g[n][m];
    ll gold_cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
            if(g[i][j] == 'g') gold_cnt++;
        }

    }





    /*
       iterate over all places we can place a tnt

       idea is, the first explosion is the only time where we might need to destroy gold ore, every subsequent explosion can be positioned so that no gold ore is strictly inside the explosion

       for each position, count how many gold ore is destroyed
       answer is # of gold ore - min # of ore destroyed ?

       O(n*m*k*k) if we iterate over all squares in explosion radius
       we could speed up with like prefix sum or something for range sum query over grid
    */



    ll pfs[n + 1][m + 1];
    for(int j = 0; j <= m; j++) pfs[0][j] = 0;
    for(int i = 0; i <= n; i++) pfs[i][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) pfs[i][j] = pfs[i - 1][j] + (g[i - 1][j - 1] == 'g');
    }
    for(int j = 1; j <= m; j++){
        for(int i = 1; i <= n; i++) pfs[i][j] += pfs[i][j - 1];
    }



    ll mn = INT_MAX;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] != '.') continue;
            /*
               want # of gold destroyed by detonating at (i, j)
               so interested in range [i - (k - 1), i + (k - 1)] X [j - (k - 1), j + (k - 1)]
            */

            ll a, b, c, d;
            a = max(0ll, i - (k - 1));
            b = max(0ll, j - (k - 1));
            c = min(n, i + k);
            d = min(m, j + k);
            ll cnt = pfs[c][d] + pfs[a][b] - pfs[c][b] - pfs[a][d];
            mn = min(mn, cnt);
        }
    }
    assert(mn != INT_MAX);

    cout << gold_cnt - mn << '\n';



















}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
