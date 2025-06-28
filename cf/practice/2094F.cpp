#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

void solve(){
    ll n, m, k; cin >> n >> m >> k;
    ll cnt = n*m / k;
    /*
       want n x m grid such that

       (1) each 1 through k appears exactly nm/k times in a cell  (nm % k == 0) 

       (2) no adjacent cells contain the same number

       cnt = n*m / k

       want to split grid into cnt equal subgrids, each subgrids should have k cells

       r, sub grid row should be subset of n 
       c,  sub grid col should be subset of m

       r = gcd(k, n)
       c = gcd(k / gcd(k, n), m) 
       k = r * c


       R, row of big grid
       C, col of big grid

       R = n / r
       C = m / c


       then,
       cycle subgrids elements right for each row
       cycle subgrids element down for each col 


       eg,

       1 2 3  4 5 6
       4 5 6  1 2 3

       3 1 2  6 4 5
       6 4 5  3 1 2



       1 2 3  1 2 3

       3 1 2  3 1 2
    */

    ll r = gcd(k, n);
    ll c = gcd(k / gcd(k, n), m);
    ll R = n / r;
    ll C = m / c;


    vector<vector<ll>> ans(n, vector<ll>(m));



    // iterate over big grids

    for(int i1 = 0; i1 < R; i1++){
        for(int i2 = 0; i2 < C; i2++){

            // rotate right by i1
            // rotate down by i2

            ll curr = 1;
            for(int i3 = 0; i3 < r; i3++){
                for(int i4 = 0; i4 < c; i4++){
                    ll row = i1*r + (i3 + i2) % r;
                    ll col = i2*c + (i4 + i1) % c;
                    ans[row][col] = curr;
                    curr++;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << ans[i][j] << ' ';
        cout << '\n';
    }

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
