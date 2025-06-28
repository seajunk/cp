#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve(){

    ll n; cin >> n;


    vector<vector<ll>> children(n);


    for(int i = 2; i <= n; i++){
        ll a = i, b = 1;
        while(a != b){
            cout << "? " << a << ' ' << b << '\n';
            ll in; cin >> in;
            if(a == in){
                children[b - 1].push_back(a - 1);
            }
            b = in;
        }
    }

    /*
    for(int i = 0; i < n; i++){
        cout << i + 1 << ": ";
        for(auto child : children[i]) cout << child + 1 << ' ';
        cout << '\n';
    }
    */


    cout << "! ";
    stack<ll> dfs;
    dfs.push(0);
    while(dfs.size()){
        ll top = dfs.top();
        dfs.pop();

        for(ll child : children[top]){
            ll u = top + 1, v = child + 1;
            cout << u << ' ' << v << ' ';
            dfs.push(child);
        }
    }
    cout << '\n';
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
