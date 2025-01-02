#include <bits/stdc++.h>
using namespace std;

vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
    unordered_map<int, int> row, col, diag, adiag;

    set<vector<int>> l;

    for(auto lamp : lamps) l.insert(lamp);

    for(auto lamp : l){

        if(row.find(lamp[0]) == row.end()) row[lamp[0]] = 1;
        else row[lamp[0]]++;

        if(col.find(lamp[1]) == col.end()) col[lamp[1]] = 1;
        else col[lamp[1]]++;

        if(diag.find(lamp[0] - lamp[1]) == diag.end()) diag[lamp[0] - lamp[1]] = 1;
        else diag[lamp[0] - lamp[1]]++;

        if(adiag.find(lamp[0] + lamp[1]) == adiag.end()) adiag[lamp[0] + lamp[1]] = 1;
        else adiag[lamp[0] + lamp[1]]++;
    }

    vector<int> ans;

    for(auto q : queries){

        if(row.find(q[0]) != row.end() || col.find(q[1]) != col.end() || diag.find(q[0] - q[1]) != diag.end() || adiag.find(q[0] + q[1]) != adiag.end()) ans.push_back(1);
        else ans.push_back(0); 

        int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

        if(l.find(q) != l.end()){
            row[q[0]]--;
            if(row[q[0]] == 0) row.erase(q[0]);
            col[q[1]]--;
            if(col[q[1]] == 0) col.erase(q[1]);
            diag[q[0] - q[1]]--;
            if(diag[q[0] - q[1]] == 0) diag.erase(q[0] - q[1]);
            adiag[q[0] + q[1]]--;
            if(adiag[q[0] + q[1]] == 0) adiag.erase(q[0] + q[1]);
            l.erase(q);
        }

        for(int i = 0; i < 8; i++){
            int newr = q[0] + dr[i];
            int newc = q[1] + dc[i];
            if(!(0 <= newr && newr <= n && 0 <= newc && newc < n)) continue;

            vector<int> temp = {newr, newc};
            if(l.find(temp) != l.end()){
                row[temp[0]]--;
                if(row[temp[0]] == 0) row.erase(temp[0]);
                col[temp[1]]--;
                if(col[temp[1]] == 0) col.erase(temp[1]);
                diag[temp[0] - temp[1]]--;
                if(diag[temp[0] - temp[1]] == 0) diag.erase(temp[0] - temp[1]);
                adiag[temp[0] + temp[1]]--;
                if(adiag[temp[0] + temp[1]] == 0) adiag.erase(temp[0] + temp[1]);
                l.erase(temp);
            }
        }
    }





    return ans;
}
