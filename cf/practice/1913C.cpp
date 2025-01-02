#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll m; cin >> m;

    unordered_map<ll, ll> cnt;
    for(int i = 0; i < 32; i++) cnt[i] = 0;

    for(int i = 0; i < m; i++){
        ll t, v; cin >> t >> v;
        if(t == 1){
            cnt[v]++;
        }
        else{
            bitset<32> temp(v);
            
            ll carry = 0;
            bool possible = true;
            for(int i = 0; i < 32; i++){
                if(cnt[i] + carry < temp[i]){
                    possible = false;
                }
                else{
                    carry = (cnt[i] + carry - temp[i]) / 2;
                }
            }
            if(possible) cout << "YES\n";
            else cout << "NO\n";

            // 003
            // 011
            // 100
        }
    }

}

int main(){
    solve();
}

