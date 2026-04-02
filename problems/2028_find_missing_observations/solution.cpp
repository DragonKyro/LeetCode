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
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        for (int r : rolls) sum += r;
        int total = mean * (rolls.size() + n) - sum;
        if (total < n || total > 6 * n) return {};
        int base = total / n, remainder = total % n;
        vector<int> result(n, base);
        for (int i = 0; i < remainder; i++) result[i]++;
        return result;
    }
};
