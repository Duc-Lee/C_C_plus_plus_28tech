# Bài 12. Xâu đối xứng 1
Kiểm tra xâu nhập vào có phải là xâu đối xứng hay không

**Input**
Dòng duy nhất là xâu không quá 1000 kí tự

**Output**
In YES nếu xâu là xâu đối xứng, ngược lại in NO

**Ví dụ**

| Input | Output |
| :--- | :--- |
| AbcdbcbA | YES |
| abcbaa | NO |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                int check(char c[]){
                    int l = 0,r = strlen(c)-1;
                    while(l<r){
                        if(c[l]!=c[r]){
                            return 0;
                        }
                        l++;
                        r--;
                    }
                    return 1;
                }
                int main(){
                    char c[1005];
                    gets(c);
                    if(check(c)){
                        printf("YES");
                    }else{
                        printf("NO");
                    }
                } 
```

# Bài 13. Xâu đối xứng 2
Bạn được phép thay đổi đúng một kí tự trong xâu, hãy kiểm tra có thể biến xâu đó thành xâu đối xứng được hay không

**Input**
Dòng đầu tiên là số lượng test case T (1≤T≤100).
T dòng tiếp theo mỗi dòng là một xâu không bao gồm khoảng trắng, mỗi xâu có độ dài không quá 1000 kí tự

**Output**
In YES nếu có thể biến xâu đầu vào thành xâu đối xứng với duy nhất một thay đổi, ngược lại in NO

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2<br>abccbZ<br>abcdxba | YES<br>YES |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                int check(char c[]){
                    int l = 0, r = strlen(c)-1;
                    // biến đếm xem có bao nhiêu cặp khác
                    int cnt = 0;
                    while(l<r){
                        if(c[l]!=c[r]) ++cnt;
                        ++l, --r;
                    }
                    // trường hợp xâu lẻ 
                    if(strlen(c)%2==1 && cnt <= 1)
                        return 1;
                    // TH xâu chẵn, chỉ có th cnt == 1 là cần sửa
                    // nếu cnt == 0, phải sửa cả 2 kí tự
                    if(strlen(c)%2==0 && cnt == 1){
                        return 1;
                    }
                }
                int main(){
                    int t;
                    scanf("%d", &t);
                    while(t--){
                        char c[1005];
                        scanf("%s", c);
                        if(check(c)){
                            printf("YES");
                        }else{
                            printf("NO");
                        }
                        // do dùng scanf() nên phải xoá kí tự \0
                        getchar();
                    }
                } 
```
