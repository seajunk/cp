#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k, q; cin >> n >> k >> q;

    vector<vector<ll>> a(n, vector<ll>(k));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++) cin >> a[i][j];
    }

    /*
       just do binary search?
    */



    for(int i = 1; i < n; i++){
        for(int j = 0; j < k; j++){
            a[i][j] |= a[i - 1][j];
        }
    }

    for(int i = 0; i < q; i++){
        ll m; cin >> m;
        ll lb = 0, ub = n;

        for(int j = 0; j < m; j++){
            ll r; cin >> r; r--;
            char o; cin >> o;
            ll c; cin >> c;
            /*
               figure out the interval for which the condition is satisfied
               then shrink [lb, ub) accordingly
            */
            if(o == '<'){
                // want countries with region r st; < c
                // this should decrease the upper bound
                ll lo = -1, hi = n - 1;
                while(lo < hi){
                    ll mid = (hi - lo + 1)/2 + lo;
                    if(a[mid][r] < c) lo = mid;
                    else hi = mid - 1;
                }
                ub = min(ub, lo + 1);
            }
            else if(o == '>'){
                // want countries with region r st > c
                // this should increase the lower bound
                ll lo = 0, hi = n;
                while(lo < hi){
                    ll mid = (hi - lo)/2 + lo;
                    if(a[mid][r] > c) hi = mid;
                    else lo = mid + 1;
                }
                lb = max(lb, lo);
            }
            else assert(false);
        }


        if(lb >= ub) cout << -1 << '\n'; 
        else cout << (lb + 1) << '\n';






    }



}

int main(){
    solve();
}
