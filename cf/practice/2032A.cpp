#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n; cin >> n;
    ll on = 0;
    for(int i = 0; i < 2*n; i++){
        ll in; cin >> in;
        if(in == 1) on++;
    }

   cout << (on % 2) << ' ' << (on <= n ? on : n - (on - n)) << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
