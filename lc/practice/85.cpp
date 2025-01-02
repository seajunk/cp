#include <bits/stdc++.h>
using namespace std;

int maximalRectangle(vector<vector<char>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    // n, m <= 200

    // reduces to largest rectangle?

    int sf[n][m + 1]; //sf[i][j] = length of longest contiguous ones starting at index j in [j, m) of row i

    for(int i = 0; i < n; i++) sf[i][m] = 0;

    for(int i = 0; i < n; i++){
        for(int j = m - 1; j >= 0; j--){
            if(matrix[i][j] == '1') sf[i][j] = sf[i][j + 1] + 1;
            else sf[i][j] = 0;
        }
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j <= m; j++) cout << sf[i][j];
        cout << '\n';
    }


    int ans = 0;

    for(int j = 0; j < m; j++){
        // largest rectangle on jth column of sf
        // monotonic stack?


        int a[n]; 
        for(int i = 0; i < n; i++) a[i] = sf[i][j]; 
        stack<pair<int, int>> s;




        int left[n]; // left[i] = index of first guy smaller than a[i] left of i
        left[0] = -1;
        s.push({a[0], 0});
        for(int i = 1; i < n; i++){
            while(s.size() && (s.top().first >= a[i])) s.pop();
            if(s.size() == 0) left[i] = -1;
            else left[i] = s.top().second;
            s.push({a[i], i});
        }
        while(s.size()) s.pop();


        int right[n]; // right[i] = index of first guy smaller than a[i] right of i
        right[n - 1] = n;
        s.push({a[n - 1], n - 1});
        for(int i = n - 2; i >= 0; i--){
            while(s.size() && (s.top().first >= a[i])) s.pop();
            if(s.size() == 0) right[i] = n;
            else right[i] = s.top().second;
            s.push({a[i], i});
        }


        int currans = 0;

        for(int i = 0; i < n; i++){
            int temp = a[i] * (right[i] - left[i] - 1);
            currans = max(currans, temp);
        }
        cout << currans << '\n';
        ans = max(ans, currans);

    }
    return ans;
}

