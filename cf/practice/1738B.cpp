#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    ll s[k];
    for(int i = 0; i < k; i++) cin >> s[i];

    if(k == 1){
        cout << "Yes\n";
        return;
    }

    vector<ll> a;

    if(n == k) a.push_back(s[0]); 

    for(int i = 1; i < k; i++) a.push_back(s[i] - s[i - 1]);

    if(n == k){
        for(int i = 1; i < n; i++){
            if(a[i] < a[i - 1]){
                cout << "No\n";
                return;
            }
        }
        cout << "Yes\n";
        return;
    }

    for(int i = 1; i < k - 1; i++){
        if(a[i] < a[i - 1]){
            cout << "No\n";
            return;
        }
    }

    if((n - (k - 1)) * a[0] < s[0]){
        cout << "No\n";
        return;
    }
    cout << "Yes\n";


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
