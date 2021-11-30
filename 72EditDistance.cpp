#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> tables;
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        tables.assign(len1+1, vector<int>(len2+1, -1));
        return dfsDistance(word1, word2, len1, len2);
    }

    int dfsDistance(string& word1, string& word2, int i, int j) {
        if (i == 0) {
            return j;
        }
        if (j == 0) {
            return i;
        }
        if (tables[i][j] != -1) {
            return tables[i][j];
        }
        if (word1[i-1] == word2[j-1]) {
            tables[i][j] = dfsDistance(word1,word2,i-1,j-1);
        } else {
            tables[i][j] = min(dfsDistance(word1,word2,i-1,j), min(dfsDistance(word1,word2,i,j-1),dfsDistance(word1,word2,i-1,j-1))) + 1;
        }
        return tables[i][j];
    }
};

int main() {
    string word1("intention"), word2("execution");
    Solution solu;
    cout << solu.minDistance(word1, word2) << endl;
    return 0;
}