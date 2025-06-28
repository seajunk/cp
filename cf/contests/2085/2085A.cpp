#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    string s; cin >> s;


    if(k == 0){
        string rev = s;;
        for(int i = 0; i < n; i++) rev[i] = s[n - 1 - i];
        if(s < rev){
            cout << "YES\n";
            return;
        }
        else{
            cout << "NO\n";
            return;
        }

    }

    set<char> cnt;
    for(int i = 0; i < n; i++){
        cnt.insert(s[i]);
    }

    if(cnt.size() == 1){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    return;


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

