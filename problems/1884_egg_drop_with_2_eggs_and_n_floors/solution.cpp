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
    int twoEggDrop(int n) {
        int m = 0, k = 0;
        while (m < n) { k++; m += k; }
        return k;
    }
};
