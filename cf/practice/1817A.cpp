#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, q; cin >> n >> q;

    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    /*
       each query of form [l, r]
       response is max length of almost increasing ss in a[l, r]


       almost increase := there does not exist three consec x >= y >= z

    */



    vector<vector<ll>> segments; // partitions array into decreasing segments of form [i, j)


    vector<ll> curr(2, -1);
    curr[0] = 0;


    for(int i = 1; i <= n; i++){
        if(i == n || a[i] > a[i - 1]){
            curr[1] = i;
            segments.push_back(curr);
            curr = {i, -1};
        }
        else{
            continue; // ?
        }
    }



    ll m = segments.size();

    ll pfs[m + 1]; 
    pfs[0] = 0;
    for(int i = 1; i <= m; i++) pfs[i] = pfs[i - 1] + min(2ll, segments[i - 1][1] - segments[i - 1][0]);

    for(int qs = 0; qs < q; qs++){
        ll l, r; cin >> l >> r;
        l--;
        r--;


        /*
           binary search for i and j such that segments[i] contains l and segments[j] contains r

           then answer to query is 

           if(i == j){
           cout << min(2ll, r + 1 - l) << '\n';
           }
           else{
           cout << (pfs[j] - pfs[i + 1]) + min(2ll, segment[i][1] - l) + min(2ll, r + 1 - segment[j][0]) << '\n';
           }

        */

        ll i, j;
        ll lo, hi;

        // maximizing i in [0, m - 1] such that segments[i][0] <= l
        lo = -1, hi = m - 1;
        while(lo < hi){
            ll mid = (hi - lo + 1)/2 + lo;
            if(segments[mid][0] <= l) lo = mid;
            else hi = mid - 1;
        }
        assert(lo != -1);
        i = lo;

        // minimizing j in [0, m - 1] such that r < segments[j][1]
        lo = 0, hi = m;
        while(lo < hi){
            ll mid = (hi - lo)/2 + lo;
            if(r < segments[mid][1]) hi = mid;
            else lo = mid + 1;
        }
        assert(lo != m);
        j = lo;

        if(i == j){
            cout << min(2ll, r + 1 - l) << '\n';
        }
        else{
            cout << (pfs[j] - pfs[i + 1]) + min(2ll, segments[i][1] - l) + min(2ll, r + 1 - segments[j][0]) << '\n';
        }
    }
    return;
}

int main(){
    solve();
}
