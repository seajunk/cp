#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;

    // key O: fib like sequence grows exponential. so if kth term is supposed to be n then there can only be log(n) terms in the sequence. 

    // iterate over k-1 value. for each value, at most logn checks happen so nlogn?


    ll ans = 0;

    
    for(int i = 0; i <= n; i++){
        ll second = n;
        ll first = i;

        // ... curr first second ...

        // loop should run at most logn times
        // if the sequence valid then the loop should run logn times
        // if the sequence is invalid then the loop should terminate after at most logn iterations ?

        bool valid = true;
        for(int j = 0; j < k - 2; j++){
            ll curr = second - first;


            valid &=  curr <= first;
            valid &=  curr >= 0;
            if(!valid) break;
            second = first;
            first = curr;
        }
        if(valid) ans++;
    }
    cout << ans << '\n';
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
