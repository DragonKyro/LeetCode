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
    int integerReplacement(int n) {
        int count = 0;
        long num = n;
        while (num != 1) {
            if (num % 2 == 0) num >>= 1;
            else if (num == 3 || ((num >> 1) & 1) == 0) num--;
            else num++;
            count++;
        }
        return count;
    }
};
