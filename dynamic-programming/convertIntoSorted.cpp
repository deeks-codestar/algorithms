#include<iostream>
#include<algorithm>
#define INF 1000000000
 
using namespace std;
 
int main(){
 
        int arr[] = {10,3,4,5};
        int size = 4;
        int max = -10;
    int dp[100][100];
    
        for(int i=0;i<size;i++) max = (arr[i]>max)?arr[i]:max;
 
        for( int j=0; j<=max; j++){
                if( arr[size-1] >= j)
                        dp[size-1][j] = 0;
                else
                        dp[size-1][j] = arr[size-1];
        }
 
        for( int i=size-2; i>0; i--){
                for( int j=0; j<=max;j++){
                        int minn = arr[i] + dp[i+1][j]; //case where the element is deleted altogether
                        
                        if( j <= arr[i]){
                                for( int k=j; k<=arr[i];k++){//we try decrementing to all possible values
                                        minn =  min(minn, arr[i]-k + dp[i+1][k]);
                                }
                        }
                        dp[i][j] = minn;        
                }
        }
 
        int ans = INF;
        for( int i=0; i<= arr[0];i++)
                ans = min(ans, (arr[0]-i)+dp[1][i]);
        
        cout<<ans;
        return 0;
}       
