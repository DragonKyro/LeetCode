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
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> result;
        for (int a = 1; a <= bound; a = (x == 1) ? bound + 1 : a * x)
            for (int b = 1; a + b <= bound; b = (y == 1) ? bound + 1 : b * y)
                result.insert(a + b);
        return vector<int>(result.begin(), result.end());
    }
};
