#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n; cin >> n;
    ll k[n];
    for(int i = 0; i < n; i++) cin >> k[i];
    set<ll> seen;
    ll mx = 0;
    for(int l = 0, r = 0; r < n;){
        if(seen.find(k[r]) == seen.end()){
            seen.insert(k[r]);
            r++;
        }
        else{
            seen.erase(k[l]);
            l++;
        }
        mx = max((ll)seen.size(), mx);
    }
    cout << mx << '\n';



}
