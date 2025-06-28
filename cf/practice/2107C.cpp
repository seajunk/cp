#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    ll neg_inf = -1 * 1e18;

    /*
       need to confirm if possible to fill in missing a values so that max subarray sum is exactly k


       lemma 1.
       possible ->
       no fully defined subarray whose sum is > k exists
       AND
       either there exists a fully defined subarray whose sum is k OR there exists atleast one undefined a value

       proof.
       suppose the conclusion is false
       case 1. there exists a fully defined subarray whose sum is > k.
       clearly doesnt work
       case 2. doesnt exist a fully defined subarray whose sum is > k.
       then by our assumption we have that there does not exist a fully defined subarray whose sum is k and there does not exist any undefined values. clearly this case also doesnt work
       /blacksquare



       lemma 2. 
       no fully defined subarray whose sum is > k exists
       AND
       either there exists a fully defined subarray whose sum is k OR there exists atleast one undefined a value 
       -> possible


       is lemma 2 true ?

       assuming the premise, can we be put in a situation where any choice of the unkown a's force us to create a subarray with sum > k ?

       k = 10, s = 110011

       a = 5 5 ? 3 7 

       can we just set k to negative infinity ?

       then the proof is ...
       suppose the premise, 

       case 1: there exists a fully defined subarray whose sum is k
       then set all k to negative infinity. then only the subarrays who are initally fully defined will have a sum > negative infinity. so maximum doesnt change ie it stays as k 

       case 2: there doesnt exist a fully define sum whose sum is k
       then by our premise we have that there is atleast one undefined value


       choose exactly one of the undefined values to be our positive value that gives us degree of freedom over sum

       set every other undefined value to S where S is the sum of all -|a[i]| for defined a[i] values. 

       how to choose our positive value ?

       we need to find the subarray with the largest sum which includes positive value

       get prefix sum and suffix sum originating from positive ? then the max subarray including positive is the combination of the prefix max array and suffix max array ?

       eg 
       a = -1 1 0 -1 3 ,positive = 2
       then
       pfsmx = [1, 0], sfmx = [0, -1, 3]
       so max array include positive is 
       [1 0 -1 3]

       then get the sum T of this value. set a[positive] = k - T
       this should work 



       so we have that 

       array works 
    if and only if 
        no fully defined array with sum > k exists ANS (there is a fully defined array with sum = k or atleast one undefined value exist)

        */


        // first we need to check existance of fully defined array with sum > k

        bool defined_eq_k = false;
        vector<ll> defined;
        for(int i = 0; i <= n; i++){
            if(i == n || s[i] == '0'){

                // get max subarray sum of defined
                if(defined.size() == 0) continue;

                vector<ll> dp(defined.size(), LLONG_MIN); // dp[j] = max sum over subarrays of the form [k, j] for 0 <= k <= j
                // can do this in O(1) memory but this approach logic more explicit and easier to understand for me
                dp[0] = defined[0];

                for(int j = 1; j < defined.size(); j++){
                    if(defined[j] > dp[j - 1] + defined[j]) dp[j] = defined[j]; 
                    else dp[j] = dp[j - 1] + defined[j];
                }

                ll mxsum = LLONG_MIN;
                for(auto e : dp) mxsum = max(mxsum, e);

                if(mxsum > k){
                    //cout << "max sum on defined subarray is too big\n";
                    cout << "NO\n";
                    return;
                }


                // also see if defined has as subarray sum equal to k while were at it 
                set<ll> pfs;
                ll curr = 0;
                pfs.insert(curr);
                for(int j = 1; j <= defined.size(); j++){
                    curr += defined[j - 1]; // defined[0, j)
                    if(pfs.find(curr - k) != pfs.end()) defined_eq_k = true;
                    pfs.insert(curr);
                }


                defined.clear();
            }
            else defined.push_back(a[i]);
        }

        // at this point we have confimred no defined subarray has sum > k


        if(defined_eq_k){
            // at this point we have that there exists a defined subarray with sum exactly equal to k

            cout << "YES\n";

            for(int i = 0; i < n; i++){
                if(s[i] == '1') cout << a[i] << ' ';
                else cout << neg_inf << ' ';
            }
            cout << '\n';

            return;
        }



        // at this point we have that there is no defined subarray with sum equal to k


        ll unkown_cnt = 0;
        for(int i = 0; i < n; i++) if(s[i] == '0') unkown_cnt++;


        if(unkown_cnt == 0){
            //cout << "no unkown values\n";
            cout << "NO\n";
            return;
        }


        // at this point there exists atleast one unkown value

        ll positive = -1;


        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                positive = i;
                break;
            }
        }

        assert(positive != -1);

        // set every unkown value not positive to S


        ll S = 0; // as defined in case 2 of proof for lemma 2. *note we negative infinity(-1 * 1e18) since positive will need to "cancel out" all these values, so choosing neg inf will make positive too big

        vector<ll> ans(n, 0);

        for(int i = 0; i < n; i++) S += -1 * abs(a[i]);
        for(int i = 0; i < n; i++){
            if(s[i] == ' ' && i != positive) ans[i] = S;
            else ans[i] = a[i];
        }


        ll pfsum = 0, sfsum = 0, pfsummx = 0, sfsummx = 0;

        for(int i = positive - 1; i >= 0; i--){
            pfsum += a[i];
            pfsummx = max(pfsummx, pfsum);
        }

        for(int i = positive + 1; i < n; i++){
            sfsum += a[i];
            sfsummx = max(sfsummx, sfsum);
        }


        // max sum of subarray including positive is pfsummx + sfsummx
        ll T = pfsummx + sfsummx + a[positive]; 



        ans[positive] = k - T;



        cout << "YES\n";
        for(int i = 0; i < n; i++) cout << ans[i] << ' ';
        cout << '\n';

        // absolute cluster fuck

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
