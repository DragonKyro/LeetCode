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
    int lastRemaining(int n) {
        bool left = true;
        int remaining = n, step = 1, head = 1;
        while (remaining > 1) {
            if (left || remaining % 2 == 1) head += step;
            remaining /= 2;
            step *= 2;
            left = !left;
        }
        return head;
    }
};
