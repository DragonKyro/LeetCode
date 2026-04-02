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
    int maximumPrimeDifference(vector<int>& nums) {
        auto isPrime = [](int n) {
            if (n < 2) return false;
            if (n < 4) return true;
            if (n%2==0||n%3==0) return false;
            for (int i=5;i*i<=n;i+=6)
                if (n%i==0||n%(i+2)==0) return false;
            return true;
        };
        int first=-1, last=-1;
        for (int i=0;i<nums.size();i++) {
            if (isPrime(nums[i])) {
                if (first==-1) first=i;
                last=i;
            }
        }
        return last-first;
    }
};
