#include <iostream>
#include <climits>
#include <map>
#define ll long long 
using namespace std;

void solve(){
    ll n; cin >> n;
    map<ll, ll> h;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll d[n + 1];
    fill(d, d + n + 1, 0);
    for(int i = 0; i < n; i++){
        if(a[i] <= n) d[a[i]] = 1;

        if(h.find(a[i]) == h.end()) h[a[i]] = 1;
        else h[a[i]]++;
    }
    ll mex;
    for(int i = 0; i <= n; i++){
        if(d[i] == 0){
            mex = i;
            break;
        }
    }
    
    bool found = false;
    ll mn2 = LLONG_MAX;

    for(auto pair : h){
        if(pair.second == 1 && !found){
            found = true;
        }
        else if(pair.second == 1 && found){
            mn2 = pair.first;
            break;
        }
    }

    cout << min(mex, mn2) << '\n';




}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

