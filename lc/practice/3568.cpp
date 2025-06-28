#include <bits/stdc++.h>
using namespace std;



int minMoves(vector<string>& classroom, int energy) {
    int m = classroom.size();
    int n = classroom[0].size();


    /*

       m in [1, 20]
       n in [1, 20]
       energy in [1, 50]

       let litters and starting points be nodes in graph G

       then for nodes i, j, and energy k, 

       dp[i][j][k] = min number of moves to get from node i to node j starting with k eenergy


       we can consider dp[i][j][k] as the weight of edge (i -> j) in G


       ans1 = min number of moves to get all litter
       ans2 = min weight of hamiltonian path starting from node S

       are ans1 and ans2 same ?

       claim. ans1 = ans2
       proof. suppose by cont that claim is false.
       so ans1 != ans2.

       case 1. energy is infinite(big enough that we dont have to consider third argument of dp, ie energy is big enoug that for fixed i, j, dp[i][j][k] = dp[i][j][l] for any pair l, k)
       since ans1 != ans2, 













    */






    return -1;
}
