# Bài tập Mảng 1 Chiều - Buổi 12

## Bài 20. Trộn 2 dãy đã sắp xếp
Cho 2 mảng đã được sắp xếp tăng dần, thực hiện trộn 2 dãy trên thành một dãy được sắp xếp.

**Input**
Dòng đầu tiên là số lượng phần tử của 2 dãy n và m. (1≤n, m≤10^6).
Dòng thứ 2 là n phần tử trong dãy số 1. (-10^6≤ai≤10^6).
Dòng thứ 3 là m phần tử trong dãy thứ 2. (-10^6≤ai≤10^6).

**Output**
In ra kết quả của bài toán.

**Ví dụ**

| Input | Output |
|---|---|
| 4 5<br>1 2 2 3<br>1 2 3 5 9 | 1 1 2 2 2 3 3 5 9 |

**Code**
```cpp
            int main(){
                int n,m;
                scanf("%d %d",&n,&m);
                int a[n],b[m];
                // nhập 2 mảng
                for(int i =0;i<n;i++){
                    scanf("%d",&a[i]);
                }
                for(int i=0;i<m;i++){
                    scanf("%d",&b[i]);
                }
                // Khởi tạo các thông số 
                int i = 0,j = 0, cnt = 0, c[n+m];
                while( i<n && j<m){
                    if(a[i]<= b[j]){
                        c[cnt] = a[i];
                        ++cnt;
                        ++i;
                    }else{
                        c[cnt] = b[j];
                        ++cnt;
                        ++j;
                    }
                }
                // Điền nốt các phần tử còn lại 
                while(i<n){
                    c[cnt] = a[i];
                    ++cnt;
                    ++i;
                }
                while(j<m;j++){
                    c[cnt] = b[j];
                    ++cnt;
                    ++i;
                }
                // in ra mảng c
                for(int i = 0;i < n+m;i++){
                    printf("%d ",c[i]);
                }
            }
```