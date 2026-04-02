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
    int numDupDigitsAtMostN(int n) {
        vector<int> digits;
        int temp = n + 1;
        while (temp > 0) { digits.insert(digits.begin(), temp % 10); temp /= 10; }
        int k = digits.size(), count = 0;
        for (int i = 1; i < k; i++) count += 9 * perm(9, i - 1);
        set<int> seen;
        for (int i = 0; i < k; i++) {
            int d = digits[i];
            for (int x = (i == 0 ? 1 : 0); x < d; x++)
                if (!seen.count(x)) count += perm(9 - i, k - i - 1);
            if (seen.count(d)) break;
            seen.insert(d);
        }
        return n - count;
    }
    int perm(int n, int k) {
        int res = 1;
        for (int i = 0; i < k; i++) res *= (n - i);
        return res;
    }
};
