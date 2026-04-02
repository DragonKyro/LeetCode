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
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> parts;
        backtrack(s, 0, parts, result);
        return result;
    }

    void backtrack(string& s, int start, vector<string>& parts, vector<string>& result) {
        if (parts.size() == 4) {
            if (start == (int)s.size()) {
                string ip = parts[0] + "." + parts[1] + "." + parts[2] + "." + parts[3];
                result.push_back(ip);
            }
            return;
        }
        for (int len = 1; len <= 3 && start + len <= (int)s.size(); len++) {
            string segment = s.substr(start, len);
            if ((segment[0] == '0' && len > 1) || stoi(segment) > 255) continue;
            parts.push_back(segment);
            backtrack(s, start + len, parts, result);
            parts.pop_back();
        }
    }
};
