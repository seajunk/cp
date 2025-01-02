#include <iostream>
#define ll long long
using namespace std;

// two pointers. instead of simulation each kraken attack, we can tell that the min of the twoend ships will be the first to sink. sink the min of the two ships and damage the other ship by the amount of durability the min ship had. mobe the pointers untill k is 0
void solve(){
    ll n, k; cin >> n; cin >> k;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll l = 0, r = n - 1;

    ll turn = 0;
    while(k && l <= r){
        if(l == r){
            a[l] = max(0ll, a[l] - k);
            break;
        }
        else{
            ll mn = min(a[l], a[r]);
            if(k == 1){
                if(turn % 2 == 0){
                    a[l]--;
                    k--;
                }
                else{
                    a[r]--;
                    k--;
                }
            }
            else{
                a[l] -= min(mn, k/2);
                a[r] -= min(mn, k/2);
                turn += 2*min(mn, k/2);
                k -= 2*min(mn, k/2);
                if(a[l] == 0) l++;
                if(a[r] == 0) r--;
            }
        }
    }
    
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] <= 0) cnt++;
    }

    cout << cnt << '\n';
    

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
