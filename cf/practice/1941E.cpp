#include <bits/stdc++.h>
typedef long long ll;
using namespace std;






void solve(){
    ll n, m, k, d; cin >> n >> m >> k >> d;





}



void solve1(){
    ll n, m, k, d; cin >> n >> m >> k >> d;

    ll bridge[n][m];

    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            cin >> bridge[r][c];
        }
    }

    ll pf_sum[n][m + 1];

    for(int r = 0; r < n; r++){
        pf_sum[r][0] = 0;
    }

    for(int r = 0; r < n; r++){
        for(int c = 1; c <= m; c++){
            pf_sum[r][c] = bridge[r][c - 1] + pf_sum[r][c - 1];
        }
    }

    ll opt[n];
    for(int r = 0; r < n; r++){
        vector<ll> beams;
        ll cost = 2;

        ll idx = -1;
        ll prev = 0;

        //cout << 0 << ' ';

        while(abs(prev - (m - 1)) - 1 > d){
            ll mx = LLONG_MIN;
            for(ll i = prev + 1; i <= min(m - 1,  prev + 1 + d); i++){
                // sum( [max(prev + d, i), min(n, i + d + 1)) )
                ll value = pf_sum[r][min(m, i + d + 1)] - pf_sum[r][max(prev + d + 1, i)] - bridge[r][i];
                if(value >= mx){
                    mx = value;
                    idx = i;
                }

            }
            //cout << idx << ' ';
            prev = idx;
            cost += bridge[r][idx] + 1;
        }

        //cout << m - 1;
        
        //cout << ": " << cost << '\n';


        opt[r] = cost;
    }

    ll window = 0;


    for(int i = 0; i < k; i++){
        window += opt[i];
    }

    ll ans = window;
    ll ans_idx = 0;
    for(int i = k; i < n; i++){
        window -= opt[i - k];
        window += opt[i];
        if(window <= ans){
            ans_idx = i;
            ans = window;
        }
    }

    cout << ans << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
