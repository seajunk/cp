#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){


    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];


    /*
       for some index i in [0, n - 1],


       can make all a[j] st j < i equal to a[i]. costs i * a[i]


       can make all a[j] st j > i equal to a[i]. costs (n - (i + 1)) * a[i]



       nessecarily final value of array has to be some a[i] value


       for a fixed a[i], what is min cost to make a[i] final value ?



       at least a[i] * (n - 1)

       min cost = 
       (1) min amongst doing it on a[i] twice,
       (2) finding longest prefix which only contains a[i] and doing it on its right end
       (3) finding longest suffix which only contains a[i] and doing it on its left end


       we can calculate (1) easily for all values in O(n) time
    */



    ll mn = LLONG_MAX;


    for(int i = 0; i < n; i++){
        mn = min(mn, a[i] * (n - 1));
    }



    vector<vector<ll>> blocks;



    vector<ll> curr = {-1, -1}; // [l, r)
    curr[0] = 0; 


    for(int i = 1; i <= n; i++){
        if(i == n || a[i] != a[curr[0]]){
            curr[1] = i;
            blocks.push_back(curr);
            curr = {i, -1};
        }
    }

    for(auto b : blocks){
        ll len = b[1] - b[0];
        mn = min(mn, a[b[0]] * (n - len));
    }

    cout << mn << '\n';





}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
