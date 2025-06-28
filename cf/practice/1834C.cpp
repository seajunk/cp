#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

void solve(){
    ll n; cin >> n;
    string s, t; cin >> s >> t;
    string rev = s;

    for(int i = 0; i < n/2; i++) swap(rev[i], rev[n - 1 - i]);

    ll d1 = 0, d2 = 0;

    for(int i = 0; i < n; i++){
        if(s[i] != t[i]) d1++;
    }

    for(int i = 0; i < n; i++){
        if(rev[i] != t[i]) d2++;
    }

    // 1 -> 0
    // 2 -> 1, flip, 0, flip
    // 3 -> 2, flip, 1, flip, 0
    // 4 -> 3, flip, 2, flip, 1, flip, 0, flip
    // 5 -> 4, flip, 3, flip, 2, flip, 1, flip, 0
    if(d1 == 0){
        cout << 0 << '\n';
        return;
    }
    ll ans1 = d1 + (d1/2)*2;
    ll ans2 = d2 + ((d2 + 1)/2)*2 - 1;
    cout << min(ans1, max(2ll, ans2)) << '\n';
    

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

