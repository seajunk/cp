#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];

    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ans += a[i];
    }

    /*
       get first iteration

       get second iteration to get rid of guys that appear only once after that also arent the last element first iteration

       any iteration after this point will look like right shift
    */

    // make first iteration prefix mad array
    set<ll> seen;
    ll mad = 0;
    for(int i = 0; i < n; i++){
        if(seen.find(a[i]) != seen.end()){
            mad = max(mad, a[i]);
        }
        seen.insert(a[i]);
        a[i] = mad;
        ans += a[i];
    }

    seen.clear();
    mad = 0;

    for(int i = 0; i < n; i++){
        if(seen.find(a[i]) != seen.end()){
            mad = max(mad, a[i]);
        }
        seen.insert(a[i]);
        a[i] = mad;
        ans += a[i];
    }

    /*
       at this point, a[i] will be added to the sum n - 1 - i times?
    */
    for(int i = 0; i < n; i++){
        ans += a[i] * (n - 1 - i);
    }

    cout << ans << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
/*
   after first iteration, array is sorted
   -> after second iteration, any element which appears once in the array while also not being the last element is removed
   -> at this point any iteration looks like a right shift
*/

