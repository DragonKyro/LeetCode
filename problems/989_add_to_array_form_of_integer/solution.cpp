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
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i = num.size() - 1, carry = k;
        vector<int> result;
        while (i >= 0 || carry > 0) {
            if (i >= 0) carry += num[i--];
            result.push_back(carry % 10);
            carry /= 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
