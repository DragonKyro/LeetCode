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
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int num = left; num <= right; num++) {
            bool valid = true;
            int n = num;
            while (n > 0) {
                int d = n % 10;
                if (d == 0 || num % d != 0) { valid = false; break; }
                n /= 10;
            }
            if (valid) result.push_back(num);
        }
        return result;
    }
};
