#include <bits/stdc++.h>
using namespace std;


// TODO: figure out the O(n) solution
int solve(vector<int> &heights){
    int n = heights.size();
    int temp;

    int k = 0;
    temp = n;
    while(temp > 1){
        temp /= 2;
        k++;
    }

    int st[k + 1][n];


    for(int i = 0; i < n; i++) st[0][i] = heights[i];

    for(int i = 1; i <= k; i++){
        for(int j = 0; j + (1 << i) - 1 < n; j++) st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }

    int lg[n + 1];
    lg[1] = 0;
    for(int i = 2; i <= n; i++) lg[i] = lg[i/2] + 1;



    int ans = INT_MIN;
    for(int i = 0; i < n; i++){
        int lo, hi;
        int l, r;
        // get r

        lo = i; hi = n;
        while(lo < hi){
            int mid = (hi - lo) / 2 + lo;

            temp = lg[mid - i + 1];

            // min of [i, mid]
            int mn = min(st[temp][i], st[temp][mid - (1 << temp) + 1]);

            // want first value less than h[i]
            if(mn >= heights[i]) lo = mid + 1; 
            else hi = mid;
        }
        r = lo;

        lo = -1; hi = i;
        while(lo < hi){
            // ceil div?
            int mid = (hi - lo + 1)/2 + lo;
            temp = lg[i - mid + 1];

            // min of [mid, i]
            int mn = min(st[temp][mid], st[temp][i - (1 << temp) + 1]);

            // want first value less than h[i]
            if(mn >= heights[i]) hi = mid - 1;
            else lo = mid;
        }

        l = lo;


        ans = max(ans, heights[i] * (r - l - 1));

    }
    return ans;
}

int main(){
    vector<int> heights = {2, 4};
    cout << solve(heights) << '\n';

    // 2 1 5 6 2 3
}



