#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, s1, s2; cin >> n >> s1 >> s2;

    vector<vector<ll>> r(n, vector<ll>(2));

    for(int i = 0; i < n; i++){
        r[i][0] = i;
        cin >> r[i][1];
    }


    /*
       3 1
      colour = 1 2 3 4 5 6 7
       count = 8 6 4 4 4 1 7

       5
       1 7 2 4 3 6
       cost = 1 3 5 

       5 6
       1 7 2 4 3
       cost = 











    */


    sort(r.begin(), r.end(), [](auto l, auto r){ return l[1] < r[1];});



    vector<ll> a, b;



    for(int i = n - 1; i >= 0; i--){
        ll costa = (a.size() + 1) * s1; // costa = the amount of time it would take to find ball r[i][0] if we give first robot r[i][0]
        ll costb = (b.size() + 1) * s2; // costb = the amount of time it would take to find ball r[i][0] if we give second robot r[i][0]

        if(costa < costb){
            a.push_back(r[i][0] + 1);
        }
        else{
            b.push_back(r[i][0] + 1);
        }
    }


    cout << a.size() << '\n';
    for(auto e : a) cout << e << ' ';
    cout << '\n';

    cout << b.size() << '\n';
    for(auto e : b) cout << e << ' ';
    cout << '\n';






}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
