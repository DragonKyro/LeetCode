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
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i = s.size() - 2;
        while (i >= 0 && s[i] >= s[i + 1]) i--;
        if (i < 0) return -1;
        int j = s.size() - 1;
        while (s[j] <= s[i]) j--;
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        long long val = stoll(s);
        return val <= INT_MAX ? (int)val : -1;
    }
};
