#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve(){
    ll n, k, q; cin >> n >> k >> q;
    ll a[k + 1], b[k + 1];
    a[0] = 0;
    b[0] = 0;
    for(int i = 1; i <= k; i++) cin >> a[i];
    for(int i = 1; i <= k; i++) cin >> b[i];


    for(int i = 0; i < q; i++){
        ll d; cin >> d;

        /*
           want to know when car gets to d in minutes rounded down

           binary search largest i such that a[i] <= d. 
           -> then get distance from a and d and the speed that car is travelling between a[i] and a[i + 1]
           -> then add to b[i] the amount of distance / speed
        */

        ll lo = -1, hi = k;
        while(lo < hi){
            ll mid = (hi - lo + 1)/2 + lo;
            if(a[mid] <= d) lo = mid;
            else hi = mid - 1;
        }
        if(lo == -1){
            cout << "shit went wrong\n";
            return;
        }
        
        ll distance = d - a[lo];

        if(distance == 0){
            cout << b[lo] << '\n';
            continue;
        }

        // d / s = d / (d / t) = d * (t / d)
        ll time = distance * (b[lo + 1] - b[lo]);
        time /= a[lo + 1] - a[lo];

        cout << b[lo] + time << '\n';

    }

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
