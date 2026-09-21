**Bài 40. Số đẹp**

Một số được coi là đẹp nếu chữ số đầu gấp đôi chữ số cuối hoặc ngược lại; đồng thời các chữ số từ vị trí thứ 2 đến gần cuối thỏa mãn là một số thuận nghịch.

Ví dụ: các số 36788766; 12345654322 là các số đẹp.

Viết chương trình kiểm tra số đẹp theo tiêu chí trên.

**Input**

- Dòng đầu ghi số bộ test
- Mỗi test là một số nguyên dương không quá 18 chữ số

**Output**

- Ghi ra YES tương ứng với số đẹp, NO trong trường hợp ngược lại

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 3<br>36788766<br>22345654321<br>12345654321 | <br>YES<br>YES<br>NO |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>
                #include <string.h>

                int solve(char c[]){
                    int l = 0;
                    int r = strlen(c) - 1;
                    int first = c[l] - '0';
                    int last = c[r] - '0';
                    if(first * 2 != last && last * 2 != first) return 0;
                    l++, r--;
                    while( l < r){
                        if(c[l] != c[r]) return 0;
                        l++, r--;
                    }
                    return 1;
                }
                int main(){
                    int t;
                    scanf("%d",&t);
                    while(t--){
                        char c[25];
                        scanf("%s",c);
                        if(solve(c)) printf("YES\n");
                        else printf("NO\n");
                    }
                }
```

- Code theo số nguyên 
```cpp
                #include <stdio.h>
                #include <math.h>

                // ham check so thuan nghich
                int check(int n){
                    int rev = 0, m = n;
                    while(n != 0){
                        rev = rev*10 + n%10;
                        n/=10;
                    }
                    return rev == m;
                }
                // ham check so dep
                int solve(int n){
                    // c la so cuoi cung cua n
                    int c = n % 10, n/= 10;
                    // dao nguoc lai cac chu so tru chu so cuoi cung
                    int rev = 0;
                    while(n >= 10){
                        rev = rev * 10 + n%10; n/=10;
                    }
                    // check so dep
                    if(n * 2 != c && 2*n != c || !check(rev)) return 0;
                    else return 1;
                }
                int main(){
                    int t;
                    scanf("%d",&t);
                    while(t--){
                        int n;
                        scanf("%d",&n);
                        if(solve(n)) printf("YES\n");
                        else printf("NO\n");
                    }
                }
```