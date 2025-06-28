#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;

    string s, t; cin >> s >> t;


    /*
       same logic as easy version ?


       compare the fixed middle section and the free sides 

       works iff fixed middle is identicle to t and free sides have same multiset as t (?)


    */

    set<ll> fixed, free;



    for(ll i = 0; i < n; i++){
        if(i + k >= n && i - k < 0) fixed.insert(i);
        else free.insert(i);
    }


    bool works = true;

    for(auto i : fixed){
        if(s[i] != t[i]){
            cout << "NO\n";
            return;
        }
    }

    multiset<char> a, b;


    for(auto i : free){
        a.insert(s[i]);
        b.insert(t[i]);
    }


    if(a != b){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";





}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
