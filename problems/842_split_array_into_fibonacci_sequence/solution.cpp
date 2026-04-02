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
    vector<int> splitIntoFibonacci(string num) {
        vector<int> result;
        backtrack(num, 0, result);
        return result;
    }
    bool backtrack(string& num, int idx, vector<int>& seq) {
        if (idx == num.size()) return seq.size() >= 3;
        for (int i = idx + 1; i <= num.size(); i++) {
            if (num[idx] == '0' && i > idx + 1) break;
            long val = stol(num.substr(idx, i - idx));
            if (val > INT_MAX) break;
            if (seq.size() >= 2) {
                long sum = (long)seq[seq.size()-1] + seq[seq.size()-2];
                if (val > sum) break;
                if (val < sum) continue;
            }
            seq.push_back((int)val);
            if (backtrack(num, i, seq)) return true;
            seq.pop_back();
        }
        return false;
    }
};
