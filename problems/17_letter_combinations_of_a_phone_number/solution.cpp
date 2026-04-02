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
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> phone = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res;
        string path;
        function<void(int)> bt = [&](int idx) {
            if (idx == digits.size()) { res.push_back(path); return; }
            for (char c : phone[digits[idx] - '0']) {
                path.push_back(c);
                bt(idx + 1);
                path.pop_back();
            }
        };
        bt(0);
        return res;
    }
};
