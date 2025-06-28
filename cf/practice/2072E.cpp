#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll k; cin >> k;

    /*
       need to place n /in [0, 500] staves in the ground such that there are exactly k pairs of staves whose euclidian distance and manhattan distances are the same.

       note that this happens only if two staves lie on the same x or y axis 


       combinatorics ?

       if we have m staves on some axis, we have m choose 2 = m(m-1)/2 pairs. 

       greedy do it lol
    */

    vector<vector<ll>> ans;

    ll pairs = 0;
    ll curr = 0;
    ll x = 0, y = 0;

    while(true){
        if(pairs + curr < k){
            ans.push_back({x, y});
            pairs += curr;
            curr++;
            y++;
        }
        else if(pairs + curr == k){
            ans.push_back({x, y});
            break;
        }
        else{
            x++;
            y++;
            curr = 0;
        }
    }




    cout << ans.size() << '\n';
    for(auto e : ans) cout << e[0] << ' ' << e[1] << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
