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
    int calPoints(vector<string>& operations) {
        vector<int> stack;
        for (auto& op : operations) {
            int n = stack.size();
            if (op == "+") stack.push_back(stack[n-1] + stack[n-2]);
            else if (op == "D") stack.push_back(2 * stack[n-1]);
            else if (op == "C") stack.pop_back();
            else stack.push_back(stoi(op));
        }
        return accumulate(stack.begin(), stack.end(), 0);
    }
};
