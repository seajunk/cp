#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n; cin >> n;
    vector<ll> a;
    set<ll> seen;
    for(int i = 0; i < n; i++){
        ll in; cin >> in;
        if(seen.find(in) == seen.end()) a.push_back(in);
        seen.insert(in);
    }
    sort(a.begin(), a.end());
    ll m = a.size();
    ll lo = 1;
    ll hi = m + 1;
    
    // search space = [1, m + 1)



    while(lo < hi){
        ll mid = (hi - lo) / 2 + lo;


        bool valid = false;

        for(int i = mid - 1; i < m; i++){
            if(a[i] - a[i - mid + 1] < n){
                valid = true;
                //cout << a[i] << ' ' << a[i - mid + 1] << '\n';
            }

        }


        if(valid){
            lo = mid + 1;
        }
        else{
            hi = mid;
        }
    }
    cout << lo - 1 << '\n';

}

int main(){
    ll t; cin >> t; 
    while(t--) solve();
}

