#include <bits/stdc++.h>
using namespace std;

int numberOfWays(int n, int x, int y){
    // n performers
    // x stages
    // [1, y] pay

    // conjecture: ans = sum of (y^(# of nonempty bands in a configuration)) across all band configuration


    // >> 2 2 1 
    // perfomers = (1 2) -> band configuration = (1 2) () | (1) (2) | () (1 2) | (2) (1)
    // so 4 different configurations 1 2 3 4
    // 1^1 + 1^2 + 1^1 + 1^2 =
    // ans = 4


    // >> 1 2 3
    // (1) () | () (1) -> ans = 3^1 + 3^1 = 6

    // >> 5 2 1
    // fact: each performer is in band 1 or band 2.
    // 2^5 possible configurations.
    // eaxctly two configurations have an empty band, namely () (1 2 3 4 5) and (1 2 3 4 5) ()
    // 30 configurations have 2 nonemptty bands. 2 configurations have 1 nonempty band 
    // -> 1^2 * 30 + 1^1 * 2 = 32


    // can we actually sum across all band configuartion?
    // 1 <= n, x, y <= 1000 
    // # of band configuration = x^n so probably not

    // fact: 0 <= # of nonempty bands in a configuration <= x
    // want to efficiently calculate (# of configurations with 0 non empty bands),  (# of configurations with 1 non empty bands), ... ,(# of configurations with x non empty bands)
    // cost = (cost to calculate # of configurations with i non empty bands) * (x + 1) doable?

    // how to calculate (# of configuration with i non empty bands) ?
    // pascals triangle? binomial coeffcient? 

    // 3 performers 4 stages

    // # of config with 0 non empty bands = 0 since performers < stages 
    // # something to do with choose ? 

    // # of config with 1 non empty
    // (1 2 3) () () () | () (1 2 3) () () | () () (1 2 3) () | () () () (1 2 3) 
    // 0 0 0 3 -> 4!/(3!1!) = 24/6 = 4 ways
    // # of ways to split 3 into 1 group is 1
    // -> 4 * 1 = 4

    // # of config with 2 non empty
    // if 2 non empty then nessecarily 0 0 1 2 is how the guys are distributed
    // 0 0 1 2 -> 4!/(2!1!1!) = 24/2 = 12 ways
    // # of ways to split 3 into group of 1 and 2 is 3!/(1!2!) = 6/2 = 3
    // -> 12 * 3 = 36

    // # of config with 3 non empty
    // if 3 non empty then nessecarily 0 1 1 1 is how the guys are distributed
    // 0 1 1 1 -> 4!/(1!3!) = 24/6 = 4
    // # of ways to split 3 into group of 1 and 2 is 3!/(1!2!) = 6/2 = 3
    // -> 12 * 3 = 36


    // n performers, k stages

    // # of config with 1 nonempty 
    // 








}
