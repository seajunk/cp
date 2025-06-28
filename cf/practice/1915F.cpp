#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;

// ??????????????????????????????
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
  

void solve(){
    ll n; cin >> n;

    map<ll, ll> intervals;
    ordered_set A, B;
    vector<ll> temp(n);

    for(int i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        A.insert(a);
        B.insert(b);
        intervals[a] = b;
    }

    /*
       for each i [0, n], 

       guy goes from a[i] to b[i] 

       every value in the arrays are distinct


       all guys move at 1/sec

       if guys meet they greet

       how many greetings ?

       greeting happens between i and j iff one of i or j fully contains the other ?

       eg [0, 5], [2, 4]

       but not [0, 5] [2, 6]
    */

    ll ans = 0;
    for(ll a : A){
        auto it = B.lower_bound(intervals[a]);
        ans += B.order_of_key(intervals[a]);
        B.erase(intervals[a]);
    }

    // key thing here was getting order of a key in a tree in O(logn) time, which set doesnt support(?)


    cout << ans << '\n';





}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

