#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m, k; cin >> n >> m >> k;
    string s; cin >> s; 

    ll ans = 0; 
    ll curr = 0; 
    for(int i = 0; i < n;){
        if(s[i] == '0') curr += 1; 
        else curr = 0; 

        if(curr == m){
            ans += 1;
            curr = 0;
            i += k;
        }
        else i += 1;
    }

    cout << ans << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

