#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll b[2*n];
    for(int i = 0; i < 2*n; i++) cin >> b[i];

    /*
       a1 = a2 - a3 + a4 - ... + a2n - a2n+1

       (a1 - a2) + (a3 - a4) + ... + (a2n+1 - a2n) = 0 

       a2n = (a1 - a2) + (a3 - a4) + ... + a2n+1
        a6 = (a1 - a2) + (a3 - a4) + a5 + a7 
    */


    sort(b, b + 2*n);


    ll missing = 0;
    vector<ll> ans(2*n + 1);

    ll temp = 0;
    for(int i = 2*n - 1; i >= 2*n - 1 - n ; i--){
        missing += b[i]; 
        ans[temp] = b[i];
        temp += 2;
    }

    temp = 1;
    for(int i = 0; i < n - 1; i++){
        missing -= b[i];
        ans[temp] = b[i];
        temp += 2;
    }

    //cout << "missing = " << missing << '\n';
    ans[2*n - 1] = missing;

    for(auto e : ans) cout << e << ' ';
    cout << '\n';







}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
