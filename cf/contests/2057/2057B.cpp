#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    map<ll, ll> cnt;

    for(int i = 0; i < n; i++){
        if(cnt.find(a[i]) == cnt.end()) cnt[a[i]] = 1;
        else cnt[a[i]]++;
    }

    vector<ll> temp;

    for(auto it = cnt.rbegin(); it != cnt.rend(); it++){
        temp.push_back(it->second);
    }

    sort(temp.begin(), temp.end());

    ll idx = 0;
    while(idx < n && temp[idx] <= k){
        k -= temp[idx];
        idx++;
    }

    cout << max((ll)cnt.size() - idx, 1ll) << '\n';




}

int main(){
    ll t; cin >> t ;
    while(t--) solve();
}
