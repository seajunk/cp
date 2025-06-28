#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    string s; cin >> s;

    ll pcnt = 0;
    ll scnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'p') pcnt++;
        if(s[i] == 's') scnt++;
    }

    if(pcnt == 0 || scnt == 0){
        cout << "YES\n";
        return;
    }

    if(pcnt > 1 && scnt > 1){
        cout << "NO\n";
        return;
    }

    if(pcnt == 1 && scnt == 1){
        if(s[n - 1] != 'p' && s[0] != 's') cout << "NO\n";
        else cout << "YES\n";
        return;
    }

    if(pcnt == 1){
        if(s[n - 1] == 'p') cout << "YES\n";
        else cout << "NO\n";
        return;
    }

    if(scnt == 1){
        if(s[0] == 's') cout << "YES\n";
        else cout << "NO\n";
        return;
    }














}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
