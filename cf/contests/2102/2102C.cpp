#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;


    /*
       want to maximize the sum of mex of all sumgrids

       mex of a grid is the 

    */



    vector<vector<ll>> grid(n, vector<ll>(n, -1));


    // if odd, handle innermost layer seperately
    ll curr = n*n - 1;
    for(int layer = 0; layer < n/2; layer++){
        // top
        for(int col = layer; col < n - layer; col++){
            grid[layer][col] = curr;
            curr--;
        }

        // right
        for(int row = layer + 1; row < n - layer; row++){
            grid[row][n - 1 - layer] = curr;
            curr--;
        }

        // bottom 
        for(int col = n - layer - 2; col >= layer; col--){
            grid[n - layer - 1][col] = curr;
            curr--;
        }

        // left
        for(int row = n - layer - 2; row >= layer + 1; row--){
            grid[row][layer] = curr;
            curr--;
        }
    }


    if(n % 2 != 0){
        grid[n/2][n/2] = 0;
    }


    for(auto r : grid){
        for(auto c : r) cout << c << ' ';
        cout << '\n';
    }





}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}


