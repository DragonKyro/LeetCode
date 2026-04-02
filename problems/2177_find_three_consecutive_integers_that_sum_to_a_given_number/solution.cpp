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
    vector<long long> sumOfThree(long long num) {
        if (num % 3 != 0) return {};
        long long mid = num / 3;
        return {mid - 1, mid, mid + 1};
    }
};
