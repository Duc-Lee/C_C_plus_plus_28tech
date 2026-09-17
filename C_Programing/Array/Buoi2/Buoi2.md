# Bài tập Mảng 1 chiểu - Buổi 2

## Bài 2. Mảng tăng.
Kiểm tra xem mảng cho trước có tăng dần hay không, mảng tăng dần được định nghĩa là mảng có phần tử đứng sau lớn hơn phần tử đứng trước nó. Nếu mảng tăng dần in ra YES, trường hợp ngược lại in ra NO.

### Input
- Dòng đầu tiên là số lượng phần tử trong mảng $n$. ($1 \le n \le 10^6$).
- Dòng thứ 2 là các phần tử $a_i$ trong mảng. ($-10^9 \le a_i \le 10^9$).

### Output
- In YES nếu mảng tăng dần. NO trong trường hợp ngược lại.

### Ví dụ:
| Input | Output |
| :--- | :--- |
| `5`<br>`1 2 2 3 5` | `NO` |

### Code:
```cpp
                    int check(int n, int a[]){
                        // Kiểm tra xem 
                        // ptu trước lớn hơn ptu sau không?
                        for(int i=0;i<n-1;i++){
                            if(a[i] > a[i+1]){
                                return 0;
                            }
                        }
                        return 1;
                    }
                    int main(){
                        int n;
                        scanf("%d",&n);
                        int a[n];
                        for(int i = 0;i<n;i++){
                            scanf("%d",&a[i]);
                        }
                        // Kiểm tra cộng dồn
                        if(check(n,a)){
                            printf("YES");
                        }else{
                            printf("NO");
                        }
                    }
```

---

## Bài 3. Số không nhỏ hơn số đứng trước
Cho một dãy số nguyên dương có n phần tử. Hãy liệt kê số các phần tử trong dãy không nhỏ hơn các số đứng trước nó (tính cả phần tử đầu tiên).

### Input
- Dòng đầu tiên là số lượng phần tử trong mảng n. ($1 \le n \le 10^6$).
- Dòng thứ 2 là các phần tử ai trong mảng. ($-10^9 \le ai \le 10^9$).

### Output
- Kết quả của bài toán.

### Ví dụ:
| Input | Output |
| :--- | :--- |
| `6`<br>`1 2 9 2 0 22` | `1 2 9 22` |

### Code:
```cpp
                    void check(int n, int a[]){
                        // Khởi tạo phần tử max
                        int max = a[0];
                        printf("%d ",a[0]);
                        for(int i=1;i<n;i++){
                            // In ra các số không nhỏ hơn số lớn nhất đứng trước nó
                            // Có thể bằng hoặc lớn hơn
                            if(a[i] >= max){
                                printf("%d ",a[i]);
                            }
                            // Cập nhật lại max
                            if(a[i] > max)
                                max = a[i];
                        }
                    }

                    int main(){
                        int n;
                        scanf("%d",&n);
                        int a[n];
                        for(int i=0;i<n;i++){
                            scanf("%d",&a[i]);
                        }
                        check(n,a);
                    }
```
