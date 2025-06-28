#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    vector<vector<ll>> blocks(n);
    vector<ll> values;

    for(int i = 0; i < n; i++){
        ll k; cin >> k;
        vector<ll> b(k);
        for(int j = 0; j < k; j++){
            cin >> b[j];
            values.push_back(b[j]);
        }
        blocks[i] = b;
    }

    sort(values.begin(), values.end()); // 10^6

    map<ll, ll> mapping;
    for(int i = 0; i < values.size(); i++) mapping[values[i]] = i;




    /*
       need atleast n-1 combines
       need to break untill each tower is subarray of [0, 1, ..., values.size()]

       iterate over each tower, if mapping[b[i - 1]] + 1 != mapping[b[i]]
       we need to break b[i - 1] off the tower, 
       so split++, combine++
       since for each guy broken off, he needs to be added back
    */


    ll c = n - 1;
    ll s = 0;

    for(int i = 0; i < n; i++){
        for(int j = 1; j < blocks[i].size(); j++){
            if(mapping[blocks[i][j - 1]] + 1 != mapping[blocks[i][j]]){
                c++;
                s++;
            }
        }
    }

    cout << s << ' ' << c << '\n';



}

int main(){
    solve();
}
