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
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> result(n, 0);
        int count = 0, ops = 0;
        for (int i = 0; i < n; i++) {
            result[i] += ops;
            count += boxes[i] - '0';
            ops += count;
        }
        count = 0; ops = 0;
        for (int i = n - 1; i >= 0; i--) {
            result[i] += ops;
            count += boxes[i] - '0';
            ops += count;
        }
        return result;
    }
};
