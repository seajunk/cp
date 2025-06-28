#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k, p; cin >> n >> k >> p;

    if(n*p < abs(k)){
        cout << -1 << '\n';
        return;
    }
    else{
        cout << (abs(k) + p - 1) / p << '\n';
    }

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
