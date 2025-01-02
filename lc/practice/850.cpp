#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int rectangleArea(vector<vector<int>> &rectangles){

    set<ll> y;

    for(auto r : rectangles){
        y.insert(r[1]);
        y.insert(r[3]);
    }

    ll ans = 0;
    sort(rectangles.begin(), rectangles.end(), [](auto l, auto r){
            return l[0] < r[0];
            });

    for(auto ity = next(y.begin()); ity != y.end(); ity++){
        ll height = *ity - *prev(ity);
        ll prevx = INT_MIN;

        for(auto r : rectangles){
            if(r[1] >= *ity) continue; 
            if(r[3] <= *prev(ity)) continue;
            ans += (max(prevx, (ll)r[2]) - max(prevx, (ll)r[0])) * height;
            prevx = max(prevx, (ll)r[2]);
        }
    }

    return ans % 1000000007;
}
