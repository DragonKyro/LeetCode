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
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto& p : knowledge) mp[p[0]] = p[1];
        string result;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == '(') {
                int j = s.find(')', i);
                string key = s.substr(i + 1, j - i - 1);
                result += mp.count(key) ? mp[key] : "?";
                i = j + 1;
            } else {
                result += s[i++];
            }
        }
        return result;
    }
};
