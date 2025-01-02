#include <iostream>
#define ll long long
using namespace std;

void solve(){
    ll n; cin >> n;
    ll ans = 1e9;

    for(int one = 0; one < 3; one++){
        for(int three = 0; three < 2; three++){
            for(int six = 0; six < 5; six++){
                for(int ten = 0; ten < 3; ten++){
                    ll m = n;
                    ll cnt = one + three + six + ten;
                    m -= one * 1 + three * 3 + six * 6 + ten * 10;

                    if(m > 0){
                        cnt += m/15;
                        m -= 15 * (m/15);
                    }
                    if(m == 0) ans = min(cnt, ans);
                }
            }
        }
    }

    cout << ans << '\n';
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
