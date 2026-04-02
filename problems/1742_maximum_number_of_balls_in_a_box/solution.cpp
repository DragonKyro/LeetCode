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
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> boxes;
        int maxCount = 0;
        for (int i = lowLimit; i <= highLimit; i++) {
            int sum = 0, n = i;
            while (n > 0) { sum += n % 10; n /= 10; }
            boxes[sum]++;
            maxCount = max(maxCount, boxes[sum]);
        }
        return maxCount;
    }
};
