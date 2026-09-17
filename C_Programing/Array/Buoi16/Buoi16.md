# Bài tập Mảng 1 Chiều - Buổi 16

## Bài 27. Đổi tiền (Tham lam)

Tại ngân hàng có các mệnh giá bằng 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, số lượng tờ tiền mỗi mệnh giá là không hạn chế. Một người cần đổi số tiền có giá trị bằng N. Hãy xác định xem số tờ tiền ít nhất sau khi đổi là bao nhiêu?

### Input
- Dòng đầu tiên là số lượng bộ test T (T <= 50).
- Mỗi test gồm 1 số nguyên N (1 <= N <= 100000).

### Output
- Với mỗi test, in ra đáp án trên một dòng.

### Ví dụ
| Input | Output |
| :--- | :--- |
| 2<br>70<br>121 | 2<br>3 |

### Code 
```cpp
            int main(){
                int money[10] = {1000,500,200,100,50,20,10,5,2,1};
                int t;
                while(t--){
                    int n;
                    scanf("%d",&n);
                    // đếm sô lượng tiền 
                    int res = 0;
                    for(int i =0;i<10;i++){
                        // tính số tiền 
                        res += n/a[i];
                        // n/a[i] : số lượng tiền trả, lấy phần nguyên 
                        // Tính số tiền dư 
                        n %= a[i];
                    }
                    printf("%d",res);
                }
            }
```