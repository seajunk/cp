#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){

    /*
       given array a of length n, want to split a into k > 1 partitions such that each partition has the same mex 
       note that two arrays with the same mex concatenated will have the same mex. 

       then our array is good if there is a way to split it into two such that each array has the same mex   

       key thing is that a[i] <= n so we can do have some counting sort esque thing to get prefix mex maybe? 
   */

    ll n; cin >> n; 
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<ll> taken(n + 1, false);

    ll pfmex[n], sfmex[n];
    ll mex = 0;

    for(int i = 0; i < n; i++){
        taken[a[i]] = true;
        while(taken[mex]) mex++;
        pfmex[i] = mex;
    }

    taken.assign(n + 1, false);
    mex = 0;

    for(int i = n - 1; i >= 0; i--){
        taken[a[i]] = true;
        while(taken[mex]) mex++;
        sfmex[i] = mex;
    }


    for(int i = 1; i < n; i++){
        if(pfmex[i - 1] == sfmex[i]){
            cout << 2 << '\n';
            cout << 1 << ' ' << i << '\n';
            cout << i + 1 << ' ' << n << '\n';
            return;
            
        }
    }


    cout << -1 << '\n';





}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
