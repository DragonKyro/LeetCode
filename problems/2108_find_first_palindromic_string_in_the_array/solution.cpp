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
    string firstPalindrome(vector<string>& words) {
        for (const string& w : words) {
            string rev(w.rbegin(), w.rend());
            if (w == rev) return w;
        }
        return "";
    }
};
