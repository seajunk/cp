#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
    ll n, m; cin >> n >> m;
    map<ll, ll> a;
    ll b[m];
    for(int i = 0; i < n ; i++){
        ll in; cin >> in;
        if(a.find(in) == a.end()) a[in] = 1;
        else a[in]++;
    }
    for(int i = 0; i < m ; i++) cin >> b[i];

    /*
       1 2 2 2
       3 4


       bool possible(ll x){

       if(x == 1){
       return a has 1
       }

       if(a has x) return true


       return possible(x/2) and possible(x/2 + x%2)


       }
    */

    function<bool(ll)> possible = [&](ll x){

        if(x == 1){

            if(a.find(1) != a.end()){
                a[1]--;
                if(a[1] == 0) a.erase(1);
                return true;
            }
            return false;
        }

        if(a.find(x) != a.end()){
            a[x]--;
            if(a[x] == 0) a.erase(x);
            return true;
        }
        return possible(x/2) && possible(x/2 + x%2);
    };


    bool ans = true;

    // might tle? 
    for(int i = 0; i < m; i++) ans &= possible(b[i]);

    if(a.size()) ans = false;

    if(ans) cout << "YES\n";
    else cout << "NO\n";
    return;
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}



