# Bài tập Mảng 1 Chiều - Buổi 4 

## Bài 6. Cặp số nguyên tố cùng nhau
Cho một dãy số nguyên dương có n phần tử. Hãy đếm các cặp số nguyên tố cùng nhau trong mảng.

### Input
- Dòng đầu tiên là số lượng phần tử trong mảng n. ($1 \le n \le 10^6$).
- Dòng thứ 2 là các phần tử ai trong mảng. ($1 \le ai \le 10^9$).

### Output
- Kết quả của bài toán.

### Ví dụ:
| Input | Output |
| :--- | :--- |
| `5`<br>`2 4 8 3 6` | `3` |

### Code:
```cpp
                // Tìm ước chung lớn nhất 
                int gcd(int a, int b){
                    if(b==0)    
                        return a;
                    return gcd(b,a%b);
                }
                int main(){
                    int n;
                    scanf("%d",&n);
                    int a[n];
                    // Khai bao cac ptu trong mang
                    for(int i=0;i<n;i++){
                        scanf("%d",&a[i]);
                    }
                    int cnt = 0;
                    // duyệt a[i] với các ptu sau nó còn lại 
                    for(int i =0;i<n;i++){
                        // Lấy a[i] để so sánh với các phần tử a[j] với j > i
                        for(int j = i+1;j<n;j++){
                            // Nếu ước chung lớn nhất của a[i] và a[j] bằng 1 
                            // thì tăng biến đếm lên 1 
                            if(gcd(a[i],a[j])==1){
                                ++cnt;
                            }
                        }
                    }
                    printf("%d ",cnt);
                }
```
- Giải thích : 
    - **Cặp số nguyên tố cùng nhau** là hai số có ước chung lớn nhất bằng 1.
    - Các cặp số nguyên tố cùng nhau là: `(2, 3)`, `(4, 3)`, `(8, 3)`. Tổng cộng có **3** cặp.
    - Ta dùng hàm **gcd** để kiểm tra.

## Bài 7. Tích lớn nhất của 2 số trong mảng
Cho một dãy số nguyên có n phần tử. Tìm tích lớn nhất của 2 số trong mảng.

### Input
- Dòng đầu tiên là số lượng phần tử trong mảng n. ($1 \le n \le 10^6$).
- Dòng thứ 2 là các phần tử ai trong mảng. ($-10^9 \le ai \le 10^9$).

### Output
- Kết quả của bài toán.

### Ví dụ:
| Input | Output |
| :--- | :--- |
| `5`<br>`2 4 8 3 6` | `48` |

### Code:
```cpp
                int cach1(int n, int a[]){
                    long long max = -1e18;
                    // Độ phức tạp O(n^2)
                    // Đi so sánh từng cặp phần tử (i,j)
                    for(int i=0;i<n;i++){
                        for(int j = i+1;j<n;j++){
                            if(a[i]*a[j] > max)
                                max = a[i]*a[j];
                        }
                    }
                    return max;
                }

                int cach2(int n, int a[]){
                    long long max1 = -1e9, max2 = -1e9;
                    long long min1 = 1e9, min2 = 1e9;
                    for (int i=0;i<n;i++){
                        // Tìm max1, max2
                        if(max1 <= a[i]){
                            max2 = max1;
                            max1 = a[i];
                        }else if(max2 < a[i]){
                            max2 = a[i];
                        }
                        // Tìm min1, min2
                        // lưu ý : min2 > min1
                        if(min1 >= a[i]){
                            min2 = min1;
                            min1 = a[i];
                        }else if(min2 > a[i]){
                            min2 = a[i];
                        }
                    }
                    // Trả về tính lớn nhất
                    // 2 số âm bé nhất có thể cho tích lớn nhất
                    return (max1 *max2) < (min1*min2) ? (min1*min2) : (max1*max2);
                }
```
