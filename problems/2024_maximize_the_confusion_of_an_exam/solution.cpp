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
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxConsec(answerKey, k, 'T'), maxConsec(answerKey, k, 'F'));
    }
    int maxConsec(string& s, int k, char ch) {
        int left = 0, count = 0, result = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            if (s[right] != ch) count++;
            while (count > k) {
                if (s[left] != ch) count--;
                left++;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};
