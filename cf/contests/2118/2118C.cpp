#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];


    /*
       beuaty of number is # of 1 in bin rep
       beauty of a is sum of beauty of its elements
       in one operation we can += 1 some elememnt, can perform at most k operations




       += 1 can increase beauty by at most 1, but it can also decrease beauty by a lot

       while k > 0, greedily increase the cheapest guy to increase
    */

    auto cnt = [&](ll a){
        ll ans = 0;
        while(a > 0){
            ans += a%2;
            a /= 2;
        }
        return ans;
    };



    for(ll i = 0; i < 60; i++){
        for(ll j = 0; j < n; j++){
            if((a[j] >> i) % 2 == 0){
                if(k >= (1ll << i)){
                    a[j] |= (1ll << i);
                    k -= (1ll << i);
                }
            }
        }
    }




    ll ans = 0;
    for(int i = 0; i < n; i++) ans += cnt(a[i]);

    cout << ans << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
