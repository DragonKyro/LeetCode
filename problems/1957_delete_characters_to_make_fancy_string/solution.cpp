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
    string makeFancyString(string s) {
        string result;
        for (char c : s) {
            int n = result.size();
            if (n >= 2 && result[n - 1] == c && result[n - 2] == c) continue;
            result += c;
        }
        return result;
    }
};
