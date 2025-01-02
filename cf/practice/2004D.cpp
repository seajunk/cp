#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    vector<set<ll>> cities(6);
    vector<vector<ll>> adj(6);
    adj[0] = {1, 2, 3, 4};
    adj[1] = {0, 2, 3, 5};
    adj[2] = {0, 1, 4, 5};
    adj[3] = {0, 1, 4, 5};
    adj[4] = {0, 2, 3, 5};
    adj[5] = {1, 2, 3, 4};

    ll n, q; cin >> n >> q;


    unordered_map<ll, ll> colour;
    for(int i = 0; i < n; i++){
        string c; cin >> c;
        if(c == "BG"){
            colour[i] = 0;
            cities[0].insert(i);
        } 
        if(c == "BR"){
            colour[i] = 1;
            cities[1].insert(i);
        } 
        if(c == "BY"){
            colour[i] = 2;
            cities[2].insert(i);
        } 
        if(c == "GR"){
            colour[i] = 3;
            cities[3].insert(i);
        } 
        if(c == "GY"){
            colour[i] = 4;
            cities[4].insert(i);
        } 
        if(c == "RY"){
            colour[i] = 5;
            cities[5].insert(i);
        } 
    }

    for(int i = 0; i < q; i++){
        ll start, end; cin >> start >> end; start--; end--;

        if(colour[start] == colour[end]){
            cout << abs(start - end) << '\n';
            continue;
        }

        vector<bool> visited(n, false);









    }

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
