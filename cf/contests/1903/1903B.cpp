#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    // 000 011 011 101 
    // 011 000 011 111 
    // 011 011 000 111 
    // 101 111 111 000 

    // ith guy is intersection of every guy in ith row

    // 001 011 011 101

    // 000 000 001
    // 000 000 000 
    // 001 000 000

    ll n; cin >> n;
    ll M[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> M[i][j];
    }


    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(M[i][j] != M[j][i]){
                cout << "NO\n";
                return;
            } 
        }
    }

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        int temp = 1073741823;
        for(int j = 0; j < n; j++) if(i != j) temp &= M[i][j];
        a[i] = temp;
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if((a[i] | a[j]) != M[i][j]){
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
    for(int e : a) cout << e << ' ';
    cout << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
