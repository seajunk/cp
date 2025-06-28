#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;

    string s = "1";

    for(int i = 1; i < n; i++){
        s += "0";
    }

    cout << s << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
