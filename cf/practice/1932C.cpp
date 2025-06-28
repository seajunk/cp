#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m; cin >> n >> m;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    string s; cin >> s;


    ll l = 0, r = n - 1;
    vector<ll> indices;

    for(char c : s){
        if(c == 'L'){
            indices.push_back(l);
            l++;
        }
        else{
            indices.push_back(r);
            r--;
        }
    }

    
    


    ll curr = a[indices[n - 1]];

    stack<ll> ans;
    ans.push(curr % m);

    for(int i = n - 2; i >= 0; i--){
        curr *= a[indices[i]];
        curr %= m;

        ans.push(curr);
    }

    while(ans.size()){
        cout << ans.top() << ' ';
        ans.pop();
    }
    cout << '\n';









}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
