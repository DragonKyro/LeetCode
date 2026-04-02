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
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<pair<int,int>>> waiting(128);
        for (int i = 0; i < (int)words.size(); i++)
            waiting[words[i][0]].push_back({i, 0});
        int count = 0;
        for (char c : s) {
            auto old = waiting[c];
            waiting[c].clear();
            for (auto [wi, ci] : old) {
                ci++;
                if (ci == (int)words[wi].size()) count++;
                else waiting[words[wi][ci]].push_back({wi, ci});
            }
        }
        return count;
    }
};
