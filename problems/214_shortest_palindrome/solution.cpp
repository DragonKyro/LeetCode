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
    string shortestPalindrome(string s) {
        string rev(s.rbegin(), s.rend());
        string combined = s + "#" + rev;
        vector<int> lps(combined.size(), 0);
        for (int i = 1; i < combined.size(); i++) {
            int j = lps[i - 1];
            while (j > 0 && combined[i] != combined[j]) j = lps[j - 1];
            if (combined[i] == combined[j]) j++;
            lps[i] = j;
        }
        return rev.substr(0, s.size() - lps.back()) + s;
    }
};
