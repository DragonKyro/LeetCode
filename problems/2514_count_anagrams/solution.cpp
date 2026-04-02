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
    int countAnagrams(string s) {
        const int MOD = 1e9+7;
        vector<long long> fact(100001); fact[0]=1;
        for (int i=1;i<=100000;i++) fact[i]=fact[i-1]*i%MOD;
        auto pw=[&](long long b, long long e){long long r=1;b%=MOD;while(e>0){if(e&1)r=r*b%MOD;b=b*b%MOD;e>>=1;}return r;};
        long long ans=1;
        istringstream iss(s); string w;
        while(iss>>w){
            ans=ans*fact[w.size()]%MOD;
            int cnt[26]={};
            for(char c:w)cnt[c-'a']++;
            for(int c:cnt)if(c>0)ans=ans*pw(fact[c],MOD-2)%MOD;
        }
        return ans;
    }
};
