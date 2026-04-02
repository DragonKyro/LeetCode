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
    int generateKey(int num1, int num2, int num3) {
        int res = 0;
        for (int i = 0; i < 4; i++) {
            int d = min({num1 % 10, num2 % 10, num3 % 10});
            res += d * (int)pow(10, i);
            num1 /= 10; num2 /= 10; num3 /= 10;
        }
        return res;
    }
};
