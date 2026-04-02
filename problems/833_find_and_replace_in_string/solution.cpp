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
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < indices.size(); i++)
            if (s.substr(indices[i], sources[i].size()) == sources[i])
                mp[indices[i]] = {(int)sources[i].size(), i};
        string result;
        int i = 0;
        while (i < s.size()) {
            if (mp.count(i)) {
                result += targets[mp[i].second];
                i += mp[i].first;
            } else result += s[i++];
        }
        return result;
    }
};
