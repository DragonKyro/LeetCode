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
    bool canArrange(vector<int>& arr, int k) {
        vector<int> rem(k, 0);
        for (int n : arr) rem[((n % k) + k) % k]++;
        if (rem[0] % 2 != 0) return false;
        for (int i = 1; i <= k / 2; i++) {
            if (i == k - i) { if (rem[i] % 2 != 0) return false; }
            else { if (rem[i] != rem[k - i]) return false; }
        }
        return true;
    }
};
