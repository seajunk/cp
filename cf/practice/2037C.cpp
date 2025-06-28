#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    /*
       want permutation of length n such that p[i] + p[i + 1] is composite for each i /in [0, n]
    */

    ll n; cin >> n;

    if(n < 5){
        cout << -1 << '\n';
        return;
    }


    vector<ll> ans;
    // ... 4 5 ... 

    for(int i = (n + 1) / 2; i > 3; i--){
        ans.push_back(2 * i - 1);
    }
    ans.push_back(1);
    ans.push_back(3);
    ans.push_back(5);

    ans.push_back(4);
    ans.push_back(2);
    for(int i = 3; i <= n/2 ;i++){
        ans.push_back(2 * i);
    }

    for(ll e : ans) cout << e << ' ';
    cout << '\n';






}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
