## Bài 36. Xâu có chữ các chữ cái liên tiếp khác nhau

Tìm xâu con liên tiếp mà trong đó các kí tự liền kề nhau đều khác nhau

**Input**

Dòng đầu tiên là số lượng test case T (1 ≤ T ≤ 100).

Mỗi test case là một xâu có không quá 1000 kí tự là chữ cái thường.

**Output**

In ra độ dài xâu con liên tiếp lớn nhất trong đó kí tự liền kề nhau đều khác nhau.

*(Bạn thử tìm cách in ra xâu con có độ dài lớn nhất mà xâu đó xuất hiện cuối cùng đó thay vì in ra mỗi chiều dài xâu)*

**Ví dụ**

| Input | Output |
| --- | --- |
| 1<br><br>abcdddzozozozozozozoabcd | <br><br>19 |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                int max(int a, int b){
                    return a < b ? b : a;
                }

                int main(){
                    char s[1000];
                    scanf("%s",s);
                    int n = strlen(s);
                    int cnt = 1; // bien dem
                    int res = 1; // bien ki luc
                    for(int i = 0 ;i<n-1;i++){
                        // nếu phần tử sau 
                        if(s[i] != s[i+1]){
                            ++cnt;
                        }
                        else{
                            res = max(res,cnt);
                            // kh thì reset lại giá trị cnt
                            cnt = 1;
                        }
                    }
                    printf("%d",res);
                }
```

---

## Bài 37. Xâu liên tiếp có chữ các chữ cái giống nhau

Tìm xâu con liên tiếp mà trong đó các kí tự liền kề nhau đều giống nhau.

**Input**

Dòng đầu tiên là số lượng test case T (1 ≤ T ≤ 100).

Mỗi test case là một xâu có không quá 1000 kí tự là chữ cái thường.

**Output**

In ra độ dài xâu con liên tiếp lớn nhất trong đó các kí tự liền kề nhau đều giống nhau.

**Ví dụ**

| Input | Output |
| --- | --- |
| 1<br><br>abcddddddzozoabcd | <br><br>6 |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                int max(int a, int b){
                    return a < b ? b : a;
                }

                int main(){
                    char s[1000];
                    scanf("%s",s);
                    int n = strlen(s);
                    int cnt = 1; // bien dem
                    int res = 1; // bien ki luc
                    for(int i = 0 ;i<n-1;i++){
                        // nếu phần tử sau 
                        if(s[i] == s[i+1]){
                            ++cnt;
                        }
                        else{
                            res = max(res,cnt);
                            // kh thì reset lại giá trị cnt
                            cnt = 1;
                        }
                    }
                    printf("%d",res);
                }
```