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
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), count = 0;
        vector<int> freq(n+1, 0), ans;
        for (int i = 0; i < n; i++) {
            freq[A[i]]++; if (freq[A[i]]==2) count++;
            freq[B[i]]++; if (freq[B[i]]==2) count++;
            ans.push_back(count);
        }
        return ans;
    }
};
