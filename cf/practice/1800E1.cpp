#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    string s, t; cin >> s >> t;

    multiset<char> S, T;

    for(int i = 0; i < n; i++){
        S.insert(s[i]);
        T.insert(t[i]);
    }

    if(S != T){
        cout << "NO\n";
        return;
    }



    // if all trapped guys of s and t are the same, then yes, otherwise no ?

    // 0 1 2 3 4
    //     

    for(int i = 0; i < n; i++){
        if(i < 3 && n - 1 - i < 3){
            if(s[i] != t[i]){
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
    return;

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
