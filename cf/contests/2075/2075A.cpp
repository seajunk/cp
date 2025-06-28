#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;

    // 39 7


    if(n - k <= 0){
        cout << 1 << '\n';
        return;
    }


    cout << ((n - k + (k - 1) - 1) / (k-1) + 1) << '\n';
    return;

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
