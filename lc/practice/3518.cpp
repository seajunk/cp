#include <bits/stdc++.h>
using namespace std;


// overflow at like n>=15 lol.
long double factorial(long double n){
    long double r = 1;
    for(long double i = 1; i <= n; i++) r *= i;
    return r;
}

string smallestPalindrome(string s, long double k) {
    int n = s.size();

    map<long double, long double> cnt;

    for(long double i = 0; i < n/2; i++){
        if(cnt.find(s[i]) == cnt.end()) cnt[s[i]] = 1;
        else cnt[s[i]]++;
    }

    vector<char> a(n/2);
    long double lb = 1;

    for(long double i = 0; i < n/2; i++){
        //cout << i << '\n';
        bool found = false;

        // O(26)
        for(auto p : cnt){
            char c = p.first;

            vector<long double> freq;
            for(auto temp : cnt){
                if(temp.first == c)  freq.push_back(temp.second - 1);
                else freq.push_back(temp.second);
            }

            long double perm = 1.0;
            long double temp = 1;
            for(auto f : freq){
                for(long double j = 1; j <= f; j++){
                    perm *= temp / j;
                    temp++;
                    //cout << k << ' ' << (perm + lb) << '\n';

                    if(k < perm + lb){
                        found = true;
                        break;
                    }
                }
                if(found) break;
            }

            // scuffed 
            if(k < perm + lb){
                found = true;
            }

            // setting a[i] = c gets us in [lb, lb + perm) 
            if(!found){
                lb += perm;
            }
            else{
                a[i] = c;
                cnt[c]--;
                if(cnt[c] == 0) cnt.erase(c);
                break;
            }
        }

        if(!found){
            cout << "k too big" << '\n';
            return "";
        }
    }

    string ans(n, 'a');

    for(long double i = 0; i < n/2; i++) ans[i] = a[i];
    if(n % 2 == 1) ans[n/2] = s[n/2];
    for(long double i = 0; i < n/2; i++) ans[n - 1 - i] = a[i];

    cout << ans << '\n';

    return ans;
}

int main(){
    while(true){
        string s; cin >> s;
        long double k; cin >> k;
        smallestPalindrome(s, k);
    }
}
