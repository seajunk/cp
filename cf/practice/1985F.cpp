#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve(){
    // 1 <= # of turns to kill <= ceil(h / min damage per turn) <= (2*10^5)^2
    // binary searchable ? 
    // calculating damage at turn t = O(n) -> do some mod calculations for each a[i]
    // total -> log(4* 10^10) * 2*10^5 // doable?

    ll h, n; cin >> h >> n;
    ll a[n], c[n];
    ll total = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        total += a[i];
    } 
    for(int i = 0; i < n; i++) cin >> c[i];




    ll hi =  200000ll * 200000ll;
    ll lo = 1ll;

    // why is this needed??
    // maybe some funky overlow issue
    if(total >= h){
        cout << 1 << '\n';
        return;
    }

    while(lo < hi){
        ll mid = (hi - lo)/2 + lo;

        // at turn mid, what is total damage

        ll dmg = total;

        for(int i = 0; i < n; i++){
            dmg += a[i] * ((mid - 1ll) / c[i]);
        }

        // want smallest mid st dmg >= h
        if(dmg < h){
            lo = mid + 1;
        }
        else{
            hi = mid;
        }
    }

    cout << lo << '\n';



    // 5 1
    // 2 2

    // turn 1: 2
    // turn 2: 2
    // turn 3: 4




    





}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
