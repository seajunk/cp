#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n, m; cin >> n >> m;
    ll h = 0;
    if(m % 2 == 0){
        h = n * (m / 2);
    }
    else if(m % 2 != 0){
        h = n * (m - 1) / 2;
    }

    cout << h << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
