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
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = potions.size();
        vector<int> result;
        for (int spell : spells) {
            int left = 0, right = n;
            while (left < right) {
                int mid = (left + right) / 2;
                if ((long long)spell * potions[mid] >= success) right = mid;
                else left = mid + 1;
            }
            result.push_back(n - left);
        }
        return result;
    }
};
