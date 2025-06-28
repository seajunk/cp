#include <bits/stdc++.h>
using namespace std;
typedef uint64_t ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<ll> cnt(1001, 0);
    for(int i = 0; i < n; i++){
        cnt[a[i]] += 1;
    }



    // if x appears odd number of times, fixable if (x - 1) appears >= 3 times

    // C: effecively, can convert one x-1 to x we have atleast two x-1 



    function<bool(ll, ll)> fix = [&](ll i, ll target){
        if(cnt[i] >= target){
            return true;
        }
        
        if(i == 1) return false;


        bool worked = fix(i - 1, target - cnt[i] + 1); 

        if(!worked) return false;

        cnt[i - 1] -= target - cnt[i];
        cnt[i] = target;
        return true;
    };

    for(int i = 1000; i >= 1; i--){
        if(cnt[i] % 2 == 0) continue;
        if(!fix(i, cnt[i] + 1)){
            cout << "NO\n";
            return;
        }
    }

    cout << "Yes\n";
    return;
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
