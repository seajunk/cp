#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m; cin >> n >> m;

    ll w[m], l[m], h[m];

    for(int i = 0; i < m; i++){
        cin >> w[i] >> l[i] >> h[i];
    }


    ll f[n];

    f[0] = 1;
    f[1] = 2;

    for(int i = 2; i < n; i++) f[i] = f[i - 1] + f[i - 2];




    vector<bool> works(m, false);


    for(int i = 0; i < m; i++){


        ll a = f[n - 1];
        ll b = f[n - 1];
        ll c = f[n - 1] + f[n - 2];

        vector<ll> have = {w[i], l[i], h[i]};
        vector<ll> need = {a, b, c};

        sort(have.begin(), have.end());
        sort(need.begin(), need.end());

        bool works = true;
        for(int j = 0; j < 3; j++){
            if(have[j] < need[j]) works = false;
        }


        cout << works;
    }

    cout << '\n';






}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}


