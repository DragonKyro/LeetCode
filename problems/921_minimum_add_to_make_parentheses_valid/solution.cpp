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
    int minAddToMakeValid(string s) {
        int openNeeded = 0, closeNeeded = 0;
        for (char c : s) {
            if (c == '(') closeNeeded++;
            else if (closeNeeded > 0) closeNeeded--;
            else openNeeded++;
        }
        return openNeeded + closeNeeded;
    }
};
