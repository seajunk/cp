#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    string s; cin >> s;

    map<char, ll> cnt;

    for(int i = 0; i < n; i++){
        if(cnt.find(s[i]) == cnt.end()) cnt[s[i]] = 1;
        else cnt[s[i]]++;
    }

    if(n == 1){
        cout << s << '\n';
        return;
    }


    char mxchar;
    char mnchar;
    ll mn = LLONG_MAX;
    ll mx = LLONG_MIN;

    for(int i = 0; i < n; i++){
        if(cnt[s[i]] > mx){
            mxchar = s[i];
            mx = cnt[s[i]];
        }
    }
    for(int i = 0; i < n; i++){
        if(cnt[s[i]] < mn && s[i] != mxchar){
            mnchar = s[i];
            mn = cnt[s[i]];
        }
    }


    for(int i = 0; i < n; i++){
        if(s[i] == mnchar){
            s[i] = mxchar;
            break;
        }
    }

    cout << s << '\n';
    return;


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
