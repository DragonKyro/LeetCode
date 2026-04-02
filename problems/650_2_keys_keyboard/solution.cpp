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
    int minSteps(int n) {
        int result = 0, d = 2;
        while (n > 1) {
            while (n % d == 0) {
                result += d;
                n /= d;
            }
            d++;
        }
        return result;
    }
};
