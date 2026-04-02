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
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> result(num_people, 0);
        int give = 1;
        int i = 0;
        while (candies > 0) {
            result[i % num_people] += min(give, candies);
            candies -= give;
            give++;
            i++;
        }
        return result;
    }
};
