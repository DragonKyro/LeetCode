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
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        backtrack(s, 0, path, result);
        return result;
    }
    void backtrack(string& s, int start, vector<string>& path, vector<vector<string>>& result) {
        if (start == s.size()) {
            result.push_back(path);
            return;
        }
        for (int end = start + 1; end <= s.size(); end++) {
            string sub = s.substr(start, end - start);
            if (isPalindrome(sub)) {
                path.push_back(sub);
                backtrack(s, end, path, result);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) { if (s[l++] != s[r--]) return false; }
        return true;
    }
};
