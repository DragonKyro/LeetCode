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
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> map;
        for (int i = 0; i < words.size(); i++) map[words[i]] = i;
        vector<vector<int>> res;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j <= (int)words[i].size(); j++) {
                string prefix = words[i].substr(0, j);
                string suffix = words[i].substr(j);
                if (isPalin(prefix)) {
                    string rev = suffix;
                    reverse(rev.begin(), rev.end());
                    if (map.count(rev) && map[rev] != i)
                        res.push_back({map[rev], i});
                }
                if (j != (int)words[i].size() && isPalin(suffix)) {
                    string rev = prefix;
                    reverse(rev.begin(), rev.end());
                    if (map.count(rev) && map[rev] != i)
                        res.push_back({i, map[rev]});
                }
            }
        }
        return res;
    }
    bool isPalin(string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) if (s[l++] != s[r--]) return false;
        return true;
    }
};
