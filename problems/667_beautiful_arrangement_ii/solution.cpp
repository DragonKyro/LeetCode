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
    vector<int> constructArray(int n, int k) {
        vector<int> result;
        for (int i = 1; i < n - k; i++) result.push_back(i);
        for (int i = 0; i <= k; i++) {
            if (i % 2 == 0) result.push_back(n - k + i / 2);
            else result.push_back(n - i / 2);
        }
        return result;
    }
};
