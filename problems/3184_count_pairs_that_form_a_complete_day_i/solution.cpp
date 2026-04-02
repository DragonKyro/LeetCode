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
    int countCompleteDayPairs(vector<int>& hours) {
        int res = 0;
        for (int i = 0; i < hours.size(); i++)
            for (int j = i+1; j < (int)hours.size(); j++)
                if ((hours[i]+hours[j]) % 24 == 0) res++;
        return res;
    }
};
