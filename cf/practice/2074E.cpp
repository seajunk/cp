#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;

    ll in = -1;
    vector<ll> points = {1, 2, 3};

    srand(time(0));

    while(true){
        cout << "? ";
        for(ll p : points) cout << p << ' ';
        cout << '\n';

        cout.flush();

        cin >> in;

        if(in == 0) break;

        // complete pseudo science
        points[rand() % 3] = in;
    }

    cout << "! ";
    for(ll p : points) cout << p << ' ';
    cout << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

