# Bài 10. Email 1
Thực hiện tạo email từ tên người dùng

**Input**
Dòng đầu tiên là số lượng test case T (1≤T≤100).
T dòng tiếp theo mỗi dòng chứa xâu có không quá 1000 kí tự

**Output**
In tên email được cấp theo mẫu

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2<br>NguYEN &nbsp; VAN &nbsp; &nbsp; &nbsp; &nbsp; maNH<br> &nbsp;nGUYEN &nbsp; &nbsp; thuY &nbsp; &nbsp;LinH | manhnv@gmail.com<br>linhnt@gmail.com |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                void chuanhoa(char c[]){
                    for(int i = 0;i< strlen(c);i++){
                        c[i] = tolower(c[i]);
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
                        printf("%s",a[n-1]);
                        for(int i =0;i<n-1;i++){
                            chuanhoa(a[i]);
                            // In kí tự đầu tiên của mỗi từ
                            printf("%c",a[i][0]);
                        }
                        printf("@gmail.com\n");
                    }
                } 
```

# Bài 11. Email 2
Thực hiện tạo email từ tên người dùng

**Input**
Dòng đầu tiên là số lượng test case T (1≤T≤100).
T dòng tiếp theo mỗi dòng chứa xâu có không quá 1000 kí tự

**Output**
In tên email được cấp theo mẫu

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2<br>NguYEN &nbsp; VAN &nbsp; &nbsp; &nbsp; &nbsp; maNH<br> &nbsp;nGUYEN &nbsp; &nbsp; thi &nbsp; thuY &nbsp; &nbsp;LinH | nvmanh@gmail.com<br>nttlinh@gmail.com |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                void chuanhoa(char c[]){
                    for(int i = 0;i< strlen(c);i++){
                        c[i] = tolower(c[i]);
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
                        // In kí tự đầu tiên của mỗi từ
                        for(int i =0;i<n-1;i++){
                            chuanhoa(a[i]);
                            printf("%c",a[i][0]);
                        }
                        chuanhoa(a[n-1]);
                        printf("%s",a[n-1]);
                        printf("@gmail.com\n");
                    }
                } 
```
