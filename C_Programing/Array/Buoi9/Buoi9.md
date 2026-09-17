# Bài tập Mảng 1 Chiều - Buổi 9

## Bài 17. Kadane Algo
Cho mảng các số nguyên. Tìm dãy con liên tiếp có tổng các phần tử lớn nhất.

**Input**
Dòng đầu tiên là số lượng phần tử trong mảng n. (1≤n≤10000).
Dòng thứ 2 là các phần tử ai trong mảng . (-10^6≤ai≤10^6).

**Output**
In ra tổng lớn nhất của dãy con liên tiếp trong mảng.

**Ví dụ**

| Input | Output |
|---|---|
| 5<br>1 2 -9 3 5 | 8 |

**Code**
```cpp
            int max(int a, int b){
                return a < b ? b :a;
            }
            int main(){
                int n;
                scanf("%d",&n);
                int a[n];
                for(int i=0;i<n;i++){
                    scanf("%d",&a[i]);
                }
                // khởi tạo 2 biến sum
                long long sum1 =0, sum2 =0;
                for(int i=0;i<n;i++){
                    // sum1 để tính tổng hiện tại
                    sum1 += a[i];
                    // tìm tổng max
                    sum2 = max(sum1,sum2);
                    // Nếu tổng hiện tại âm 
                    // Ngay lập tức gán sum1 biến đếm = 0
                    if(sum1 < 0){
                        sum1 = 0;
                    }
                }
                printf("%d",sum2);
            }
```