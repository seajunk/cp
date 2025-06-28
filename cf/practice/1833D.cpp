#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    vector<ll> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    /*
       main priority is to get n to the first index since any array without n at the start will be smaller

       this isnt possible if a[0] = n, in which case we prioritize a[0] = n - 1 to happen


    */


    ll I = -1;


    for(int i = 0; i < n; i++){
        if(p[i] == n){
            I = i;
            break;
        }
    }

    if(I == 0){
        for(int i = 0; i < n; i++){
            if(p[i] == n - 1){
                I = i;
                break;
            }
        }
    }

    // try segments tj, I - 1]
    // additonally if I == n - 1, also try [0, n - 1] and [n - 1, n - 1]
    // O(n^2)


    vector<ll> ans = {LLONG_MIN};

    for(int j = 0; j <= I - 1; j++){
        // choosing [j, I - 1] 
        // prefix = [0, j - 1]
        // suffix = [I, n - 1]
        vector<ll> prefix, middle, suffix;

        // try not to get constant factor diffed challenge
        for(int k = 0; k <= j - 1; k++) prefix.push_back(p[k]);
        for(int k = I; k <= n - 1; k++) suffix.push_back(p[k]);
        for(int k = I - 1; k >= j; k--) middle.push_back(p[k]);
        vector<ll> temp;

        for(ll e : suffix) temp.push_back(e);
        for(ll e : middle) temp.push_back(e);
        for(ll e : prefix) temp.push_back(e);

        ans = max(ans, temp);
    }

    if(I == n - 1){
        vector<ll> temp;

        // choosing [0, n - 1]
        for(int i = n - 1; i >= 0; i--) temp.push_back(p[i]);
        ans = max(ans, temp);
        temp.clear();

        // choosing [n - 1, n - 1] 
        temp.push_back(p[I]);
        for(int i = 0; i < n; i++){
            if(i == I) continue;
            temp.push_back(p[i]);
        }
        ans = max(ans, temp);

    }


    for(ll e : ans) cout << e << ' ';
    cout << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
