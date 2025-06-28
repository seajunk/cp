#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 10^x
ll pow10(ll x){
    if(x == 0) return 1;
    ll half = pow10(x/2);
    if(x % 2 == 0) return half * half;
    else return half * half * 10;
}


ll cnt(ll k){
    ll digits = 0;
    ll temp = k;
    while(temp > 0){
        temp /= 10;
        digits++;
    }


    vector<ll> dp(digits);
    dp[0] = 0;
    for(int i = 1; i < digits; i++) dp[i] = dp[i - 1] * 9 + pow10(i - 1); 



    ll cnt = 0;
    while(digits > 0){
        // digits = # of digits in value we are currently considering


        ll leading = (k / pow10(digits - 1)) % 10;


        if(leading < 4){
            cnt += dp[digits - 1] * leading;
        }
        else if(leading == 4){
            cnt += dp[digits - 1] * leading + k % pow10(digits - 1) + 1;
            break;
        }
        else{
            cnt += dp[digits - 1] * (leading - 1) + pow10(digits - 1);
        }
        digits--;
    }
    return cnt;
}

void solve(){
    ll k; cin >> k;

    /*

       let f be a function such that
       f(x) = x - cnt(x)

       f(x + 1) = f(x) or f(x) + 1

       ie the sequence f(0), f(1), ... f(k), ... increase by at most 1 per element


       we are interested in y such that f(y) = k 

       once we find such y, answer is the largest number <= y such that it does not contain a 4 in its decimal representation
    */

    // minimize for y in [1, LLONG_MAX]
    ll lo = 1, hi = LLONG_MAX;
    while(lo < hi){
        ll mid = (hi - lo)/2 + lo;
        if(mid - cnt(mid) >= k) hi = mid;
        else lo = mid + 1;
    }
    assert(hi != LLONG_MAX);
    assert(lo - cnt(lo) == k);
    ll y = lo;

    // answer is largest number <= y which doesnt have 4 in it


    string ans = to_string(y);
    bool hasfour = false;

    for(int i = 0; i < ans.size(); i++){
        if(hasfour){
            ans[i] = '9';
            continue;
        }
        if(ans[i] == '4'){
            hasfour = true;
            ans[i] = '3';
        }
    }



    // this question took 6 years off my life i think
    cout << ans << '\n';
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
