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
    int pivotInteger(int n) {
        int total = n * (n + 1) / 2;
        int x = sqrt(total);
        return x * x == total ? x : -1;
    }
};
