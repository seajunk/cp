#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n, x; cin >> n >> x;
    ll a[n];
    unordered_map<ll, ll> cnt;
    set<ll> seen;
    ll duplicate = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];

        if(cnt.find(a[i]) == cnt.end()) cnt[a[i]] = 1;
        else cnt[a[i]]++;


        if(seen.find(a[i]) == seen.end()) seen.insert(a[i]);
        else{
            duplicate++;
        }
    }

    // mex is in range [0, m]
    ll m = n + duplicate;

    vector<bool> has(m + 1, false);

    for(int i = 0; i < n; i++){
        if(a[i] <= m) has[a[i]] = true;
    }

    vector<ll> missing;

    for(int i = 0; i <= m; i++){
        if(!has[i]) missing.push_back(i);
    }

    for(int i = 0; i < missing.size(); i++){
        if(x > missing[i]){
            cout << i << '\n';
        }




    }










}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

