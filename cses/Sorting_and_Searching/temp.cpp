#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, x; cin >> n >> x;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    ll lo = 0, hi = n;

    // ans \in [lo, hi]
    // how to be sure search space decreases each iteration?
    while(lo < hi){
        ll m = lo + (hi - lo) / 2;
        // lo <= m < hi


        if(a[m] == x){
            // ans \in [lo, m]
            hi = m;
        }
        else if(a[m] < x){
            // ans \in (m, hi]
            lo = m + 1;
        }
        else if(a[m] > x){
            // ans \in [lo, m]
            hi = m;
        }
    }



    cout << lo << '\n';




}
