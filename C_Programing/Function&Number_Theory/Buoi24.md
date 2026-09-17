**Bài 2.** Số chính phương.

Kiểm tra số chính phương.

**Input**

Dòng đầu tiên là số lượng test case T(1≤n≤100).

T dòng tiếp theo mỗi dòng là một số nguyên dương n (1≤n≤10^18)

**Output**

Mỗi test case in trên 1 dòng, in YES nếu n là số chính phương, NO trong trường hợp ngược lại.

**Ví dụ.**

| Input | Output |
| :--- | :--- |
| 2<br>24<br>10000000000000000 | <br>NO<br>YES |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>
                
                // so chinh phuong la so ma can bac hai cua no cung la mot so nguyen
                int check(int n){
                    // tinh can bac hai cua n
                    int s = sqrt(n);
                    // kiem tra xem n co phai la so chinh phuong hay khong
                    if(s*s == n) return 1;
                    else return 0;
                }
                
                int main(){
                    int t;
                    scanf("%d",&t);
                    while(t--){
                        int n;
                        scanf("%d",&n);
                        if(check(n)){
                            printf("YES\n");
                        } else{
                            printf("NO\n");
                        }
                    }
                    return 0;
                }
```

**Bài 3. Số chính phương trong đoạn.**

In ra các số chính phương trong đoạn từ a tới b.

**Input**

Dòng đầu tiên là số lượng test case T(1≤n≤100).

T dòng tiếp theo mỗi dòng là 2 số nguyên dương a, b (1≤a≤b≤10⁶)

**Output**

Mỗi test case in ra trên 1 dòng.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2<br>1 50<br>10 20 | <br>1 4 9 16 25 36 49<br>16 |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>
                
                // so chinh phuong la so ma can bac hai cua no cung la mot so nguyen
                int check(int n){
                    // tinh can bac hai cua n
                    int s = sqrt(n);
                    // kiem tra xem n co phai la so chinh phuong hay khong
                    if(s*s == n) return 1;
                    else return 0;
                }
                
                int main(){
                    int t;
                    scanf("%d",&t);
                    while(t--){
                        int a, b;
                        scanf("%d %d",&a,&b);
                        // in so chinh phuong trong doan [a,b]
                        for(int i = a; i<= b;i++){
                            if(check(i)){
                                printf("%d ",i);
                            }
                        }
                        printf("\n");
                    }
                    return 0;
                }
```

**Cách 2 : Duyệt ít phần tử hơn**
```cpp
                #include <stdio.h>
                #include <math.h>
                
                int main(){
                    int t;
                    scanf("%d",&t);
                    while(t--){
                        int a, b;
                        scanf("%d %d",&a,&b);
                        // tinh can bac hai cua a va b
                        int s1 = sqrt(a);
                        int s2 = sqrt(b);
                        // in so chinh phuong trong doan [a,b]
                        for(int i = s1; i<= s2;i++){
                            printf("%d ",i*i);
                        }
                        printf("\n");
                    }
                    return 0;
                }
```