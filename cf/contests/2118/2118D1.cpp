#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;

    ll p[n];
    for(int i = 0; i < n; i++) cin >> p[i];
    ll d[n];
    for(int i = 0; i < n; i++) cin >> d[i];

    ll q; cin >> q;
    ll a[q];
    for(int i = 0; i < q; i++) cin >> a[q];



    /*
       two graphs with 2 * n + 1 nodes.

       one graph for guy facing left and right
       one extra node to represent exiting


       wlog suppose guy is facing right



       edge (i -> j) exists if guy lands at i and the next light he lands at is j if he continues onwards.



       given, q we simulate until he ends up at a node. then we do cycle detection or something
    */

    sort(p, p + n);


    for(int m = 0; m < q; m++){

        map<vector<ll>, vector<vector<ll>>> adj; // adj[{light position, light state, facing direciton}] = {nodes of the same format}



    for(int i = 0; i < n; i++){

        // considering node curr = {p[i], 0, 0}
        vector<ll> curr = {p[i], 0, 0};

        // curr will have at most one edge? to light p[i + 1] where or will have no edge, which indicates that curr will exit the strip
        if(i != n - 1){ // if i == n - 1, curr will exit strip, so no neighbours

            ll dist = p[i + 1] - p[i]; // guy will get to p[i + 1] after dist seconds. 
            /*
               how to get colour of p[i + 1] when we get there?
               I think a[m] fixes values and lets determine this ?

               FUCKUFRCKUFKCU



            */






        }









    }










    }









}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
