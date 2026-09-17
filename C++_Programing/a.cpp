#include <stdio.h>

int max(int a,int b){
    return a < b ? b : a;
}
int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i =0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    int res = 0;
    for(int i =0;i<n-1;i++){
        if(arr[i]*arr[i+1] > res){
            res = arr[i]*arr[i+1];
        }
    }
    if (res > 0){
        printf("%d", res);
    }
    else{
        printf("0");
    
    }
}