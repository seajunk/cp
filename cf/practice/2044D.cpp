#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n]; 
    for(int i = 0; i < n; i++) cin >> a[i];

    unordered_set<ll> seen;

    vector<ll> b(n, -1);


    for(int i = 0; i < n; i++){
        if(seen.find(a[i]) == seen.end()){
            b[i] = a[i];
            seen.insert(a[i]);
        }
    }

    ll curr = 1;
    for(int i = 0; i < n; i++){
        if(b[i] == -1){
            while(seen.find(curr) != seen.end()) curr++;
            b[i] = curr;
            seen.insert(curr);
        }
    }

    for(ll e : b) cout << e << ' ';
    cout << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
