#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
class Solution {
    map<int,int>m;
public:
    int cuttingRope(int n) {
        if (n==0)
            return 0;
        if (n==1)
            return 1;
        if (m.count(n)){
            return m[n];
        }
        int Max=0;
        for (int i = 1; i <= n; ++i) {
            Max=max(Max,cuttingRope(i)*cuttingRope(n-i));
        }
        m[n]=Max;
        return Max;
    }
};