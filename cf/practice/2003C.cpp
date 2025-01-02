#include <bits/stdc++.h>
#define ll long long 
using namespace std;

void solve(){
    ll n;
    string s;
    cin >> n >> s;

    // want to maximize the # of length 3 substrings with 2 or more characers
    // aabbcc -> aab abb bbc bcc aa bb cc
    // aabb

    unordered_map<char, ll> cnt;
    for(int i = 0; i < n; i++){
        if(cnt.find(s[i]) == cnt.end()) cnt[s[i]] = 1;
        else cnt[s[i]]++;
    }




    ll ptr = 0;
    while(ptr < n){
        for(int i = 0; i < 26; i++){
            if(cnt.find('a' + i) != cnt.end()){
                s[ptr] = (char)('a' + i);
                cnt['a' + i]--;
                if(cnt['a' + i] == 0) cnt.erase('a' + i); 
                ptr++;
            }
        }
    }

    cout << s << '\n';















}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
