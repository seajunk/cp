#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll d[n];
    for(int i = 0; i < n; i++) cin >> d[i];
    ll l[n], r[n];
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i]; 


    ll lb[n + 1], ub[n + 1];
    lb[0] = 0, ub[0] = 0; // [lb, ub] is range of values our drones can be at i


    for(int i = 0; i < n; i++){
        if(d[i] == 0){
            lb[i + 1] = lb[i];
            ub[i + 1] = ub[i];
        }
        else if(d[i] == 1){
            lb[i + 1] = lb[i] + 1;
            ub[i + 1] = ub[i] + 1;
        }
        else if(d[i] == -1){
            lb[i + 1] = lb[i];
            ub[i + 1] = ub[i] + 1;
        }



        if(max(lb[i + 1], l[i]) > min(ub[i + 1], r[i])){
            cout << -1 << '\n';
            return;
        }

        lb[i + 1] = max(lb[i + 1], l[i]);
        ub[i + 1] = min(ub[i + 1], r[i]);

    }




    for(int i = n; i >= 1; i--){
        if(d[i - 1] == 1){
            lb[i - 1] = lb[i] - 1;
        }
        else if(d[i - 1] == 0){
            lb[i - 1] = lb[i];
        }
        else{
            lb[i - 1] = max(lb[i] - 1, lb[i - 1]);
        }
    }



    for(int i = 0; i < n; i++) cout << lb[i + 1] - lb[i] << ' ';
    cout << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

