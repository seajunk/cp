#include <bits/stdc++.h>
#define ll long long
using namespace std;


void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll b[n];
    for(int i = 0; i < n; i++) cin >> b[i];
    ll m; cin >> m;
    ll d[m];
    for(int i = 0; i < m; i++) cin >> d[i];

    bool found = false;
    map<ll, ll> cnt;
    for(int i = 0; i < n; i++){
        if(b[i] == d[m - 1]){
            found = true;
        }
    }
    for(int i = 0; i < m; i++){
        if(cnt.find(d[i]) == cnt.end()) cnt[d[i]] = 1;
        else cnt[d[i]]++;
    }
    if(!found){
        cout << "NO" << '\n';
        return;
    }
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            if(cnt.find(b[i]) == cnt.end() || cnt[b[i]] == 0){
                cout << "NO" << '\n';
                return;
            }
            else{
                cnt[b[i]]--;
            }
        }
    }
    cout << "YES" << '\n';

}


int main(){
    ll t; cin >> t;
    while(t--) solve();
}

