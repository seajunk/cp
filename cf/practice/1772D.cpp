#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    /*
       want to find x such that {|a[0] - x|, ..., |a[n - 1] - x|} is non decreasing

       if we choose x such that a[i] >= x for all i then sortedness doesnt change, if a[i] < x for all i then sortedness is reversed



       12345

    */




    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    ll lo = 0, hi = 1000000000;
    // x in [lo, hi]

    for(int i = 1; i < n; i++){
        if(a[i] > a[i - 1]) hi = min(hi, a[i - 1] + (a[i] - a[i - 1])/2); 
        else if(a[i] < a[i - 1]) lo = max(lo, a[i] + (a[i - 1] - a[i] + 1)/2); 
    }

    if(lo <= hi){
        cout << lo << '\n';
        return;
    }
    cout << -1 << '\n';
    return;
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
