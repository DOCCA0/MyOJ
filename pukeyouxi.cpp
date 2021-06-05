#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
using namespace std;
int main(){
    int arr[6];
    bool finish=true;
    for (int i = 0; i < 6; ++i) {
        scanf("%d",&arr[i]);
        if (arr[i]!=0)
            finish=false;
    }
    if (finish)
        return 0;
    else{
        int x,y;
        x=(arr[0]+arr[1]+ arr[1]+arr[3]+arr[5] -arr[0]-arr[2]-arr[4])/2;
        y=(arr[0]+arr[1]- arr[1]-arr[3]-arr[5] +arr[0]+arr[2]+arr[4])/2;
        cout<<x<<'-'<<y<<endl;
    }
}