# Bài 16. Loại bỏ từ
Thực hiện loại bỏ các từ trong 1 xâu

**Input**
Dòng 1 chứa xâu có không quá 1000 kí tự
Dòng 2 chứa từ cần loại bỏ có không quá 10 kí tự

**Output**
Thực hiện loại bỏ từ trong xâu

**Ví dụ**

| Input | Output |
| :--- | :--- |
| lap &nbsp; trinh &nbsp; python &nbsp; &nbsp; &nbsp; &nbsp; java python c lap trinh<br>trinh | lap python java python c lap |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                int main(){
                    char c[1005];
                    gets(c);
                    char b[50];
                    gets(b);    
                    char a[20][50];
                    char *token = strtok(c," ");
                    int n = 0;
                    while(token != NULL){
                        if(strcmp(token,b)!=0){
                            strcpy(a[n],token);
                            ++n;
                        }
                        token = strtok(NULL," ");
                    }
                    // in ra kết quả 
                    for(int i = 0;i < n;i++){
                        printf("%s",a[i]);
                        if(i != n - 1){
                            printf(" ");
                        }
                    }
                } 
```

