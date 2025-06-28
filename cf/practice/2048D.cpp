#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m; cin >> n >> m;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll b[m];
    for(int i = 0; i < m; i++) cin >> b[i];



    /*
       if a contest contains b[i], we can determien the lowerbound of kevins rank on this contest.
       namely, 
       if b[i] <= a[0], kevins rank >= 1
       if b[i] > a[0], kevins rank >= # of guys who can solve this problem + 1
       and its easy to see that kevins rank in a contest is the largest of these lowerbounds
       
       So if we want to minmize kevins rank across all contests, we should sort the contests by their lower bounds?
    */

    ll kevin = a[0];
    sort(a, a + n);

    ll lb[m];
    for(int i = 0; i < m; i++){
        if(kevin >= b[i]) lb[i] = 1;
        else{
            ll lo = 0, hi = n;
            while(lo < hi){
                ll mid = (hi - lo)/2+lo;
                if(a[mid] >= b[i]) hi = mid;
                else lo = mid + 1;
            }
            lb[i] = n - lo + 1;
        }
    }

    sort(lb, lb + m);


    vector<ll> ans(m, 0);

    for(int k = 1; k <= m; k++){
        for(int j = 0; j < m/k; j++){
            // jth contest = [k*j, k*(j+1))
            ans[k - 1] += lb[k*(j+1) - 1];
        }
    }

    for(auto e : ans) cout << e << ' ';
    cout << '\n';













}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
