#include <bits/stdc++.h>
#define ll long long 
using namespace std;

void solve(){
    ll n, k; cin >> n >> k;

    ll cnt = 0;

    // 7, 3
    // 21
    if(k == 1){
        cout << n << '\n';
        return;
    }
    while(n != 0){
        cnt += n % k;
        n  /= k;
    }

    cout << cnt << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
