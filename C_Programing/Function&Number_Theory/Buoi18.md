**Bài 5. Đếm số lượng chữ số 0 của n!.**

**Input**

Dòng đầu tiên là số lượng test case T(1≤n≤100).

T dòng tiếp theo mỗi dòng là một số nguyên dương n (1≤n≤10^6).

**Output**

In ra số lượng chữ số 0 liên tiếp tính từ cuối của n!.

**Ví dụ**

**Input:**
```text
2
10
20
```

**Output:**
```text
2
4
```

**Code**
```cpp
                #include <stdio.h>

                // Dem so luong chu so 0 cua n! 
                int count(int n){
                   int res = 0;
                   // i = 5 vi so tan cung la 0 thi phai co thua so 5 
                   // con 2 thi khoi luong nhieu hon 5 nen ko can
                   for(int i = 5; i <= n; i *= 5) 
                   {    
                        // dem so luong 
                        res += n / i;
                   } 
                   return res;
                }
                int main(){
                    int t;
                    scanf("%d", &t); // doc du lieu test case
                    while(t--){
                        int n; // khai bao bien n
                        scanf("%d", &n); // doc du lieu n 
                        printf("%d\n", count(n));
                    }
                    return 0;
                }
```