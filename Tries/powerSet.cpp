/*Author : drkspark */
/*Problem Url : https://www.codingninjas.com/codestudio/problems/1062667?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website */
// Power Set Using Bit Manipulation

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pwset(vector<int>v) {
    vector<vector<int>> res;
    sort(begin(v), end(v));
    int n = v.size();
    for (int i = 0; i < (1LL << n); i++) {
        
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            
            if (i & (1 << j)) {
                temp.push_back(v[j]);
            }
        }
    
        res.push_back(temp);
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while(t--) {

        


    }
    return 0;
}