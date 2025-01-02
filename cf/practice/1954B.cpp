#include <iostream>
#define ll long long 
const ll N = 2e5 + 5;
using namespace std;

void solve(){
    ll n, curr, mn, x;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    x = a[0];

    curr = 0;
    mn = 2e5;
    for(int i = 0; i < n; i++){
        if(a[i] == x) curr++;
        else{
            if(curr != 0) mn = min(mn, curr);
            curr = 0;
        }
    }

    if(curr != 0) mn = min(mn, curr);




    cout << ((curr == n ? -1 : mn)) << '\n';




}

int main(){
    ll t;
    cin >> t;
    while(t--) solve();
}

