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
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int result = 0;
        int lastM = 0, lastP = 0, lastG = 0;
        for (int i = 0; i < garbage.size(); i++) {
            result += garbage[i].size();
            for (char c : garbage[i]) {
                if (c == 'M') lastM = i;
                else if (c == 'P') lastP = i;
                else lastG = i;
            }
        }
        vector<int> prefix(travel.size() + 1, 0);
        for (int i = 0; i < travel.size(); i++) prefix[i+1] = prefix[i] + travel[i];
        result += prefix[lastM] + prefix[lastP] + prefix[lastG];
        return result;
    }
};
