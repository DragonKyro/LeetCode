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
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        for (int i = 0; i < k; i++) { int v = pq.top(); pq.pop(); pq.push((int)sqrt(v)); }
        long long sum = 0;
        while (!pq.empty()) { sum += pq.top(); pq.pop(); }
        return sum;
    }
};
