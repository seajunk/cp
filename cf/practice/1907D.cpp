#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll l[n], r[n];
    for(int i = 0; i < n; i++){
        cin >> l[i];
        cin >> r[i];
    }


    // for each i in n, hightlight inteval that we can be at and the interval we need to be at 
    // if the intersection is empty cant work, 

    ll lo = 0, hi = 1000000000;

    while(lo < hi){
        ll mid = (hi - lo)/2 + lo;
        bool valid = true;


        ll lb = 0, ub = 0; // [lb, ub] is current interval 

        // if [lb - mid, ub + mid] disjoint with the ith interval, valid = false

        for(int i = 0; i < n; i++){
            lb -= mid;
            ub += mid;

            // get intersection of [lb, ub] and [l[i], r[i]]
            // if disjoint valid = false, ow set [lb, ub] to intersection

            if(max(lb, l[i]) <= min(ub, r[i])){
                lb = max(lb, l[i]);
                ub = min(ub, r[i]);
            }
            else{
                valid = false;
                break;
            }
        }

        if(valid) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << '\n';






}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
