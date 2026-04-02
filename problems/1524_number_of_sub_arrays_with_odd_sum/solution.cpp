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
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1e9 + 7;
        long long odd = 0, even = 1, prefix = 0, res = 0;
        for (int n : arr) {
            prefix += n;
            if (prefix % 2 == 1) { res = (res + even) % MOD; odd++; }
            else { res = (res + odd) % MOD; even++; }
        }
        return res;
    }
};
