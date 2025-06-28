#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);


    ll firsteven = -1, lasteven = -1, firstodd = -1, lastodd = -1;




    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            firsteven = i;
            break;
        }
    }

    for(int i = n - 1; i >= 0; i--){
        if(a[i] % 2 == 0){
            lasteven = i;
            break;
        }
    }

    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 1){
            firstodd = i;
            break;
        }
    }

    for(int i = n - 1; i >= 0; i--){
        if(a[i] % 2 == 1){
            lastodd = i;
            break;
        }
    }


    ll ans = min(firsteven + n - (lasteven + 1), firstodd + n - (lastodd + 1));

    cout << ans << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

