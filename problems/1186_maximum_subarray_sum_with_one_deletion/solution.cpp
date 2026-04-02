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
    int maximumSum(vector<int>& arr) {
        int noDelete = arr[0], oneDelete = INT_MIN / 2, result = arr[0];
        for (int i = 1; i < (int)arr.size(); i++) {
            oneDelete = max(oneDelete + arr[i], noDelete);
            noDelete = max(noDelete + arr[i], arr[i]);
            result = max({result, noDelete, oneDelete});
        }
        return result;
    }
};
