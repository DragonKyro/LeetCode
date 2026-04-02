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
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        for (int i = 0; i < k; i++) {
            int top = pq.top(); pq.pop();
            pq.push(top - top / 2);
        }
        int sum = 0;
        while (!pq.empty()) { sum += pq.top(); pq.pop(); }
        return sum;
    }
};
