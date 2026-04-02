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
    vector<int> evenOddBit(int n) {
        int even = 0, odd = 0, i = 0;
        while (n > 0) { if (n&1) { if (i%2==0) even++; else odd++; } n >>= 1; i++; }
        return {even, odd};
    }
};
