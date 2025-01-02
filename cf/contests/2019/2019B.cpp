#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n, q; cin >> n >> q;

    ll x[n];
    for(int i = 0; i < n; i++) cin >> x[i];

    unordered_map<ll, vector<vector<ll>>> m;
    ll left = 0;
    for(int i = 1; i < n; i++){
        if(m.find(i*(n - i)) == m.end()) m[i*(n - i)] = {{x[i - 1], x[i]}};
        else m[i*(n - i)].push_back({x[i - 1], x[i]});
    }
    for(int i = 0; i < n; i++){
        ll temp = n - i - 1 + i * (n - i);
        if(m.find(temp) == m.end()) m[temp] = {{x[i]}};
        else m[temp].push_back({x[i]});
    }


    for(int i = 0; i < q; i++){
        ll k; cin >> k;

        if(k == n - 1){
            if(n == 2){
                cout << x[1] - x[0] + 1 << '\n';
            }
            else if(n == 3){
                cout << x[1] - x[0] + 1 + x[2] - x[1] << '\n';
            }
            else{
                cout << x[1] - x[0] + 1 + x[n - 1] - x[n - 2] + 1 << '\n';
            }
        }
        else{
            if(m.find(k) == m.end()){
                cout << 0 << '\n';
            }
            else{
                ll count = 0;
                for(vector<ll> v : m[k]){
                    if(v.size() == 0) count += v[0];
                    else{
                        count += max(v[0], v[1]) - min(v[0], v[1]) - 1;
                    }
                }
                cout << count << '\n';
            }
        }


    }


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
