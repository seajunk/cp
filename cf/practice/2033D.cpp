#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ps[n + 1];
    ps[0] = 0;
    for(int i = 1; i <= n; i++){
        ps[i] = ps[i - 1] + a[i - 1];
    }



    // 1 2 -3 4 -4
    // 0 1 3 0 4 <=> sum of [0, 3) = 0 
    vector<vector<ll>> intervals;
    map<ll, ll> m;
    for(int i = 0; i <= n; i++){
        if(m.find(ps[i]) == m.end()) m[ps[i]] = i;
        else{
            intervals.push_back({m[ps[i]], i});
            m[ps[i]] = i;
        }
    }


    sort(intervals.begin(), intervals.end(), [](vector<ll> left, vector<ll> right){ return left[1] < right[1]; });

    ll ans = 0;
    ll latest = 0;
    for(vector<ll> interval : intervals){
        if(latest <= interval[0]){
            latest = interval[1];
            ans++;
        }
    }

    cout << ans << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
