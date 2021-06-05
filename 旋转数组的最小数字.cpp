#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
using namespace std;
class Solution {
    int size;
public:
    int erfen(vector<int>& numbers,int l,int r){
        cout<<l<< ' '<<r<<endl;
        if (l==r)return numbers[r];
        int m=(l+r)/2;
        if (numbers[l]>numbers[m])
            return erfen(numbers,l,m);
        else if (numbers[m]>numbers[r])
            return erfen(numbers,m+1,r);
        else if(numbers[l]<numbers[m]&&numbers[m]<numbers[r])
            return numbers[l];
        else{
            for (int i = 0; i < size-1; ++i) {
                if (numbers[i]>numbers[i+1])
                    return numbers[i+1];
            }
        }
        return numbers[l];
    }
    int minArray(vector<int>& numbers) {
        size=numbers.size();
        return erfen(numbers,0,size-1);
    }
};