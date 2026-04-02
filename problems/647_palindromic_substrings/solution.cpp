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
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int d = 0; d <= 1; d++) {
                int l = i, r = i + d;
                while (l >= 0 && r < s.size() && s[l] == s[r]) {
                    count++; l--; r++;
                }
            }
        }
        return count;
    }
};
