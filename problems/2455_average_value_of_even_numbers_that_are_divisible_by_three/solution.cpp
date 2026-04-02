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
    int averageValue(vector<int>& nums) {
        int sum = 0, count = 0;
        for (int n : nums) if (n % 6 == 0) { sum += n; count++; }
        return count == 0 ? 0 : sum / count;
    }
};
