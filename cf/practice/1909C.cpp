#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll c[n];
    unordered_map<ll, ll> type;
    set<ll> thing;
    for(int i = 0; i < n; i++){
        ll in; cin >> in;
        thing.insert(in);
        type[in] = 0;
    } 
    for(int i = 0; i < n; i++){
        ll in; cin >> in;
        thing.insert(in);
        type[in] = 1;
    } 
    for(int i = 0; i < n; i++) cin >> c[i];


    stack<ll> temp;
    vector<ll> intervals;

    for(ll t : thing){
        if(type[t] == 0){
            temp.push(t);
        }
        else{
            intervals.push_back(t - temp.top());
            temp.pop();
        }
    }

    sort(intervals.begin(), intervals.end());

    sort(c, c + n);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += intervals[i] * c[n - i - 1];
    }

    cout << ans << '\n';





}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
