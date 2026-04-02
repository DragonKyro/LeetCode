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
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        string v = "aeiou";
        vector<int> pre(words.size()+1, 0);
        for (int i = 0; i < words.size(); i++)
            pre[i+1] = pre[i] + (v.find(words[i].front())!=string::npos && v.find(words[i].back())!=string::npos ? 1 : 0);
        vector<int> ans;
        for (auto& q : queries) ans.push_back(pre[q[1]+1] - pre[q[0]]);
        return ans;
    }
};
