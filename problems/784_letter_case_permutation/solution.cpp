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
    vector<string> letterCasePermutation(string s) {
        vector<string> result = {""};
        for (char c : s) {
            vector<string> next;
            for (auto& r : result) {
                if (isalpha(c)) {
                    next.push_back(r + (char)tolower(c));
                    next.push_back(r + (char)toupper(c));
                } else {
                    next.push_back(r + c);
                }
            }
            result = next;
        }
        return result;
    }
};
