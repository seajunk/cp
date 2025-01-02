#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    set<ll> unique;
    map<ll, ll> cnt;
    for(int i = 0; i < n; i++){
        unique.insert(a[i]);
        if(cnt.find(a[i]) == cnt.end()) cnt[a[i]] = 1;
        else cnt[a[i]]++;
    }

    

    vector<vector<ll>> blocks;
    vector<ll> temp;
    temp.push_back(cnt[*unique.begin()]);
    for(auto it = next(unique.begin()); it != unique.end(); it++){
        if(*prev(it) + 1 == *it){
            temp.push_back(cnt[*it]);
        }
        else{
            blocks.push_back(temp);
            temp = {cnt[*it]};
        }
        if(next(it) == unique.end()){
            blocks.push_back(temp);
            temp = {};
        }
    }
    if(temp.size()) blocks.push_back(temp);


    ll ans = 0;
    for(vector<ll> block : blocks){
        ll curr = 0;
        if(block.size() <= k){
            for(ll b : block) curr += b;
            ans = max(ans, curr);
        }
        else{
            for(int i = 0; i < k; i++){
                curr += block[i];
            }
            ans = max(ans, curr);
            for(int i = k; i < block.size(); i++){
                curr += block[i];
                curr -= block[i - k];
                ans = max(ans, curr);
            }
        }
    }

    cout << ans << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
