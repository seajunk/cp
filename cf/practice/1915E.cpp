#include <iostream>
#include <set>
#include <vector>
#define ll long long
using namespace std;

void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<vector<ll>> pre(n + 1, vector<ll>(2, 0));

    pre[0] = {0, 0};
    for(int i = 1; i <= n; i++){
        pre[i][0] = pre[i - 1][0];
        pre[i][1] = pre[i - 1][1];
        if(i&1) pre[i][1] += a[i - 1]; 
        else pre[i][0] += a[i - 1]; 
    }


    set<vector<ll>> s;

    // (x, y) need (a, b) st a - x = b - y <=> a + y = b + x
    // (0, 2) need (3, 5) | (2, 7)
    // store x - y?
    // if x - y = a - b then (x, y), (a, b) are compatible pairs?
    // (1, 5) (7, 11) true 
    for(int i = 0; i <= n; i++){
        if(s.find({pre[i][0] - pre[i][1]}) != s.end()){
            cout << "YES" << '\n';
            return;
        }
        s.insert({pre[i][0] - pre[i][1]});
    }
    cout << "NO" << '\n';

}

int main(){
    ll t;  cin >> t;
    while(t--) solve();
}


