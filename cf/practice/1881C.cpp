#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;

void solve(){
    /*
       for each cell, get the 3 other guys obtainable from
       rotating and get the max char of the 4. then calculate number of operations to turn every guy into the max char 
    */
    ll n; cin >> n;
    char a[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }



    // can rotate matrix by transposing -> reversing column order. 


    ll ans = 0;
    for(ll r = 0; r < n; r++){
        for(ll c = 0; c < n; c++){

            vector<char> curr; // set of chars obtainable from rotating a[i, j]
            pair<ll, ll> second = {c, n - 1 - r};
            pair<ll, ll> third = {second.second, n - 1 - second.first};
            pair<ll, ll> fourth = {third.second , n - 1 - third.first};

            curr.push_back(a[r][c]);
            curr.push_back(a[second.first][second.second]);
            curr.push_back(a[third.first][third.second]);
            curr.push_back(a[fourth.first][fourth.second]);

            char mx = 0;
            for(char c : curr){
                mx = max(mx, c);
            }
            for(char c : curr){
                ans += mx - c;
            }
        }
    }



    cout << ans / 4 << '\n';


    

    
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
