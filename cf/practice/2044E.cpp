#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll k, l1, r1, l2, r2; cin >> k >> l1 >> r1 >> l2 >> r2;

    ll ans = 0;
    for(int n = 0; n <= 32; n++){

        ll curr = 1;
        ll cnt = 0;
        while(curr * l1 <= 1000000000 && cnt < n){
            curr *= k;
            cnt++;
        }

        if(cnt < n) continue;

        // smallest x for which x*curr in [l2, r2]
        // biggest x for which x*curr in [l2, r2]

        ll lb , ub;
        ll lo, hi;
        lo = l1, hi = r1;

        // lb
        while(lo < hi){
            ll mid = (hi - lo)/2 + lo;


            if(mid * curr < l2) lo = mid + 1;
            else hi = mid;
        }
        lb = lo;

        lo = l1, hi = r1;
        // ub
        while(lo < hi){
            ll mid = (hi - lo)/2 + lo;

            if(mid * curr <= r2) lo = mid + 1;
            else hi = mid;
        }
        ub = lo;
        if(ub * curr > r2) ub--;


        // lb = smallest x st l2 <= xcurr 
        // ub = largest x st xcurr <= r2

        if(lb*curr < l2) continue;
        if(ub*curr > r2) continue;

        
        if(lb <= ub) ans += ub - lb + 1;

    }

    cout << ans << '\n';






    


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
