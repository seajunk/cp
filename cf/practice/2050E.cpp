#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string a, b, c; cin >> a >> b >> c;
    ll n = c.size();

    /*
       string c is made of interleaving a and b, then arbirarily changing some number of characters.
       want to find out minimum number of changes that must have happend in c

       |a|, |b| <= 1000

       dp[i][j]

       considering first i, j elements of a, b
       comparing it to first i + j elemts of c
       calculate minimal changes needed to fix c ?


       a = abcd
       b = 1234
       c = 1bcda342
    */

    vector<vector<ll>> dp(a.size() + 1, vector<ll>(b.size() + 1, 0));
    dp[0][0] = 0;

    ll error = 0;
    for(int i = 1; i <= a.size(); i++){ 
        if(c[i - 1] != a[i - 1]) error++;
        dp[i][0] = error;
    }

    error = 0;
    for(int j = 1; j <= b.size(); j++){ 
        if(c[j - 1] != b[j - 1]) error++;
        dp[0][j] = error;
    }

    for(int i = 1; i <= a.size(); i++){
        for(int j = 1; j <= b.size(); j++){
            dp[i][j] = min(dp[i - 1][j] + (c[i + j - 1] != a[i - 1]), dp[i][j - 1] + (c[i + j - 1] != b[j - 1]));
        }
    }


    /*
    for(int i = 0; i <= a.size(); i++){
        for(int j = 0; j <= b.size(); j++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    */


    cout << dp[a.size()][b.size()] << '\n';
    return;
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
/*
   (1) dont start coding until you have a idea that you can take all the to an answer
   (2) at least have some semblence of proof or reasoning for an idea, eg here the dp transitions should make sense
*/
