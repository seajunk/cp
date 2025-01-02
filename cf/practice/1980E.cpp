#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m; cin >> n >> m;
    ll a[n][m], b[n][m];

    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            cin >> a[r][c];
        }
    }

    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            cin >> b[r][c];
        }
    }

    set<pair<set<ll>, ll>> acnt, bcnt;

    for(int r = 0; r < n; r++){
        set<ll> arow;
        set<ll> brow;
        for(int c = 0; c < m; c++){
            arow.insert(a[r][c]);
            brow.insert(b[r][c]);
        }
        acnt.insert({arow, 1});
        bcnt.insert({brow, 1});
    }
    for(int c = 0; c < m; c++){
        set<ll> acol, bcol;
        for(int r = 0; r < n; r++){
            acol.insert(a[r][c]);
            bcol.insert(b[r][c]);
        }
        acnt.insert({acol, 0});
        bcnt.insert({bcol, 0});
    }

    if(acnt == bcnt) cout << "YES\n";
    else cout << "NO\n";



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
