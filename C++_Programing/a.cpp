#include <bits/stdc++.h>
using namespace std;

void nhap(int a[][1000], int n, int m){
    // nhap mang 2 chieu 
    for(int i = 1; i<=n;i++){
        for(int j = 1; j<= m;j++){
            cin >> a[i][j];
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int a[1000][1000];
    nhap(a, n, m);
    // khoi tao mang prefix sum 2 chieu 
    // kich thuoc mang phai lon hon n va m de tranh loi truy xuat
    int prefix[1001][1001] = {0};
    // tinh mang prefix sum 
    for(int i = 1; i<= n;i++){
        for(int j = 1; j <= m; j++){
            // công thức tính prefix sum 2 chiều
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + a[i][j]; 
        }
    }
    return 0;
}