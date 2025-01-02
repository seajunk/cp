#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;

    // conj: p works only if the permutation is monotonic up and down 


    // how many different ways ?

    // 1 2 3 4 5

    // 1 2 3
    // 1 3 2
    // 3 2 1
    // 1 3 2

    // ends must be 1
    // n can be anywhere 
    // 1 ? ? 5 ?
    // 3 choose 2 


    // 1 ... n ... 
    // n - 2 choose distinace between 1 and n









    ll cnt = 1;

    for(int i = 0; i < (n/2); i++){
        cnt *= 2;
        if(cnt >= k) break;
    }

    if(cnt < k){
        cout << -1 << '\n';
        return;
    }

















}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
