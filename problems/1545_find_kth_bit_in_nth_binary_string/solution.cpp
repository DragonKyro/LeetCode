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
    char findKthBit(int n, int k) {
        if (n == 1) return '0';
        int length = (1 << n) - 1;
        int mid = length / 2 + 1;
        if (k == mid) return '1';
        else if (k < mid) return findKthBit(n - 1, k);
        else return findKthBit(n - 1, length - k + 1) == '0' ? '1' : '0';
    }
};
