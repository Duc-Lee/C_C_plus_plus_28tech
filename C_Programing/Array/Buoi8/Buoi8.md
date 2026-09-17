# Bài tập Mảng 1 Chiều - Buổi 8

## Bài 16. Range1
Cho mảng các số nguyên, thực hiện tính toán tổng các phần tử trong đoạn từ vị trí L tới vị trí R trong mảng.

**Input**
Dòng đầu tiên là số lượng phần tử trong mảng n. (1≤n≤100000).
Dòng thứ 2 là các phần tử ai trong mảng . (-10^9≤ai≤10^6).
Dòng thứ 3 là số lượng truy vấn q (1≤q≤1000).
q dòng tiếp theo, mỗi dòng là 2 vị trí L, R (1≤L≤R≤1000).

**Output**
In ra giá trị cho từng truy vấn.

| Input | Output |
|---|---|
| 10<br>1 2 3 4 5 6 7 8 9 10<br>3<br>1 3<br>1 10<br>2 5 | <br><br><br>6<br>55<br>14 |

**Code**
```cpp
            int main(){
                int n;
                scanf("%d",&n);
                int a[n];
                for(int i=0;i<n;i++){
                    scanf("%d",&a[i]);
                }
                int t;
                scanf("%d",&t);
                for(int i = 1;i<=t;i++){
                    int l,r;
                    scanf("%d %d",&l,&r);
                    int sum = 0;
                    for(int j = l-1, j <= r-1;j++){
                        sum += a[j];
                    }
                    printf("%d\n",sum);
                }
            }
```

- Cách 2 : Sử dụng phương pháp tổng tiền tố 
```cpp
            int main(){
                int n;
                scanf("%d",&n);
                int a[n];
                for(int i=0;i<n;i++){
                    scanf("%d",&a[i]);
                }
                // khởi tạo mảng tổng tiền tố
                long long prefix[n];
                for(int i=0;i<n;i++){
                    // Kiểm tra xem nếu phần tử đầu thì tổng bằng chính nó
                    if (i==0)
                        prefix[0] = a[0];
                    else 
                        prefix[i] = prefix[i-1] + a[i];
                }
                int t;
                scanf("%d",&t);
                for(int i = 1;i<=t;i++){
                    int l,r;
                    scanf("%d %d",&l,&r);
                    // do mảng bđ từ index = 0
                    // nên chỉ số bị chậm hơn thực 1 đơn vị
                    --l;--r;
                    if(l==0) 
                        printf("%d\n",prefix[r])
                    else 
                        // tổng hiện tại - tổng trc l
                        printf("%d\n",prefix[r] - prefix[l-1]);
                }
            }
```