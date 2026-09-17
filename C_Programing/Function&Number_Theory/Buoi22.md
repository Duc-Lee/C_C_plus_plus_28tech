**Bài 9 . Bình phương nguyên tố.**

Một số được coi là số đẹp khi nó đồng thời vừa chia hết cho một số nguyên tố và chia hết cho bình phương của số nguyên tố đó. Viết chương trình liệt kê các số đẹp như vậy trong đoạn giữa hai số nguyên dương cho trước.

**Input**

2 số nguyên dương a, b (1≤a≤b≤10⁶).

**Output**

In ra các số đẹp trong đoạn từ a tới b.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 1 50 | 4 8 9 12 16 18 20 24 25 27 28 32 36 40 44 45 48 49 50 |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>   

                int solve(int n){
                    // ban chat la tim cac thua so nguyen to cua n 
                    // vi so dep chia het cho p 
                    // va chia het cho p^2 
                    // => n chia het cho p^2 
                    for(int i = 2; i <= sqrt(n);i++){
                        // neu i la thua so nguyen to 
                        // khoi tao bien dem 
                        int cnt = 0;
                        while(n % i == 0){
                            ++cnt;
                            n /= i;
                        }
                        // neu cnt >= 2, tuc la chia het cho binh phuong cua so nguyen to do 
                        // vi du 4 = 2^2 chia het cho 2 va 4 
                        // 12 = 2^2 . 3 chia het cho 2 va 4 
                        if( cnt >= 2) return 1;
                    }
                    return 0;
                }
                int main(){
                    int a,b;
                    scanf("%d %d",&a,&b);
                    for(int i = a; i <= b; i++){
                        if(solve(i)) printf("%d ",i);
                    }
                    printf("\n");
                }
```

**Bài 10. Bình phương nguyên tố 2.**

Một số được coi là số đẹp khi nếu nó chia hết cho một số nguyên tố nào đó thì cũng chia hết cho bình phương của số nguyên tố đó. Viết chương trình liệt kê các số đẹp như vậy trong đoạn giữa hai số nguyên dương cho trước

**Input**

2 số nguyên dương a, b (1≤a≤b≤10⁶).

**Output**

In ra các số đẹp trong đoạn từ a tới b.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 1 50 | 4 8 9 16 25 27 32 36 49 |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>   

                int solve(int n){
                    // kiem tra dieu kien n chia het cho p ma khong chia het cho p^2 
                    int ok = 0;
                    for(int i = 2; i <= sqrt(n);i++){
                        // khoi tao bien dem 
                        int cnt = 0;
                        // dem so lan i la thua so nguyen to 
                        while(n % i == 0){
                            ++cnt;
                            n /= i;
                        }
                        // neu cnt == 1 tuc la chia het cho p ma khong chia het cho p^2 
                        if(cnt == 1) return 0;
                        // neu cnt >= 2 tuc la chia het cho binh phuong cua so nguyen to 
                        if(cnt >= 2) ok = 1;
                    }
                    // neu n != 1 tuc la n la so nguyen to 
                    if(n != 1) return 0;
                    return ok;
                }
                int main(){
                    int a,b;
                    scanf("%d %d",&a,&b);
                    for(int i = a; i <= b; i++){
                        if(solve(i)) printf("%d ",i);
                    }
                    printf("\n");
                }
```