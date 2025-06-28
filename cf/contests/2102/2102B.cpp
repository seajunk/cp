#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;

    vector<vector<ll>> a(n, vector<ll>(2));


    for(int i = 0; i < n; i++){
        a[i][0] = i;
        cin >> a[i][1];
        if(a[i][1] < 0) a[i][1] *= -1;
    }


    sort(a.begin(), a.end(), [](auto l, auto r){ return l[1] < r[1];});


    for(int i = 0; i < n; i++){
        if(a[i][0] == 0){


            // a[i][0] can put n - i - 1 guys to the left of it 
            // so it can become order i + 1 to n
            // it can also become order 1 to n - i

            // the median is order (n + 1) / 2

            // 0 3 4 5





            ll median = ((n + 1) / 2);


            if(i + 1 <= median && median <= n){
                cout << "YES\n";
                return;
            }


            if(1 <= median && median <= n - i){
                cout << "YES\n";
                return;
            }

            cout << "NO\n";
            return;


            






        }
    }



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
