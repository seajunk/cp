#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m; cin >> n >> m;
    ll a[n][m];

    for(int r = 0; r < n; r++){
        string s; cin >> s;
        for(int c = 0; c < m; c++){
            a[r][c] = stoll(string(1, s[c]));
        }
    }

    // >> 2 4 
    // >> 1 5 4 3
    // >> 1 1 1 1

    ll layers = min(n, m) / 2;
    ll ans = 0;
    for(int layer = 0; layer < layers; layer++){
        vector<ll> flat;

        // top part
        for(int i = layer; i < m - layer; i++) flat.push_back(a[layer][i]);

        // right part
        for(int i = layer + 1; i < n - 1 - layer; i++) flat.push_back(a[i][m - 1 - layer]);

        // bottom part
        for(int i = m - 1 - layer; i >= layer; i--) flat.push_back(a[n - 1 - layer][i]);

        // left part
        for(int i = n - 2 - layer; i >= layer + 1; i--) flat.push_back(a[i][layer]);

        for(int i = 0; i < flat.size(); i++){
            if((flat[i % flat.size()] == 1) && (flat[(i + 1) % flat.size()] == 5) && (flat[(i + 2) % flat.size()] == 4) && (flat[(i + 3) % flat.size()] == 3)){
                ans++;
            }
        }

    }

    cout << ans << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
