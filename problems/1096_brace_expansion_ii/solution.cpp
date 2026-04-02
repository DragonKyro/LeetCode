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
    int idx = 0;
    vector<string> braceExpansionII(string expression) {
        auto result = parse(expression);
        vector<string> ans(result.begin(), result.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
    set<string> parse(string& s) {
        set<string> result;
        set<string> current = {""};
        while (idx < s.size()) {
            if (s[idx] == '{') {
                idx++;
                auto inner = parse(s);
                set<string> next;
                for (auto& a : current) for (auto& b : inner) next.insert(a + b);
                current = next;
            } else if (s[idx] == '}') {
                idx++;
                result.insert(current.begin(), current.end());
                return result;
            } else if (s[idx] == ',') {
                result.insert(current.begin(), current.end());
                current = {""};
                idx++;
            } else {
                int j = idx;
                while (j < s.size() && isalpha(s[j])) j++;
                string word = s.substr(idx, j - idx);
                set<string> next;
                for (auto& a : current) next.insert(a + word);
                current = next;
                idx = j;
            }
        }
        result.insert(current.begin(), current.end());
        return result;
    }
};
