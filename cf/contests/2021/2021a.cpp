#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    while(a.size() > 1){
        ll temp = (a[0] + a[1]) / 2;
        
        a.push_back(temp);
        sort(a.begin(), a.end());
        a.erase(a.begin() + 0);
        a.erase(a.begin() + 1);
    }
    cout << a[0] << '\n';

    // 1 4 5 7 8
    // 2 5 7 8
    // 3 7 8
    //





}

int main(){
    ll t; cin >> t; 
    while(t--) solve();
}

