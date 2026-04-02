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
    int minimumPartition(string s, int k) {
        int parts = 1; long long cur = 0;
        for (char c : s) {
            int d = c - '0'; if (d > k) return -1;
            cur = cur * 10 + d;
            if (cur > k) { parts++; cur = d; }
        }
        return parts;
    }
};
