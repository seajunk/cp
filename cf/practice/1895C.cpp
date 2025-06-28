#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    string s[n];
    for(int i = 0; i < n; i++) cin >> s[i];



    // iterate over s[i]

    // case 1: s[i] is ge to other ticket
    // then s[i] compatible with s[j] if
    // s[i] left = s[i] right + s[j]
    // s[i] left - s[i] right = s[j]


    // case2: s[i] is less than other ticket
    // then s[i] compatible with s[j] if
    // s[i] + s[j] left = s[j] right
    // s[i] = s[j] right - s[j] left

    map<ll, map<ll, ll>> cnt1, cnt2;


    for(int i = 0; i < n; i++){
        ll l = s[i].size();

        ll sum = 0;
        for(auto c : s[i]) sum += c - '0';

        if(cnt1[l].find(sum) == cnt1[l].end()) cnt1[l][sum] = 1;
        else cnt1[l][sum]++;









    }








}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
