#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;


    vector<ll> a(n);




    ll positives = 0;
    ll ub = 0;

    for(int add = n; ub < k; add--){
        positives += 1;
        ub += add;
    }



    ll remainder = ub - k;



    for(int i = 0; i < n; i++){
        if(i < positives - 1) a[i] = 1000;
        else if(i == positives - 1){
            // n - positives - ub + 1
            ll need = n - positives - remainder + 1;
            a[i] = 2*need - 1;

        }
        else a[i] = -2;
    }


    for(int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << '\n';






}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
