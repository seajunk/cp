#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    string s; cin >> s;


    if(s[0] == '1' || s[n - 1] == '1'){
        cout << "Yes\n"; 
        return;
    }

    // bob gets n/2 turns; 
    // each turn bob can effectively delete a 1 next to a zero
    // each turn alice can effectively block a side of 1 to get attacked from


    bool works = false;

    for(int i = 1; i < n; i++){
        if(s[i] == '1' && s[i - 1] == '1') works = true;
    }

    if(works) cout << "YES\n";
    else cout << "NO\n";






}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
