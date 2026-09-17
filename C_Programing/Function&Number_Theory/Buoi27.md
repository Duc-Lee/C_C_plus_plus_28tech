**Bài 7. Số có ước lẻ.**

Kiểm tra xem một số có số lượng ước số của nó là số lẻ.

**Input**

Dòng đầu tiên là số lượng test case T(1≤n≤100).

T dòng tiếp theo mỗi dòng là 1 số nguyên dương n (1≤n≤10¹⁸)

**Output**

Mỗi test case in ra trên 1 dòng. YES nếu n có số lượng ước lẻ, ngược lại in NO.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 1<br>1000000000000000000 | <br>YES |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>

                int main(){
                    int t;
                    scanf("%d",&t);
                    while(t--){
                        long long n;
                        scanf("%lld",&n);
                        // can bac hai cua n
                        long long k = sqrt(n);
                        // neu n la so chinh phuong thi can bac hai cua no se la so nguyen
                        // ma chi co so chinh phuong moi co so luong uoc la so le
                        // vi du n = 9 thi k = 3 va k*k = 9
                        // n va k deu la so nguyen
                        if(k*k == n) printf("YES\n");
                        else printf("NO\n");
                    }
                    return 0;
                }
```