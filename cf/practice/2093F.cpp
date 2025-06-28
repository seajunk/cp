#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m; cin >> n >> m;

    vector<string> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];


    vector<vector<string>> b(m, vector<string>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) cin >> b[i][j];
    }



    vector<bool> seen(n, false);



    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(b[j][i] == a[i]) seen[i] = true;
        }
    }



    for(int i = 0; i < n; i++){
        if(!seen[i]){
            cout << -1 << '\n';
            return;
        }
    }


    ll mx_matches = INT_MIN;



    for(int i = 0; i < m; i++){
        ll matches = 0;
        for(int j = 0; j < n; j++){
            if(b[i][j] == a[j]) matches++;
        }
        mx_matches = max(mx_matches, matches);
    }



    ll ans = n + (n - mx_matches) * 2;

    cout << ans << '\n';






}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
