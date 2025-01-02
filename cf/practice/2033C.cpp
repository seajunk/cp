#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n]; 
    for(int i = 0; i < n; i++) cin >> a[i];


    // 1 1 2 3 -> 1 2 1 3

    // 2 1 2 2 1 1

    // 2 1 1 2 2 4 -> 2 1 2 1 2 4


    // conj: if arr[0:i] is optimal, optimal is better of flipping/not flipping arr[i] 




    for(int i = 1; i < n/2; i++){
        ll notflip = (a[i] == a[i - 1]) + (a[n - 1 - i] == a[n - 1 - (i - 1)]);
        ll flip = (a[i] == a[n - 1 - (i - 1)]) + (a[n - 1 - i] == a[i - 1]);

        if(flip < notflip){
            a[i] ^= a[n - 1 - i]; // 10 ^ 20
            a[n - 1 - i] ^= a[i]; // 20 ^ 10 ^ 20
            a[i] ^= a[n - 1 - i];
        } 
    }

    ll ans = 0;

    for(int i = 1; i < n; i++){
        if(a[i] == a[i - 1]) ans++;
    }

    cout << ans << '\n';











}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
