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
    int countOperations(int num1, int num2) {
        int ops = 0;
        while (num1 != 0 && num2 != 0) {
            if (num1 >= num2) num1 -= num2;
            else num2 -= num1;
            ops++;
        }
        return ops;
    }
};
