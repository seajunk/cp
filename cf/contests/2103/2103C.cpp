#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];


    /*
       need to partition a into 3 subarrays such that median of at least 2 of the arrays is <= k
       call these 2 guys small 

       case 1. left and right are small
       greedily increase prefix array until small, same for suffix 


       case 2. left and middle are small
       would greedy work?

       case 3. right and middle are small
    */

    // pfsum[i] = sum over a[0, i)
    ll pfsum[n + 1];
    pfsum[0] = 0;
    for(int i = 1; i <= n; i++) pfsum[i] = pfsum[i - 1] + (a[i - 1] <= k ? 1 : -1);

    // my head hurts
    vector<ll> sfmx(n + 1, LLONG_MIN); // pfsumsfmx[i] = max over pfsum[j] for i < j <= n - 1

    sfmx[n] = LLONG_MIN;
    for(int i = n - 1; i >= 0; i--) sfmx[i] = max(sfmx[i + 1], pfsum[i]);

    for(int i = 1; i <= n - 2; i++){
        if(pfsum[i] >= 0 && sfmx[i + 1] >= pfsum[i]){
            //cout << "case 1\n";
            cout << "YES\n";
            return;
        }
    }

    ll pfmx[n + 1];
    pfmx[0] = LLONG_MIN;
    for(int i = 1; i <= n; i++){
        pfmx[i] = max(pfmx[i - 1], (pfsum[n] - pfsum[i]));
    }

    for(int i = n - 1; i >= 2; i--){
        if((pfsum[n] - pfsum[i]) >= 0 && (pfsum[n] - pfsum[i]) <= pfmx[i - 1]){
            //cout << "case 2\n";
            cout << "YES\n";
            return;
        }
    }


    ll l = -1, r = -1;
    for(int i = 1; i <= n - 2; i++){
        if(pfsum[i] >= 0){
            l = i;
            break;
        }
    }

    for(int i = n - 1; i >= 2; i--){
        if((pfsum[n] - pfsum[i]) >= 0){
            r = i;
            break;
        }
    }

    if(l != -1 && r != -1 && l < r){
        //cout << l << ' ' << r << '\n';
        cout << "YES\n";
        return;
    }





    cout << "NO\n";
    return;
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

