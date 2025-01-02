#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m; cin >> n >> m;

    ll ans = 0;
    ll len = 0;

    vector<string> strings;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        strings.push_back(s);
    }

    for(string s : strings){
        if((len + s.size()) <= m){
            len += s.size();
            ans++;
        }
        else break;
    }

    cout << ans << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
