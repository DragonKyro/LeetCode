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
    int findMinFibonacciNumbers(int k) {
        vector<int> fibs = {1, 1};
        while (fibs.back() < k) {
            int sz = fibs.size();
            fibs.push_back(fibs[sz-1] + fibs[sz-2]);
        }
        int count = 0;
        for (int i = fibs.size() - 1; i >= 0 && k > 0; i--) {
            if (fibs[i] <= k) {
                k -= fibs[i];
                count++;
            }
        }
        return count;
    }
};
