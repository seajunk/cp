#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){

    /*
       given array a of length n, want to see if possible to rearrange elements of a such that after rearranging, 

       a1 mod a2 mod a3 ... mod an-1 != 0

       where mod is left associative here.

       doesnt work if were ever forced to make a zero anywhere in the array. 
       works if we can avoid making a zero anywhere in the array.

       when are we forced into a zero ?

       get smallest element , then check if there exists some guy in a st guy % smalest != 0.

       if guy exists, then works 
       otherwise doesnt work ?
    */

    ll n; cin >> n; 
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i]; 



    ll mn = LLONG_MAX;
    for(int i = 0; i < n; i++){
        mn = min(mn, a[i]);
    }

    ll mncnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == mn) mncnt += 1;
    }

    if(mncnt == 1){
        cout << "Yes\n";
        return;
    }
    // 1234567890

    for(int i = 0; i < n; i++){
        if(a[i] % mn != 0){
            cout << "Yes\n";
            return;
        }
    }

    cout << "No\n";
}

int main(){
    ll t; cin >> t; 
    while(t--) solve();
}
