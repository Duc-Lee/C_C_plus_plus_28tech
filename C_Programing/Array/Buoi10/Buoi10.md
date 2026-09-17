# Bài tập Mảng 1 Chiều - Buổi 10

## Bài 18. Sliding Window
Cho mảng các số nguyên. Hãy tìm dãy con k phần tử liên tiếp có tổng các phần tử lớn nhất.

**Input**
Dòng đầu tiên là số lượng phần tử trong mảng n,k. (1≤k≤n≤10000).
Dòng thứ 2 là các phần tử ai trong mảng . (-10^6≤ai≤10^6).

**Output**
In ra tổng lớn nhất của dãy con có k liên tiếp trong mảng, và các số trong dãy con đó. Nếu có nhiều dãy con có cùng tổng lớn nhất thì in ra dãy con cuối cùng.

**Ví dụ**

| Input | Output |
|---|---|
| 10 3<br>1 2 4 4 8 1 3 3 9 4 | 16<br>3 9 4 |

**Code**
- Cách 1 : Phương pháp dùng 2 vòng for
```cpp
            int main(){
                int n,k;
                scanf("%d %d",&n,&k);
                int a[n];
                for(int i=0;i<n;i++) scanf("%d",&a[i]);
                // khới tạo biến tổng 
                long long res =0, sum = 0, idx = 0;
                for(int i = 0;i<n-k+i;i++){
                    sum = 0;
                    for(int j = 0;j<k;j++){
                        sum += a[i+j];
                    }
                    if(sum >= res){
                        res = sum;
                        idx = i;
                    }
                }
                // In kết quả 
                printf("%lld\n",res);
                for(int i=0;i<k;i++){
                    printf("%d ",a[idx + i]);
                }
            }
```

- Cách 2 : Phương pháp cửa sổ trượt 
```cpp
            int main(){
                int n,k;
                scanf("%d %d",&n,&k);
                int a[n];
                for(int i=0;i<n;i++) scanf("%d",&a[i]);
                // khới tạo biến tổng 
                long long res =0, sum = 0, idx = 0;
                // Tinh tổng 3 phần tử đầu mảng 
                for(int i=0;i<k;i++){
                    sum += a[i];
                }
                // Gán biến kỉ lục sum hiện tại
                res = sum;
                // n - k + 1 : để duyệt đến ptu thứ 2 từ cuối
                for(int i = 1;i<n-k+1;i++){
                    // Tính tổng cửa sổ trượt
                    // Trừ phần tử đầu, cổng phần tử tiếp theo
                    sum += a[i+k-1] - a[i-1];
                    // Lưu kỉ lục 
                    if(sum >= res){
                        res = sum;
                        idx = i;
                    }
                }
                printf("%lld\n",res);
                for(int i=0;i<k;i++){
                    printf("%d ",a[idx + i]);
                }
            }
```