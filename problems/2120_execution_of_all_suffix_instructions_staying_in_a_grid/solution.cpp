#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m = s.size();
        vector<int> result(m);
        map<char, pair<int,int>> moves = {{'L',{0,-1}},{'R',{0,1}},{'U',{-1,0}},{'D',{1,0}}};
        for (int i = 0; i < m; i++) {
            int r = startPos[0], c = startPos[1], count = 0;
            for (int j = i; j < m; j++) {
                r += moves[s[j]].first;
                c += moves[s[j]].second;
                if (r >= 0 && r < n && c >= 0 && c < n) count++;
                else break;
            }
            result[i] = count;
        }
        return result;
    }
};
