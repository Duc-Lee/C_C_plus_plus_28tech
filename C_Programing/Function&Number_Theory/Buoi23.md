**Phần 3. Tổng hợp (Số thuận nghịch, số chính phương, số fibonacci...).**

**Bài 1.** Số thuận nghịch.

Kiểm tra số thuận nghịch.

**Input**

Dòng đầu tiên là số lượng test case T(1≤n≤100).

T dòng tiếp theo mỗi dòng là một số nguyên dương n (1≤n≤10^18)

**Output**

Mỗi test case in trên 1 dòng, in YES nếu n là số thuận nghịch, NO trong trường hợp ngược lại.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2<br>10019<br>999999999999999 | <br>NO<br>YES |

**Code**
```cpp
                #include <stdio.h>
                
                int check(int n){
                    // dao nguoc lai so 
                    int rev = 0, m = n;
                    // khi n khac 0
                    while(n != 0){
                        // dao nguoc lai so
                        rev = n%10 + rev/10;
                        n /= 10;
                    }
                    if(rev == m) return 1;
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
                }
```

- Cách 2 : Sử dụng xâu kí tự 
```cpp
                #include <stdio.h>
                
                int check(char n[]){
                    // dem do dai 
                    int len = strlen(n) - 1;
                    // duyet nua xau
                    for(int i = 0; i < len/2; i++){
                        // neu khac nhau thi return 0
                        if(n[i] != n[len-i]) return 0;
                    }
                    return 1;
                }
                
                int main(){
                    int t;
                    scanf("%d",&t);
                    while(t--){
                        char n[100];
                        scanf("%s",n);
                        if(check(n)){
                            printf("YES\n");
                        } else{
                            printf("NO\n");
                        }
                    }
                }
```