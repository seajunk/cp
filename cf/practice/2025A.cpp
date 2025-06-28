#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s, t; cin >> s >> t;

    ll ptr = 0;
    while(ptr < s.size() && ptr < t.size()){
        if(s[ptr] != t[ptr]) break;
        ptr++;
    }


    cout << s.size() + t.size() - max(0ll, ptr - 1)  << '\n';
    

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
