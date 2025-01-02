#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, m; cin >> n >> m;
    ll x[n];
    unordered_map<ll, ll> idx;
    for(int i = 0; i < n; i++){
        cin >> x[i];
        idx[x[i]] = i;
    } 

    // 1 3 5 4 6 2
    // 1 2 
    // 3 4
    // 5 6

    ll runs = 1;
    for(int i = 2; i <= n; i++){
        if(idx[i - 1] > idx[i]) runs++;
    }
    cout << runs << '\n';


    for(int i = 0; i < m; i++){
        ll a, b; cin >> a >> b;

        // # of runs for an array is # of pairs of inversed consecutive numbers + 1
        // when swapping, a, b, 3 cases
        // case 1: |a - b| = 1 
        // case 2: |a - b| = 2
        // case 3: ow





    }


}



