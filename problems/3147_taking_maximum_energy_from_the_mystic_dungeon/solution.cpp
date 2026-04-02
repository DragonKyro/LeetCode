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
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size(), res = INT_MIN;
        for (int i = n-1; i >= n-k; i--) {
            int sum = 0;
            for (int j = i; j >= 0; j -= k) {
                sum += energy[j];
                res = max(res, sum);
            }
        }
        return res;
    }
};
