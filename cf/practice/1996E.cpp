#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s; cin >> s;
    ll n = s.size();
    ll MOD = 1e9 + 7;
    /*

       for each substring s[l, r], count the number of substrings in s[l, r] which has same # of 1 and 0


       So a way to think of it is,
       let the weight of a subarray s[l, r) be the number of subarrays which contain it.
       Then we are intereseted in the sum of weight of all euqal subarrays.



       One way to calculate this is to get every equal subarray and sum up its weights. Even if we do this as efficiently as possible, there are order of n^2 subarrays for us to check so this method is too slow.


       Is there some way to aggragate ? The issue is that the weight of a subarray depends on its boundaries. The usual way of counting equal subarrays doesnt consider the specific positions of the boundaries.















       lets fix l. then if we have the sum of n - r + 1 for all equal subarrays of the form [l, r), we can calculate the total weight of all equal subarrays with left boundary l?

       for example if we have the for a fixed l there are equal subarrays
       [l, a0)
       [l, a1)
       [l, a2)
       [l, a3) ... etc 

       Then the combined weight would be 
       (l + 1)*(n - a0 + 1) + (l + 1)*(n - a1 + 1) + ...
       where we can just factor out (l + 1) leaving us with sum(n - ai + 1)


       lets fix r instead.
       for a fixed r, how to get sum of l + 1 across all equal subarrays [l, r)?

       modify the usual prefix sum : count method but instead of keeping track of count, keep track prefix sum : sum of l

       ??
    */



    map<ll, ll> cnt; // cnt[x] = sum of r + 1 in subarray [0, r) where sum over [0, r) = x
    cnt[0] = 1;
    ll ans = 0;
    ll sum = 0;
    for(int r = 1; r <= n; r++){
        if(s[r - 1] == '0') sum--;
        else sum++;

        if(cnt.find(sum) != cnt.end()){
            ans += (cnt[sum]*(n - r + 1)) % MOD;
            cnt[sum] += r + 1;
        }
        else cnt[sum] = r + 1;
    }

    cout << (ans % MOD) << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
