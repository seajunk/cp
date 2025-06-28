#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m; cin >> n >> m;
    ll a[m];
    for(int i = 0; i < m ; i++) cin >> a[i];
    sort(a, a + m);

    vector<vector<ll>> schedule(n, vector<ll>(6));

    for(int i = 0; i < (n + 1)/2; i++){

        ll first = i;
        ll second = n - 1 - i;


        for(int j = 0; j < 6; j++){
            if(j%2 == 0) schedule[first][j] = a[i];
            else schedule[first][j] = a[m - 1 - i];
        }
        for(int j = 0; j < 6; j++){
            if(j%2 == 1) schedule[second][j] = a[i];
            else schedule[second][j] = a[m - 1 - i];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 6; j++) cout << schedule[i][j] << ' ';
        cout << '\n';
    }




}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
