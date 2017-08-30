#include <iostream>
#include <math.h>
//#define MAX_LEFT_SUM = -32,768;

using namespace std;

class MaxSubArray {
    public:
        int leftIndex;
        int rightIndex;
        int sum=0;
};

MaxSubArray findSplit_max(int *p, int low, int mid,  int high){
    MaxSubArray m;
    int sum=0;
    int maxLeftSum,maxRightSum;
    maxLeftSum = maxRightSum = -32,768;
    int maxLeftI,maxRightI;

    for(int i = mid; i>=low; i--){
        sum = sum + p[i];

        if(sum>maxLeftSum){
            maxLeftSum = sum;
                maxLeftI = i;
        }
    }

    sum = 0; //reset sum cause past sum from left half is again added in the right half

    for(int i=mid+1; i<=high;i++){
        sum = sum + p[i];
        if(sum>maxRightSum){
            maxRightSum = sum;
            maxRightI = i;
        }

    }

    m.leftIndex = maxLeftI;
    m.rightIndex = maxRightI;
    m.sum = maxLeftSum + maxRightSum;

    return m;
}

MaxSubArray findMax_subArray( int *p, int low, int high ){
    MaxSubArray m;
//    cout<<p[0]<<endl;

    if(high==low)
    {
            m.sum = p[low];
            m.leftIndex=low;
            m.rightIndex=high;
            return m;

    }
    int mid =  floor( (low+high)/2);
    MaxSubArray leftMax;
    MaxSubArray rightMax;
    MaxSubArray splitMax;

    //recursive calls
    leftMax=findMax_subArray(p,low,mid);
    rightMax=findMax_subArray(p,mid+1,high);

    //split call to compute sum of splited max array
    splitMax = findSplit_max(p,low,mid,high);


    if(leftMax.sum >= rightMax.sum && leftMax.sum >= splitMax.sum){
        return leftMax;
    }else if( rightMax.sum >= leftMax.sum && rightMax.sum >= splitMax.sum ){
        return rightMax;
    }else{
        return splitMax;
    }
    return m;

}

int main()
{
    MaxSubArray maxSubArray;
    int *p;
    int sizearr;
    cin>>sizearr;
    p = new int(sizearr);
    for (int i=0; i<sizearr; i++){
        cin>>p[i];
    }
    maxSubArray = findMax_subArray(p,0,sizearr-1);
    cout<<"left max i:" << maxSubArray.leftIndex << " "
        << "right max i:" <<maxSubArray.rightIndex << "\n";

    cout<<"max sum is: "<<maxSubArray.sum;
//    cout << "Hello world!" << endl;
    return 0;
}
