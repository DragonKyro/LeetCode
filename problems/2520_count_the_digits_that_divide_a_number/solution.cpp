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
    int countDigits(int num) {
        int count = 0, n = num;
        while (n > 0) { if (num % (n%10) == 0) count++; n /= 10; }
        return count;
    }
};
