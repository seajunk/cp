#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, x; cin >> n >> x;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    //unordered_map<ll, ll> m;
    // unordered_map might get blown up
    map<ll, ll> m;
    for(int i = 0; i < n; i++){
        if(m.find(a[i]) != m.end()){
            cout << m[a[i]] + 1 << ' ' << i + 1 << '\n';
            return 0;
        }

        m[x - a[i]] = i;
    }

    cout << "IMPOSSIBLE" << '\n';
    return 0;

}
