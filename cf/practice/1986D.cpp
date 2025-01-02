#include <bits/stdc++.h>
#define ll long long
using namespace std;


void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    ll arr[n];
    for(int i = 0; i < n; i++) arr[i] = s[i] - '0'; 


    if(n == 2){
        cout << (ll)stoi(s.substr(0, 2)) << '\n';
        return;
    }

    if(n == 3 && s[1] == '0'){
        ll mn = LLONG_MAX;
        mn = min(mn, (ll)stoi(s.substr(0, 1)) + (ll)stoi(s.substr(1, 2)));
        mn = min(mn, (ll)stoi(s.substr(0, 2)) + (ll)stoi(s.substr(2, 1)));
        mn = min(mn, (ll)stoi(s.substr(0, 1)) * (ll)stoi(s.substr(1, 2)));
        mn = min(mn, (ll)stoi(s.substr(0, 2)) * (ll)stoi(s.substr(2, 1)));
        cout << mn << '\n';
        return;
    }

    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            cout << 0 << '\n';
            return;
        }
    }

    // 1 2 3 4 5
    ll mn = LLONG_MAX;
    for(int i = 0; i < n - 1 ; i++){
        vector<ll> b;
        for(int j = 0; j < n; j++){
            if(j == i){
                b.push_back((ll)stoi(s.substr(j, 2)));
                j++;
            }
            else{
                b.push_back((ll)stoi(s.substr(j, 1)));
            }
        }

        ll curr = 0;
        for(ll e : b){
            if(e != 1) curr += e;
        }
        mn = min(curr, mn);
    }

    cout << mn << '\n';
    // 2221



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
