#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    string s1, s2; cin >> s1 >> s2;

    ll a[2][n];

    for(int i = 0; i < n; i++){
        a[0][i] = s1[i] - '0';
        a[1][i] = s2[i] - '0';
    }

    // 1101
    // 1100

    ll jump = n - 1;
    for(int i = 1; i < n; i++){
        if((a[0][i] == 1) && (a[1][i - 1] == 0)){
            jump = i - 1;
            break;
        }
    }

    ll dup = 1;
    for(int i = jump; i >= 1; i--){
        if(a[0][i] == a[1][i - 1]) dup++;
        else break;
    }


    for(int i = 0; i <= jump; i++){
        cout << a[0][i];
    }
    for(int i = jump; i < n; i++){
        cout << a[1][i];
    }
    cout << '\n';
    cout << dup << '\n';









}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
