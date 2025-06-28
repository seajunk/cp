#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    /*
       There exists atleast i such that a[i] = 1

       The count of values is fixed. 
       -> we know what the final array should look like, ie sorted
       -> 



       2 2 1 0
       2 2 0 1
       1 2 0 2
       0 2 1 2
       0 1 2 2


       moving a guy will take at most 2 operations



       if only 1 2 exist or 0 1 exist, just do it (?)
       if all 0 1 2 exist, issues are when 0 is where 2 should be or 2 is where 0 should be




       first run, 
       two cases
       if all 1's are in correct position do nothing,
       if there exists a 1 in incorrect position, fix every one except for this one


       second run,
       if all 1's are in correct posiiton, fix all pairs of 0 and 2 
       cost <= 2*min(cnt0, cnt2) + 1

       if there exists a 1 in incorrect position, fix all pairs of 0 and 2 using this one cost <= 2*min(cnt0, cnt2) + 1



       case1 cost = # of pairs of 0, 2 which need to be swapped * 2 + 1
       case2 cost = # of incorrect 1's - 1 + # of pairs of 0 2 *2 + 1

    */


    vector<vector<ll>> ans;


    ll cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0) cnt0++;
        else if(a[i] == 1) cnt1++;
        else cnt2++;
    }

    ll fix1 = 0;
    for(int i = 0; i < n; i++){
        if(a[i] != 1) continue;

        if(!(cnt0 <= i && i < cnt0 + cnt1)) fix1++;
    }


    if(fix1 == 0){
        ll original = -1;
        for(int i = 0; i < n; i++){
            if(a[i] == 1){
                original = i;
                break;
            }
        }
        assert(original != -1);



        // this question is really cringe





    }











}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
