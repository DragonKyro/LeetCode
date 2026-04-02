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
    string decodeAtIndex(string s, int k) {
        long size = 0;
        for (char c : s) {
            if (isdigit(c)) size *= c - '0';
            else size++;
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            k %= size;
            if (k == 0 && isalpha(s[i])) return string(1, s[i]);
            if (isdigit(s[i])) size /= s[i] - '0';
            else size--;
        }
        return "";
    }
};
