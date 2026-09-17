## Bài 13. Số nhị phân chia hết cho 5

Kiểm tra xem một số nguyên dương có chia hết cho 5 hay không

**Input**

Dòng đầu tiên là số lượng test case T (1≤T≤100).

Mỗi test case gồm 1 dòng, mỗi dòng là một số nguyên dương n được biểu diễn dưới dạng số nhị phân có không quá 1000 bit.

**Output**

In YES nếu số đã cho thỏa mãn yêu cầu đầu bài, ngược lại in NO

**Ví dụ**

| Input | Output |
|---|---|
| 2<br><br>111<br><br>0001101110100100101111000011111011000010010101111011010011110011 | <br><br>NO<br><br>YES |

**Code**
```cpp
                    #include <stdio.h>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <ctype.h>
                    #include <math.h>
                    // chuyển bit về cơ số 10
                    // đồng thời kiểm tra xem có chia hết cho 5 hay không
                    int check(char c[]){
                        int n = strlen(c);
                        int tmp = 1, sum = 0;
                        // duyệt ngược về 
                        for(int i = n-1;i>=0;i--){
                            sum += (c[i] - '0') * tmp;
                            tmp = tmp * 2; // tính 2 luỹ lên
                            // dùng này để tránh tràn số 
                            // %10 để lấy số dư
                            // muốn chia hết cho 5 thì số dư khi chia cho 10 phải bằng 0 hoặc 5
                            // nên ta chỉ cần tính mod 10 là đủ
                            tmp %= 10;
                            sum %= 10;
                        }
                        if(sum % 5 == 0) return 1;
                        return 0;
                    }
                    int main(){
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