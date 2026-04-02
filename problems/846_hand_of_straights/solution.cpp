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
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize) return false;
        map<int, int> counts;
        for (int c : hand) counts[c]++;
        while (!counts.empty()) {
            int first = counts.begin()->first;
            for (int i = 0; i < groupSize; i++) {
                if (!counts.count(first + i)) return false;
                if (--counts[first + i] == 0) counts.erase(first + i);
            }
        }
        return true;
    }
};
