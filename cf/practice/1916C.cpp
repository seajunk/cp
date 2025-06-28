#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){




    ll n; cin >> n;
    ll a[n];
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }


    ll pfocnt[n + 1];

    pfocnt[0] = 0;
    for(int i = 1; i <= n; i++){
        if(a[i - 1] % 2 != 0) pfocnt[i] = pfocnt[i - 1] + 1;
        else pfocnt[i] = pfocnt[i - 1];
    }

    ll pfsum[n + 1];
    pfsum[0] = 0;
    for(int i = 1; i <= n; i++) pfsum[i] = pfsum[i - 1] + a[i - 1];
    vector<ll> ans(n); 

    for(int i = 1; i <= n; i++){
        if(i == 1) ans[i - 1] = a[i - 1];
        else if(pfocnt[i] % 3 == 0) ans[i - 1] = pfsum[i] - pfocnt[i] / 3; 
        else if(pfocnt[i] % 3 == 1) ans[i - 1] = pfsum[i] - pfocnt[i] / 3 - 1;  
        else ans[i - 1] = pfsum[i] - pfocnt[i] / 3; 
    }


    for(ll e : ans) cout << e << ' ';
    cout << '\n';




}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
