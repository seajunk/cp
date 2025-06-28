#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    /*
       subarray b appears as a ss exactly once iff 

       its first element is the first occurence and the last element is the last occurence

       (=>) suppose subarray b has first element as first occurence ans last element as last occurence. now suppose towards contradiction that b appears more than once as a ss in a. then there exists ss which is equal to b where either its first element or last element is not the first occurence of last occurence respectively. note then that there are less numbers between this ss first and last elements than are in b which is a contradiction.

       (<-) suppoose subarray b appears as ss exactly once. now suppsoe towards contradiction that either its first or last element is not the first or last occurence. then this is a contradiction as we can just take the first occurnece / last occurence and take the rest of the array as the same as b. then we get b as a ss which is distinct for the subarray b. 
    */



    vector<bool> first(n);
    vector<bool> last(n);

    set<ll> seen;

    for(int i = 0; i < n; i++){
        if(seen.find(a[i]) == seen.end()) first[i] = true;
        seen.insert(a[i]);
    }


    seen.clear();

    for(int i = n - 1; i >= 0; i--){
        if(seen.find(a[i]) == seen.end()) last[i] = true;
        seen.insert(a[i]);
    }


    vector<ll> sfs(n + 1);
    sfs[n] = 0;
    for(int i = n - 1; i >= 0; i--) sfs[i] = sfs[i + 1] + last[i];

    ll ans = 0;

    for(int i = 0; i < n; i++){
        if(!first[i]) continue;
        ans += sfs[i];
    }

    cout << ans << '\n';







}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
