#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s, t; cin >> s >> t;


    // need to find char in s[1:] and t[:n-1] such that the len of abbreviation is minimized


    unordered_map<char, ll> cnt_s, cnt_t;

    for(int i = s.size() - 1; i >= 1; i--){
        cnt_s[s[i]] = i;
    }

    ll mn = LLONG_MAX;
    string ans = "-1";


    for(int i = t.size() - 2; i >= 0; i--){
        if(cnt_s.find(t[i]) != cnt_s.end()){
            if((t.size() - 1 - i + cnt_s[t[i]]) > mn) continue;
            mn = t.size() - 1 - i + cnt_s[t[i]];

            ll j = cnt_s[t[i]];
            ans = "";

            for(int l = 0; l <= j; l++){
                ans += s[l];
            }
            for(int l = i + 1; l < t.size(); l++){
                ans += t[l];
            }
        }
    }

    cout << ans << '\n';
}

int main(){
    solve();
}

