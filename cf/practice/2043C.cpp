#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    /*
       at most one value x in a is not 1 or -1

       get all possible sums of subarrays of a

       n <= 200000




       first check if x exists


       if x doesnt exist,
       return all values from min subarray sum to max subarray sum

       if x exists,
       let a[k] = x
       a subarray either contains x or doesnt contain x

       all sums of subarrays can be obtained by gettiing
       max subarray sum of a[0, k) and a[k + 1, n)

       all sums of subarrays can be obtained by calculating
       maximum and minimum on subarrays of the forms
       [j, k), [k + 1, j)
    */

    auto subarray_max = [&](ll l, ll r){
        ll mx = 0;
        ll curr = 0;
        for(int i = l; i < r; i++){
            if(a[i] + curr > a[i]) curr = curr + a[i]; 
            else curr = a[i];
            mx = max(mx, curr);
        }
        return mx;
    };
    auto subarray_min = [&](ll l, ll r){
        ll mn = 0;
        ll curr = 0;
        for(int i = l; i < r; i++){
            if(a[i] + curr < a[i]) curr = curr + a[i]; 
            else curr = a[i];
            mn = min(mn, curr);
        }
        return mn;
    };


    ll k = -1;

    for(int i = 0; i < n; i++){
        if(a[i] != 1 && a[i] != -1){
            k = i;
            break;
        }
    }

    if(k == -1){
        ll mn = subarray_min(0, n);
        ll mx = subarray_max(0, n);
        cout << mx - mn + 1 << '\n';
        for(int i = mn; i <= mx; i++) cout << i << ' ';
        cout << '\n';
        return;
    }


    set<ll> ans;
    ll mn, mx;

    mn = subarray_min(0, k);
    mx = subarray_max(0, k);
    for(int i = mn; i <= mx; i++) ans.insert(i);
    mn = subarray_min(k + 1, n);
    mx = subarray_max(k + 1, n);
    for(int i = mn; i <= mx; i++) ans.insert(i);


    ll mnl = 0, mxl = 0;
    ll curr = 0;
    for(int i = k - 1; i >= 0; i--){
        curr += a[i];
        mnl = min(mnl, curr);
        mxl = max(mxl, curr);
    }

    ll mnr = 0, mxr = 0;
    curr = 0;
    for(int i = k + 1; i < n; i++){
        curr += a[i];
        mnr = min(curr, mnr);
        mxr = max(curr, mxr);
    }

    for(int i = mnl + mnr + a[k]; i <= mxl + mxr + a[k]; i++) ans.insert(i);

    cout << ans.size() << '\n';
    for(auto e : ans) cout << e << ' ';
    cout << '\n';















}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
