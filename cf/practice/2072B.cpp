#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    ll ucnt = 0;
    ll dcnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '-') dcnt++;
        else ucnt++;
    }

    for(int i = 0; i < dcnt/2; i++){
        s[i] = '-';
    }

    for(int i = dcnt/2; i < dcnt/2 + ucnt; i++){
        s[i] = '_';
    }

    for(int i = dcnt/2 + ucnt; i < n; i++){
        s[i] = '-';
    }

    vector<ll> pfcnt(n + 1), sfcnt(n + 1);

    pfcnt[0] = 0;
    for(int i = 1; i < n; i++){
        if(s[i - 1] == '-') pfcnt[i] = pfcnt[i - 1] + 1;
        else pfcnt[i] = pfcnt[i - 1];
    }

    sfcnt[n] = 0;
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == '-') sfcnt[i] = sfcnt[i + 1] + 1;
        else sfcnt[i] = sfcnt[i + 1];
    }

    ll ans = 0;

    for(int i = 0; i < n; i++){
        if(s[i] != '_') continue;

        ans += pfcnt[i] * sfcnt[i];
    }

    cout << ans << '\n';

    


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
