#include <bits/stdc++.h>
using namespace std;


// O(26)
bool subset(unordered_map<char, int> sub, unordered_map<char, int> super){
    for(auto c : sub){
        if(super.find(c.first) == super.end()) return false;
        if(super[c.first] < sub[c.first]) return false;
    }
    return true;
}

string minWindow(string s, string t) {

    /*
       smallest substring of s whose multiset is superset of t
    */

    int n = s.size();
    int m = t.size();

    if(m > n) return "";

    unordered_map<char, int> T;
    for(int i = 0; i < m; i++){
        if(T.find(t[i]) == T.end()) T[t[i]] = 1;
        else T[t[i]]++;
    }

    unordered_map<char, int> S;


    string ans(n + 1, 'a');

    int l = 0;
    for(int r = 1; r <= n; r++){

        if(S.find(s[r - 1]) == S.end()) S[s[r - 1]] = 1;
        else S[s[r - 1]]++;


        // on paper this is constant time
        while(subset(T, S)){
            if(ans.size() > r - l) ans = s.substr(l, r - l); 
            S[s[l]]--;
            if(S[s[l]] == 0) S.erase(s[l]);
            l++;
        }
    }


    if(ans.size() == n + 1) return "";

    cout << ans << '\n';
    return ans;
}
