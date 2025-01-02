#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    

    unordered_set<char> cnt;
    for(int i = 0; i < n; i++){
        if(cnt.find(s[i]) == cnt.end()) cnt.insert(s[i]);
    }

    ll m = n - cnt.size();
    cout << (n * (n + 1) / 2 - (m * (m  + 1) / 2)) << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}


