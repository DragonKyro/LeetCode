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
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result;
        for (int n : nums) if (n < pivot) result.push_back(n);
        for (int n : nums) if (n == pivot) result.push_back(n);
        for (int n : nums) if (n > pivot) result.push_back(n);
        return result;
    }
};
