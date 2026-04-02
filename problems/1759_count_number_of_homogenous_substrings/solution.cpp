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
    int countHomogenous(string s) {
        long long MOD = 1e9 + 7, result = 0, count = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) count++;
            else { result += count * (count + 1) / 2; count = 1; }
        }
        result += count * (count + 1) / 2;
        return result % MOD;
    }
};
