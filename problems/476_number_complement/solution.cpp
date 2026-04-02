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
    int findComplement(int num) {
        int mask = 0;
        int temp = num;
        while (temp > 0) {
            mask = (mask << 1) | 1;
            temp >>= 1;
        }
        return num ^ mask;
    }
};
