#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string x, y; cin >> x >> y;
    

    // 13 34  

    // heur: generally want x and y to be as close as possible

    // conj: minimizing difference of x and y -> maximizing their product

    // 1 2 3
    // 3 2 1

    ll n = x.size();

    // x >= y
    bool first = true;
    for(int i = 0; i < n; i++){
        if(x[i] == y[i]) continue;


        if(first){
            if(x[i] < y[i]) swap(x[i], y[i]);
            first = false;
        }
        else{
            if(y[i] < x[i]) swap(x[i], y[i]);
        }
    }

    cout << x << ' ' << y << '\n';
    





}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
