#include <stdio.h>
void duyet_mang(int n, int a[]){
    for (int i =0;i<n;i++){
        printf("%d ",a[i]);
    }
}

void sx_tang_dan(int n, int a[]){
    for(int i =0;i<n;i++){
        for (int j =i+1;j<n;j++){
            if(a[i]>a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void sx_giam_dan(int n, int a[]){
    sx_tang_dan(n,a);
    for(int i =0;i<n/2;i++){
        int temp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = temp;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    // Duyệt mảng 
    duyet_mang(n,a);
    // Sắp xếp tăng dần 
    sx_tang_dan(n,a);
    printf("\n");
    duyet_mang(n,a);
    // Sắp xếp giảm dần 
    sx_giam_dan(n,a);
    printf("\n");
    duyet_mang(n,a);
    printf("\n");
    // đếm số phần tử chẵn lẽ âm dương 
    int chan = 0, le = 0, am = 0, duong = 0;
    int tong_chan = 0, tong_le = 0, tong_am = 0, tong_duong = 0;
    for (int i=0;i<n;i++){
        if(a[i]%2 != 0){
            le++;
            tong_le += a[i];
        }
        if(a[i]%2 == 0){
            chan++;
            tong_chan += a[i];
        }
        if(a[i]<0){
            am++;
            tong_am += a[i];
        }
        if(a[i]>0){
            duong++;
            tong_duong += a[i];
        }
    }
    printf("Tong phan tu chan la: %d\n",tong_chan);
    printf("Tong phan tu le la : %d\n",tong_le);
    printf("Tong phan tu am la : %d\n",tong_am);
    printf("Tong phan tu duong la : %d",tong_duong);
    return 0;
}









