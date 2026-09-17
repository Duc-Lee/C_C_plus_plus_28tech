# Bài 7. Chuẩn hóa tên 1
Thực hiện viết hoa chữ cái đầu của từng từ trong tên người. Tên người là một xâu có thể không chuẩn.

**Input**
Dòng đầu tiên là số lượng test case T (1≤T≤100).
T dòng tiếp theo mỗi dòng chứa xâu có không quá 1000 kí tự

**Output**
In tên người đã được chuẩn hóa trên từng dòng

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2<br>NguYEN &nbsp; VAN &nbsp; &nbsp; &nbsp; &nbsp; maNH<br> &nbsp;nGUYEN &nbsp; &nbsp; thuY &nbsp; &nbsp;LinH | Nguyen Van Manh<br>Nguyen Thuy Linh |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                void chuanhoa(char c[]){
                    c[0] = toupper(c[0]);
                    for(int i = 1;i< strlen(c);i++){
                        c[i] = tolower(c);
                    }
                }
                int main(){
                    int t;
                    scanf("%d", &t);
                    getchar(); 
                    while(t--){
                        char c[1005];
                        gets(c);
                        char a[20][50];
                        char *token = strtok(c," ");
                        int n = 0;
                        while(token != NULL){
                            strcpy(a[n],token);
                            ++n;
                            token = strtok(NULL," ");
                        }
                        for(int i =0;i<n;i++){
                            chuanhoa(a[i]);
                            printf("%s",a[i]);
                            // In dau cach trong cau cho dung, tranh thua
                            if(i != n-1) printf(" ");
                        }
                        printf("\n");
                    }
                } 
```

# Bài 8. Chuẩn hóa tên 2
Thực hiện chuẩn hóa tên người theo mẫu. Tên người là một xâu có thể không chuẩn.

**Input**
Dòng đầu tiên là số lượng test case T (1≤T≤100).
T dòng tiếp theo mỗi dòng chứa xâu có không quá 1000 kí tự

**Output**
In tên người đã được chuẩn hóa trên từng dòng

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2<br>NguYEN &nbsp; VAN &nbsp; &nbsp; &nbsp; &nbsp; maNH<br> &nbsp;nGUYEN &nbsp; &nbsp; thuY &nbsp; &nbsp;LinH | Manh, Nguyen Van<br>Linh, Nguyen Thuy |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                void chuanhoa(char c[]){
                    c[0] = toupper(c[0]);
                    for(int i = 1;i< strlen(c);i++){
                        c[i] = tolower(c);
                    }
                }
                int main(){
                    int t;
                    scanf("%d", &t);
                    getchar(); 
                    while(t--){
                        char c[1005];
                        gets(c);
                        char a[20][50];
                        char *token = strtok(c," ");
                        int n = 0;
                        while(token != NULL){
                            strcpy(a[n],token);
                            ++n;
                            token = strtok(NULL," ");
                        }
                        chuanhoa(a[n-1]);
                        printf("%s, ",a[n-1]);
                        for(int i =0;i<n-1;i++){
                            chuanhoa(a[i]);
                            printf("%s",a[i]);
                            // In dau cach trong cau cho dung, tranh thua
                            if(i != n-1) printf(" ");
                        }
                        printf("\n");
                    }
                } 
```

# Bài 9. Chuẩn hóa tên 3
Thực hiện chuẩn hóa tên người theo mẫu. Tên người là một xâu có thể không chuẩn.

**Input**
Dòng đầu tiên là số lượng test case T (1≤T≤100).
T dòng tiếp theo mỗi dòng chứa xâu có không quá 1000 kí tự

**Output**
In tên người đã được chuẩn hóa trên từng dòng

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2<br>NguYEN &nbsp; VAN &nbsp; &nbsp; &nbsp; &nbsp; maNH<br> &nbsp;nGUYEN &nbsp; &nbsp; thuY &nbsp; &nbsp;LinH | MANH, Nguyen Van<br>LINH, Nguyen Thuy |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>

                void chuanhoa1(char c[]){
                    c[0] = toupper(c[0]);
                    for(int i = 1;i<strlen(c);i++){
                        c[i] = tolower(c[i]);
                    }
                }
                void chuanhoa2(char c[]){
                    for(int i = 0;i<strlen(c);i++){
                        c[i] = toupper(c[i]);
                    }
                }
                int main(){
                    int t;
                    scanf("%d", &t);
                    getchar(); 
                    while(t--){
                        char c[1005];
                        gets(c);
                        // khởi tạo xâu 2 chiều lưu các từ trong câu 
                        char a[20][50];
                        int n = 0;
                        char *token = strtok(c," ");
                        while(token != NULL){
                            strcpy(a[n],token);
                            ++n;
                            token = strtok(NULL," ");
                        }
                        chuanhoa2(a[n-1]);
                        printf("%s, ",a[n-1]);
                        for(int i =0;i<n;i++){
                            chuanhoa1(a[i]);
                            printf("%s",a[i]);
                            if(i != n-1) printf(" ");
                        }
                        printf("\n");
                    }
                } 
```
