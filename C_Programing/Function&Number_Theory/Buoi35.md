# **Bài 19. Tính giai thừa.**

Viết chương trình C cho phép nhập một số tự nhiên n và tính giai thừa của n.

**Input**

Một số tự nhiên n.

**Output**

Giai thừa của n.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 10 | 3628800 |

**Code**
```cpp
                #include <stdio.h>

                long long giai_thua(int n){
                    long long res = 1;
                    for(int i = 2; i <= n; ++i){
                        res *= i;
                    }
                    return res;
                }

                int main(){
                    int n;
                    scanf("%d", &n);
                    printf("%lld\n", giai_thua(n));
                    return 0;
                }
```

# **Bài 20. Số armstrong.**

Số armstrong là số A có n chữ số và thỏa mãn tổng của lũy thừa bậc n của từng chữ số trong A bằng chính nó.

Ví dụ: 371 = 3³ + 7³ + 1³

Viết chương trình C kiểm tra một số xem có phải là số armstrong hay không. Nếu đúng in ra 1, sai in ra 0.

**Input**

Một số nguyên dương.

**Output**

Nếu đúng in ra 1, sai in ra 0.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 371 | 1 |
| 24 | 0 |

**Code**
```cpp
                    #include <stdio.h>
                    #include <math.h>

                    int dem_luy_thua(int x){
                        int cnt = 0;
                        while(x != 0){
                            ++cnt;
                            x /= 10;
                        }
                        return cnt;
                    }

                    int amstrong(int x){
                        // khoi tao luy thua n
                        int n = dem_luy_thua(x);
                        int sum = 0, tmp = x;
                        while(tmp != 0){
                            sum += (int)pow(tmp % 10,n);
                            tmp /= 10;
                        }
                        return sum == x;
                    }

                    int main(){
                        int n;
                        scanf("%d", &n);
                        if(amstrong(n)){
                            printf("1\n");
                        }else{
                            printf("0\n");
                        }
                        return 0;   
                    }   
```