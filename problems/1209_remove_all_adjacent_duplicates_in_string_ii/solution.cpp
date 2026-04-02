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
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> stack;
        for (char c : s) {
            if (!stack.empty() && stack.back().first == c) {
                if (++stack.back().second == k) stack.pop_back();
            } else {
                stack.push_back({c, 1});
            }
        }
        string res;
        for (auto& [ch, cnt] : stack) res += string(cnt, ch);
        return res;
    }
};
