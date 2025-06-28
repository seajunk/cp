#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    set<ll> s;
    for(int i = 0; i < n; i++){
        ll in; cin >> in;
        s.insert(in);
    }

    ll mex = 0;
    while(s.find(mex) != s.end()) mex++;

    cout << mex << '\n';
    s.insert(mex);
    cout.flush();
    ll y; cin >> y;

    while(y != -1){
        cout << y << '\n';
        cout.flush();
        cin >> y;
    }




}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

