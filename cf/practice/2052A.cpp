#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll n; cin >> n; // n <= 1000
    ll c[n];
    for(int i = 0; i < n ;i++) cin >> c[i];


    /*
       literally just simulate it ?
    */


    vector<ll> start(n);
    for(int i = 0; i < n; i++) start[i] = i + 1;

    map<ll, ll> idx; // stupid but whatever 
    for(int i = 0; i < n; i++) idx[start[i]] = i;

    vector<vector<ll>> ans;

    for(int i = 0; i < n; i++){
        ll curr = idx[c[i]];


        // go right
        while(curr != n - 1){
            ans.push_back({start[curr + 1], start[curr]});
            swap(start[curr + 1], start[curr]);
            idx[start[curr]] = curr;
            idx[start[curr + 1]] = curr + 1;
            curr += 1;
        }

        // go left
        while(curr != i){
            ans.push_back({start[curr], start[curr - 1]});
            swap(start[curr], start[curr - 1]);
            idx[start[curr]] = curr;
            idx[start[curr - 1]] = curr - 1;
            curr -= 1;
        }
    }


    cout << ans.size() << '\n'; // this is kinda lazy

    for(auto e : ans) cout << e[0] << ' ' << e[1] << '\n';




    /*
       2 3 1

       1 2 3
       2 3 1

    */





}



void attempt1(){
    ll n; cin >> n;
    ll c[n];
    for(int i = 0; i < n; i++) cin >> c[i];


    /*
       start with

       1 2 3 4 5 ...
       end with c

       x and y can swap at most twice
       what is maximum number of swaps to get from start to c?


       reminds me of group theory



       say we have the permutation
       c = 3 1 2 5 4

       then we can decompose into the cycles.
       (3 2 1) (5 4)

       if two numbers are in different cycles, we can swap them twice to increase our answer for free.

       we need size of cycles - 1 swaps to fix the cycle, 
       namely in cycle of size m, a
       (a[0], a[1],  ..., a[m - 1]) 
       we swap a[0], a[1]. this reduces the cycle down to (a[1], ..., a[m - 1])
       just keep swapping a[i] and a[i + 1] until cycle is cleared

       this means a[i], a[i + 1] can not swap again 
       so the cycle a can create 
       |a|*(|a|-1) - (|a|-1) 
       |a|^2 - |a| - |a| + 1
       |a|^2 - 2|a| + 1
       (|a| - 1)^2

       another interpretation, number of swaps to fix, then number of swaps we can perform with pairs of elements who havent been swapped
       (|a| - 1) + (|a| - 1)*(|a| - 2)
       = (|a| - 1)(|a| - 1)
       = (|a| - 1)^2

       This is max cycle becuase, to fix a, then there exists sequence of values in cycle such that each consecutive element have been swapped during the fixing procedure.(proof needed)
       so the cycle must produce at least |a| - 1 cycles.
       note also that these pairs in the sequence can not be swapped again since array is now fixed. So cycle can produce at most (max value - |a| - 1) and max value is (|a - 1|*|a|)(proof needed.)

       In our procedure this value is achieved, thus it is optimal.

       Solution is to

       get all cycles,
       swap every pair of numbers which arent in the same cycle twice.

       then for each cycle, swap the ith guy with every j > i + 1 th guy twice, then swap ith guy with i + 1th guy once
    */



    vector<bool> seen(n + 1, false);
    vector<vector<ll>> cycles;

    for(int i = 0; i < n; i++){
        if(seen[c[i]]) continue;
        vector<ll> cycle;

        ll curr = c[i];
        while(!seen[curr]){
            seen[curr] = true;
            cycle.push_back(curr);
            curr = c[curr - 1];
        }

        cycles.push_back(cycle);
        cycle = {};
    }

    ll count = 0;

    for(auto cycle : cycles){
        count += (cycle.size() - 1)*(cycle.size() - 1);
        count += (n - cycle.size())*cycle.size();
    }


    cout << count << '\n';

    for(int i = 0; i < cycles.size(); i++){
        for(auto a : cycles[i]){
            for(int j = i + 1; j < cycles.size(); j++){
                for(auto b : cycles[j]){
                    if(a >= b) swap(a, b);
                    cout << b << ' ' << a << '\n';
                    cout << a << ' ' << b << '\n';
                }
            }
        }
    }

    for(auto cycle : cycles){
        for(int i = 2; i < cycle.size(); i++){
            ll a = cycle[i];
            ll b = cycle[i - 2];
            if(a >= b) swap(a, b);
            cout << b << ' ' << a << '\n';
            cout << a << ' ' << b << '\n';
        }

        for(int i = cycle.size() - 1; i >= 1; i--){
            ll a = cycle[i];
            ll b = cycle[i - 1];
            cout << b << ' ' << a << '\n'; 
        }
    }


    /*






    */




}
