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
    int countLargestGroup(int n) {
        unordered_map<int,int> groups;
        for (int i = 1; i <= n; i++) {
            int sum = 0, x = i; while (x) { sum += x % 10; x /= 10; }
            groups[sum]++;
        }
        int mx = 0; for (auto& [k,v] : groups) mx = max(mx, v);
        int count = 0; for (auto& [k,v] : groups) if (v == mx) count++;
        return count;
    }
};
