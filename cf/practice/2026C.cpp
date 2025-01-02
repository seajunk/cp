#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    string s; cin >> s;

    // 00111
    // (2, 5) (1, 4), 3 = 2 + 1 + 3 = 6
    // (1, 5) (2, 4), 3 = 1 + 2 + 

    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        a[i] = stoll(string(1, s[i]));
    }

    set<ll> ones;

    for(int i = 0; i < n; i++){
        if(a[i] == 1){
            ones.insert(i + 1);
        }
    }

    ll ans = 0;
    for(int i = n - 1; i >= 0; i--){
        if(a[i] == 0){
            auto mx = ones.end();

            if(mx == ones.begin()){
                ans += i + 1;
            }
            else{
                mx--;
                ll temp = *mx;
                if(i + 1 < temp){
                    ans += i + 1;
                    ones.erase(mx);
                }
                else ans += i + 1;
            }
        }
    }

    vector<ll> temp;
    for(ll one : ones) temp.push_back(one);

    for(int i = 0; i < (temp.size() + 1) / 2; i++){
        ans += temp[i];
    }

    cout << ans << '\n';





}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

