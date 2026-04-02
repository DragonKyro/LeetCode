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
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> curr;
        for (int i = 1; i <= 9; i++) curr.push_back(i);
        for (int level = 1; level < n; level++) {
            vector<int> next;
            for (int num : curr) {
                int last = num % 10;
                if (last + k <= 9) next.push_back(num * 10 + last + k);
                if (k != 0 && last - k >= 0) next.push_back(num * 10 + last - k);
            }
            curr = next;
        }
        return curr;
    }
};
