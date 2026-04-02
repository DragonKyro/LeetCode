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
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> wordMasks;
        for (auto& word : words) {
            int mask = 0;
            for (char c : word) mask |= 1 << (c - 'a');
            if (__builtin_popcount(mask) <= 7) wordMasks[mask]++;
        }
        vector<int> result;
        for (auto& puzzle : puzzles) {
            int first = 1 << (puzzle[0] - 'a');
            int mask = 0;
            for (char c : puzzle) mask |= 1 << (c - 'a');
            int count = 0;
            for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
                if (sub & first) {
                    auto it = wordMasks.find(sub);
                    if (it != wordMasks.end()) count += it->second;
                }
            }
            result.push_back(count);
        }
        return result;
    }
};
