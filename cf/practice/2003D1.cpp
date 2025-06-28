#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n, m; cin >> n >> m;

    vector<vector<ll>> a(n);


    for(int i = 0; i < n; i++){
        ll l; cin >> l;

        for(int j = 0; j < l; j++){
            ll in; cin >> in;
            a[i].push_back(in);
        }
    }


    /*
       n <= 10^5
       sum(l) <= 10^5

       each a[i] can send x to max(second mex of a, x)

       then find the largest second mex = mxmex2 in a.

       then answer is 
       maxmex2 * (min(m, mxmex2) + 1) + ((mxmex2 + 1) + ... + m)
       ?
    */

    ll mxmex2 = LLONG_MIN;
    for(int i = 0; i < n; i++){
        ll length = a[i].size();

        vector<bool> seen(length + 2, false);
        for(int j = 0; j < length; j++){
            if(!(0 <= a[i][j] && a[i][j] <= length + 1)) continue;
            seen[a[i][j]] = true;
        }
        ll mex1 = -1, mex2 = -1;
        for(int j = 0; j < length + 2; j++){
            if(!seen[j]){
                if(mex1 == -1){
                    mex1 = j;
                }
                else{
                    mex2 = j;
                    break;
                }
            }
        }
        //cout << mex1 << ' ' << mex2 << '\n';

        mxmex2 = max(mxmex2, mex2);
    }

    ll first = mxmex2 * (min(mxmex2, m) + 1);  
    ll second = max(0ll, (m*(m + 1)/2) - (mxmex2 * (mxmex2 + 1)/2));
    ll ans = first + second;

    //cout << first << ' ' << second << '\n';
    cout << ans << '\n';




}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

/*
   each row lets us send any number x to max(x, second mex) 
   -> then were interested in the largest second mex in the whole array
   -> then for each 0, 1, ..., m, it gets mapped to max(max second mex, i)
   -> sum it up
*/
