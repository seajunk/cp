#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    k--;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];


    ll idx = -1;

    for(int i = 0; i < n; i++){
        if(a[i] > a[k]){
            idx = i;
            break;
        }
    }

    if(idx == -1){
        cout << n - 1 << '\n';
        return;
    }

    if(idx > k){
        cout << idx - 1 << '\n';
        return;
    }

    if(idx < k){
        // at best k - 1
        vector<ll> temp = a;
        swap(temp[0], temp[k]);

        ll firstswap = 0;
        for(int i = 0; i < n - 1; i++){
            if(temp[i] > temp[i + 1]){
                firstswap++;
                swap(temp[i], temp[i + 1]);
            }
            else break;
        }

        temp = a;
        swap(temp[idx], temp[k]);
        ll idxswap = 0;
        if(idx != 0) idxswap++;

        for(int i = idx; i < n - 1; i++){
            if(temp[i] > temp[i + 1]){
                idxswap++;
                swap(temp[i], temp[i + 1]);
            }
            else break;
        }

        cout << max(idxswap, firstswap) << '\n';




    }



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
