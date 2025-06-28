#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    /*
       given string s, want to find non-empty substring p of s such that the number of distinct substrings of p is even.

       if string has two consecutive equal characters, good
       if string has three consecutive distinct characters, good 
       if neither of the above conditions hold then string looks like

       ababababab...

       two characters alternating. note this will always result in odd number of substrings. 
    */

    string s; cin >> s;
    ll n; n = s.size();

    for(int i = 1; i < n; i++){
        if(s[i] == s[i - 1]){
            cout << s[i - 1] << s[i] << '\n';
            return;
        }
    }

    for(int i = 2; i < n; i++){
        set<char> curr;
        curr.insert(s[i]);
        curr.insert(s[i - 1]);
        curr.insert(s[i - 2]);
        if(curr.size() == 3){
            cout << s[i - 2] << s[i - 1] << s[i] << '\n';
            return;
        }
    }

    cout << -1 << '\n';
    return;
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
