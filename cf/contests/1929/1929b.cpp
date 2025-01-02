#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll f(ll k, ll n){
    if(k <= 4 * n - 4){
        // return smallest i such that 2 * i >= k
        return (k + 1) / 2;
    }
    else if(k == ((4 * n) - 3)) return 2 * n - 1;
    else return 2 * n;
}


void solve(){
    ll n, k; cin >> n >> k;


    cout << f(k, n) << '\n';


    

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}



