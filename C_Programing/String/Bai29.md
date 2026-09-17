## Bài 8. Số chia hết cho 6

Nhập vào một số nguyên dương n (1 ≤ n ≤ 10^1000). Xác định xem n có chia hết cho 6 hay không?

**Input**

Dòng đầu tiên là số bộ test T (1 ≤ T ≤ 100).

Mỗi bộ test bao gồm một dòng chứa số nguyên dương cần kiểm tra.

**Output**

In YES nếu n chia hết cho 6, ngược lại in NO.

**Ví dụ**

| Input | Output |
| --- | --- |
| 2<br>18<br>33333333999999993333333333333333333333333333333333333333222 | <br>YES<br>YES |

**Code**
```cpp
                            #include <stdio.h>
                            #include <string.h>
                            #include <stdlib.h>
                            #include <ctype.h>

                            // số chia hết cho số 6 là số vừa chia hết cho 3 và chia hết cho 2
                            int check(char c[]){
                                // nếu số tận cùng chia hết cho 2 
                                if((c[strrlen(c)-1] - '0')%2 == 1){
                                    return 0;
                                }
                                int sum = 0;
                                for(int i = 0;i< strlen(c);i++){
                                    // tổng các giá trị lại 
                                    sum += c[i] - '0';
                                }
                                // nếu tổng chia hết cho 3 
                                // vì số chia hết cho 3 thì tổng các chữ số cũng phải chia hết cho 3
                                // chia hết cho 2 thì số tận cùng phải chia hết cho 2
                                if(sum % 3 == 0) return 1;
                                return 0;
                            }
                            int main() {
                                int t;
                                scanf("%d",&t);
                                while(t--){
                                    char c[1001];
                                    scanf("%s",c);
                                    if(check(c)) printf("YES\n");
                                    else printf("NO\n");
                                }
                                return 0;
                            }
```

## Bài 9. Số chia hết cho 4

Nhập vào một số nguyên dương n (1 ≤ n ≤ 10^1000). Xác định xem n có chia hết cho 4 hay không?

**Input**

Dòng đầu tiên là số bộ test T (1 ≤ T ≤ 100).

Mỗi bộ test bao gồm một dòng chứa số nguyên dương cần kiểm tra.

**Output**

In YES nếu n chia hết cho 4, ngược lại in NO.

**Ví dụ**

| Input | Output |
| --- | --- |
| 2<br>18<br>3333333399999999333333333333333333333333333333333333333322210024 | <br>NO<br>YES |

**Code**
```cpp
                            #include <stdio.h>
                            #include <string.h>
                            #include <stdlib.h>
                            #include <ctype.h>
                            
                            int chech(char c[]){
                                // nếu có 1 chữ số thì 
                                if(strlen(c) == 1){
                                    if((c[0] - '0') % 4 == 0){
                                        return 1;
                                    }
                                    return 0;
                                }
                                // số chia hết cho 4 là số có 2 số tận cùng chia hết cho 4 
                                // lấy 2 số cuối cùng
                                int tmp = (c[strlen(c)-2] - '0') * 10 + (c[strlen(c)-1] - '0');
                                if(tmp % 4 == 0) return 1;
                                else return 0;
                            }

                            int main() {
                                int t;
                                scanf("%d",&t);
                                while(t--){
                                    char c[1001];
                                    scanf("%s",c);
                                    if(check(c)) printf("YES\n");
                                    else printf("NO\n");
                                }
                                return 0;
                            }
```
