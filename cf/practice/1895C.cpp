#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    string s[n];
    for(int i = 0; i < n; i++) cin >> s[i];


    // conj: two tickets work => they have same length parity
    
    // for some fixed s[i], s[j] will work with s[i] if 
    // case same len: works iff same sum
    // case s[i] > s[j]: sum of s[j] + sum of some prefix of s[i] = some suffix of s[i] or sum of s[j] + some suffix of s[i] = some prefix of s[i]
    // case s[i] < s[j]: analogous to above



    // 13 2123 -> 132 123
    // 2123 13 -> 212 313 

    // 22 2222 -> 222 222
    // 2222 22 -> 222 222


    // fact: strings are at most len 5
    // for each s[i], iterate through each 1 <= j <= 5
    // for each j witih same parity as len(s[i]), find the count of string s[j] of length m for which 









}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
