#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m; cin >> n >> m;
    char grid[n][m];

    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++) cin >> grid[r][c];
    }

    // each row must have same number of black & white
    // each col must have same number of black & white
    // each domino must have black & white


    // if a h domino exists on a row, somwhere along the column, the opposite domino must exist
    // if a v domino exists on a col, somwhere along the row, the opposite domino must exist


    // works iff count of l & r in columns are even & count of u & d in rows are even

    for(int r = 0; r < n; r++){
        ll ucnt = 0;
        ll dcnt = 0;

        for(int c = 0; c < m; c++){
            if(grid[r][c] == 'U') ucnt++;
            if(grid[r][c] == 'D') dcnt++;
        }
        if(ucnt % 2 != 0){
            cout << -1 << '\n';
            return;
        }
        if(dcnt % 2 != 0){
            cout << -1 << '\n';
            return;
        }
    }


    for(int c = 0; c < m; c++){
        ll lcnt = 0;
        ll rcnt = 0;

        for(int r = 0; r < n; r++){
            if(grid[r][c] == 'L') lcnt++;
            if(grid[r][c] == 'R') rcnt++;
        }
        if(lcnt % 2 != 0){
            cout << -1 << '\n';
            return;
        }
        if(rcnt % 2 != 0){
            cout << -1 << '\n';
            return;
        }
    }




    bool rowtoggle = true, coltoggle = true;

    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            if(grid[r][c] == 'U'){
                if(rowtoggle){
                    grid[r][c] = 'W';
                    grid[r + 1][c] = 'B';
                }
                else{
                    grid[r][c] = 'B';
                    grid[r + 1][c] = 'W';
                }
                rowtoggle = !rowtoggle;
            }
            else if(grid[r][c] == 'D'){
                if(rowtoggle){
                    grid[r][c] = 'B';
                    grid[r - 1][c] = 'W';
                }
                else{
                    grid[r][c] = 'W';
                    grid[r - 1][c] = 'B';
                }
                rowtoggle = !rowtoggle;
            }
        }
    }

    for(int c = 0; c < m; c++){
        for(int r = 0; r < n; r++){
             if(grid[r][c] == 'L'){
                if(coltoggle){
                    grid[r][c] = 'W';
                    grid[r][c + 1] = 'B';
                }
                else{
                    grid[r][c] = 'B';
                    grid[r][c + 1] = 'W';
                }
                coltoggle = !coltoggle;
            } else if(grid[r][c] == 'R'){
                if(coltoggle){
                    grid[r][c] = 'B';
                    grid[r][c - 1] = 'W';
                }
                else{
                    grid[r][c] = 'W';
                    grid[r][c - 1] = 'B';
                }
                coltoggle = !coltoggle;
            }
        }
    }







    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            cout << grid[r][c];
        }
        cout << '\n';
    }





}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
