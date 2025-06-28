#include <bits/stdc++.h>
using namespace std;


bool isRectangleCover(vector<vector<int>>& rectangles) {

    int mny = INT_MAX, mnx = INT_MAX;
    int mxy = INT_MIN, mxx = INT_MIN;

    set<int> ys;
    int have = 0;
    for(auto rect : rectangles){
        ys.insert(rect[1]);
        ys.insert(rect[3]);
        have += (rect[2] - rect[0]) * (rect[3] - rect[1]);
        mnx = min(mnx, rect[0]);
        mxx = max(mxx, rect[2]);
        mny = min(mny, rect[1]);
        mxy = max(mxy, rect[3]);
    }
    int need = (mxx - mnx) * (mxy - mny); 





    return have == need;
}
