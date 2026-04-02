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
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long> ugly(n);
        ugly[0] = 1;
        int k = primes.size();
        vector<int> idx(k, 0);
        priority_queue<pair<long,int>, vector<pair<long,int>>, greater<>> pq;
        for (int i = 0; i < k; i++)
            pq.push({primes[i], i});
        for (int i = 1; i < n; i++) {
            ugly[i] = pq.top().first;
            while (pq.top().first == ugly[i]) {
                auto [val, j] = pq.top(); pq.pop();
                idx[j]++;
                pq.push({(long)primes[j] * ugly[idx[j]], j});
            }
        }
        return ugly[n - 1];
    }
};
