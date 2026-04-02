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
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        deque<int> idx;
        for (int i = 0; i < n; i++) idx.push_back(i);
        vector<int> result(n);
        for (int card : deck) {
            result[idx.front()] = card;
            idx.pop_front();
            if (!idx.empty()) { idx.push_back(idx.front()); idx.pop_front(); }
        }
        return result;
    }
};
