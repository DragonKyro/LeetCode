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
    string countAndSay(int n) {
        string s = "1";
        for (int k = 1; k < n; k++) {
            string nxt;
            int i = 0;
            while (i < s.size()) {
                int j = i;
                while (j < s.size() && s[j] == s[i]) j++;
                nxt += to_string(j - i) + s[i];
                i = j;
            }
            s = nxt;
        }
        return s;
    }
};
