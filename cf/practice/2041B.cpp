#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll w, b; cin >> w >> b;


    ll lo = 0, hi = 1000000000;

    while(lo < hi){
        ll mid = (hi - lo)/2 + lo;

        bool valid = false;



        // w + b >= k*(k+1)/2 sufficient for k length triangle formable
        // 

        if((w + b) >= (mid*(mid + 1)/2)) valid = true;



        if(valid) lo = mid + 1; 
        else hi = mid;

    }

    cout << lo - 1 << '\n';




}

int main(){
    ll t; cin >> t;
    while(t--) solve();

}

