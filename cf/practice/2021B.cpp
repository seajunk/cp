#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n, x; cin >> n >> x;
    ll a[n];


    set<ll> seen;
    map<ll, ll> excess;
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(seen.find(a[i]) == seen.end()) seen.insert(a[i]);
        else{
            cnt++;
            if(excess.find(a[i]) == excess.end()) excess[a[i]] = 1;
            else excess[a[i]]++;
        }
    }


    ll m = n + cnt;
    // mex in [0, m]


    vector<bool> has(m + 1, false);
    for(int i = 0; i < n; i++){
        if(a[i] <= m) has[a[i]] = true;
    }

    vector<ll> missing;
    
    for(int i = 0; i <= m; i++){
        if(!has[i]) missing.push_back(i);
    }


    unordered_map<ll, map<ll, ll>> table;

    for(pair<ll, ll> p : excess){
        if(table.find(p.first % x) == table.end()) table[p.first % x][p.first] = p.second;
        else table[p.first % x][p.first] = p.second; 
    }

    for(int i = 0; i < missing.size(); i++){
        if(table.find(missing[i] % x) == table.end()){
            cout << missing[i] << '\n';
            return;
        }
        else{
            map<ll, ll>::iterator lb = (table[missing[i] % x].lower_bound(missing[i]));
            if(lb == table[missing[i] % x].begin()){
                cout << missing[i] << '\n';
                return;
            }
            else{
                lb--;
                if(table[missing[i] % x][(*lb).first] == 1) table[missing[i] % x].erase((*lb).first);
                else table[missing[i] % x][(*lb).first]--;
            }
        }
    }

    cout << m << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

