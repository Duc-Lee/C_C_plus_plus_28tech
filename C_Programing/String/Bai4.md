# Bài 10. Xâu pangram 1
Một xâu chứa đầy đủ các kí tự in thường từ a-z được gọi là xâu Pangram
Kiểm tra xâu nhập vào có phải là xâu pangram hay không

**Input**
Dòng duy nhất là xâu gồm các kí tự in thường không quá 1000 kí tự

**Output**
In YES nếu xâu là xâu pangram, ngược lại in NO

**Ví dụ**

| Input | Output |
| :--- | :--- |
| thequickbrownfoxjumpsoverthelazydog | YES |
| abcdefghijklmnopzzutvlt | NO |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>

                int paragram(char c[]){
                    int cnt[26] = {0};
                    for(int i=0 ;i < strlen(c);i++){
                        cnt[c[i]-97] = 1;
                    }
                    for(int i =0;i<26;i++){
                        if(cnt[i] == 0){
                            return 0;
                        }
                    }
                    return 1;
                }
                int main(){
                    char c[1005];
                    gets(c);
                    if(paragram(c)){
                        printf("YES");
                    }else{
                        printf("NO");
                    }
                } 
```

# Bài 11. Xâu pangram 2
Một xâu chứa đầy đủ các kí tự từ a-z không phân biệt hoa thường được gọi là xâu Pangram
Kiểm tra xâu nhập vào có phải là xâu pangram hay không

**Input**
Dòng duy nhất là xâu gồm các kí tự là chữ cái không quá 1000 kí tự

**Output**
In YES nếu xâu là xâu pangram, ngược lại in NO

**Ví dụ**

| Input | Output |
| :--- | :--- |
| THEquickbrownfoxjumpsoverthelaZydog | YES |
| abcdefghijklmnopzzutvlt | NO |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>

                int paragram(char c[]){
                    int cnt[26] = {0};
                    // Chuyển hết chữ cái trong xâu về chữ in thường 
                    for(int i = 0;i< strlen(c);i++){
                        c[i] = tolower(c[i]);
                    }
                    for(int i=0 ;i < strlen(c);i++){
                        cnt[c[i]-97] = 1;
                    }
                    for(int i =0;i<26;i++){
                        if(cnt[i] == 0){
                            return 0;
                        }
                    }
                    return 1;
                }
                int main(){
                    char c[1005];
                    gets(c);
                    if(paragram(c)){
                        printf("YES");
                    }else{
                        printf("NO");
                    }
                }  
```
