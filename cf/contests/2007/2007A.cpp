#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;


ll count_pfactor(ll n){
    ll count = 0;
    while(n%2==0){
        count++;
        n /= 2;
    }

    for(int i = 3; i <= sqrt(n); i += 2){
        while(n % i == 0){
            count++;
            n /= i;
        }
    }
    if(n > 2){
        count++;
    }


    return count;
}

ll gcd(ll a, ll b){
    ll temp = min(a, b);
    while (temp > 0){
        if(a % temp == 0 && b % temp == 0){
            break;
        }
        temp--;
    }
    return temp;
}

// [10, 21] 10 11 12 13 14 15 16 17 18 19 20 21

void solve(){
    ll l, r; cin >> l >> r;
    bool taken[1001] = {false};
    
    vector<ll> a;
    for(int i = l; i <= r; i++) a.push_back(i);
    sort(a.begin(), a.end(), [](auto left, auto right){
            return count_pfactor(left) < count_pfactor(right);
            });














    /*
    ll count = 0;
    ll left = 0, right = a.size() - 1;

    while(left < right){
        if(taken[a[left]]){
            left++;
        }
        else if(taken[a[right]]){
            right--;
        }
        else if(gcd(a[left], a[right]) == 1){
            for(int i = right - 1; i > left; i--){
                if(!taken[i]){
                    if(gcd(a[left] * a[right], a[i]) == 1){
                        taken[a[i]] = true;
                        left++;
                        right--;
                        count++;

                    }
                }
            }
        }
        else{
            right--;
        }
        cout << count << '\n';
    }
    */


    







    /*
    ll count = 0;
    for(int i = 0; i < a.size(); i++){
        ll curr = a[i];
        ll three = 1;
        vector<ll> indices;
        indices.push_back(a[i]);
        for(int j = i + 1; j < a.size(); j++){

            if(!taken[a[j]]){
                if(gcd(curr, a[j]) == 1){
                    curr *=  a[j];
                    indices.push_back(a[j]);
                    three++;
                }
            }

            if(three == 3){
                count++;
                for(auto index : indices) taken[index] = true;
                break;
            }
        }
    }
    cout << count << '\n';
    */
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
