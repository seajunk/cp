#include <bits/stdc++.h>
typedef long long ll ;
using namespace std;

void solve(){
    ll n; cin >> n;
    ll h[n];
    for(int i = 0; i < n; i++)  cin >> h[i];

    // need prefix max
    // need(?) suffix min
    ll pfmx[n];
    ll sfmn[n];

    pfmx[0] = h[0];
    for(int i = 1; i < n; i++){
        pfmx[i] = max(pfmx[i - 1], h[i]);
    }

    sfmn[n - 1] = h[n - 1];
    for(int i = n - 2; i >= 0; i--){
        sfmn[i] = min(sfmn[i + 1], h[i]);
    }


    ll mxh[n];
    mxh[n - 1] = pfmx[n - 1];
    for(int i = n - 2; i >= 0; i--){
        ll lo = i;
        ll hi = n;

        while(lo < hi){
            ll mid = (hi - lo) / 2 + lo;

            if(sfmn[mid] <= h[i]){
                lo = mid + 1;
            }
            else{
                hi = mid;
            }
        }
        ll j = lo - 1;
        if(j == i) mxh[i] = max(pfmx[i], h[i]);
        else mxh[i] = max(pfmx[i], mxh[j]);
    }

    for(int i = 0; i < n; i++) cout << mxh[i] << ' ';
    cout << '\n';






    // go from right to left
    // mxh[n - 1] = max(h[n - 1], pfmx[n - 1]);
    // mxh[i] = max(pfmx(i), h[i], mxh[largest j such that h[i] > h[j], j > i]);
    //


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
