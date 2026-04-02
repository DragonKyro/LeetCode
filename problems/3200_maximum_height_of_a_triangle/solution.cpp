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
    int maxHeightOfTriangle(int red, int blue) {
        auto check = [](int a, int b) {
            int row = 1;
            while (true) {
                if (row%2==1) { a-=row; if (a<0) return row-1; }
                else { b-=row; if (b<0) return row-1; }
                row++;
            }
        };
        return max(check(red, blue), check(blue, red));
    }
};
