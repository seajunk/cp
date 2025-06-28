#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    /*
       in one operation,
       pick some i, a[i] += 1, move a[i] to back of a
       what is lexicograhically smallest we can make a after operations

       we can make improvments iff a is not nondecreasing

       we never want to operate on elements in the first run



       2 1 3
       first run = 1

       1 2 2 1 4
       1 1 4 3 3
       1 1 3 3 5

       5 4 3 2 1





















    */

    ll b[n];
    for(int i = 0; i < n; i++) b[i] = a[i];
    sort(b, b + n);
    vector<ll> first_run;


    for(int i = 0, j = 0; i < n; i++){
        if(a[i] == b[j]){
            first_run.push_back(i);
            j++;
        }
    }


    for(int i = 0; i < n; i++){
        if(i < first_run.size()) continue;
        b[i]++;
    }


    for(int i = 0; i < n; i++) cout << b[i] << ' '; 
    cout << '\n';




}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
