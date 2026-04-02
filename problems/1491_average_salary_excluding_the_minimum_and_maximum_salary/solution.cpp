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
    double average(vector<int>& salary) {
        int mn = *min_element(salary.begin(), salary.end());
        int mx = *max_element(salary.begin(), salary.end());
        double sum = accumulate(salary.begin(), salary.end(), 0.0);
        return (sum - mn - mx) / (salary.size() - 2);
    }
};
