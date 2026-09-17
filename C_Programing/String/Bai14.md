# Bài 17. Tập từ riêng của 2 xâu
Cho 2 xâu, mỗi xâu chứa các từ mỗi từ có độ dài không quá 100 kí tự, thực hiện liệt kê các từ chỉ xuất hiện trong xâu 1 mà không xuất hiện trong xâu thứ 2 theo thứ tự từ điển, mỗi từ chỉ liệt kê một lần

**Input**
Dòng đầu tiên là xâu 1 có không quá 1000 kí tự
Dòng 2 là xâu 2 có không quá 1000 kí tự

**Output**
Các từ xuất hiện trong xâu 1 mà không xuất hiện trong xâu 2

**Ví dụ**

| Input | Output |
| :--- | :--- |
| lap &nbsp; trinh &nbsp; python &nbsp; &nbsp; &nbsp; &nbsp; java python c lap trinh<br>trinh php java | c lap python |


**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                int main(){
                    char s1[1005], s2[1005];
                    gets(s1);
                    gets(s2);
                    char a[20][50],b[20][50];
                    char *token = strtok(s1," ");
                    int n = 0;
                    while(token != NULL){
                        strcpy(a[n],token);
                        ++n;
                        token = strtok(NULL," ");
                    }
                    token = strtok(s2," ");
                    int m = 0;
                    while(token != NULL){
                        strcpy(b[m],token);
                        ++m;
                        token = strtok(NULL," ");
                    }
                    for(int i = 0;i < n;i++){
                        int ok = 1;
                        // nhảy qua các phần tử trung ngay trong chính mảng a
                        while(strcmp(a[i],a[i+1])==0){
                            i++;
                        }
                        for(int j = 0;j < m;j++){
                            // nếu xh ở cả 2 mảng thì break
                            if(strcmp(a[i],b[j])==0){
                                ok = 0;
                                break;
                            }
                        }
                        if(ok){
                            printf("%s ",a[i]);
                        }
                    }
                } 
```

# Bài 18. Tập từ riêng của 2 xâu 2
Cho 2 xâu, mỗi xâu chứa các từ mỗi từ có độ dài không quá 100 kí tự, thực hiện liệt kê các từ chỉ xuất hiện trong xâu 1 mà không xuất hiện trong xâu thứ 2 theo thứ tự từ điển, mỗi từ chỉ liệt kê một lần

**Input**
Dòng đầu tiên là số lượng test case T (1≤T≤100).
Mỗi test case gồm 2 dòng :
Dòng đầu tiên là xâu 1 có không quá 1000 kí tự
Dòng 2 là xâu 2 có không quá 1000 kí tự

**Output**
Các từ xuất hiện trong xâu 1 mà không xuất hiện trong xâu 2 theo từng test case.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2<br>lap &nbsp; trinh &nbsp; python &nbsp; &nbsp; &nbsp; &nbsp; java python c lap trinh<br>trinh php java<br>aaa abc abcd a<br>a abc | c java lap python<br><br>aaa abcd |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                // Hàm sắp xếp theo thứ tự từ điển
                void sx(char a[][50], int n){
                    for(int i = 0; i < n; i++){
                        for(int j = i + 1; j < n; j++){
                            if(strcmp(a[i], a[j]) > 0){
                                char tmp[50];
                                strcpy(tmp, a[i]);
                                strcpy(a[i], a[j]);
                                strcpy(a[j], tmp);
                            }
                        }
                    }
                }

                int main(){
                    int t;
                    scanf("%d", &t);
                    getchar(); 
                    while(t--){
                        char s1[1005], s2[1005];
                        gets(s1);
                        gets(s2);
                        
                        char a[100][50], b[100][50];
                        int n = 0, m = 0;
                        
                        // Tách xâu 1
                        char *token = strtok(s1, " ");
                        while(token != NULL){
                            strcpy(a[n], token);
                            ++n;
                            token = strtok(NULL, " ");
                        }
                        
                        // Tách xâu 2
                        token = strtok(s2, " ");
                        while(token != NULL){
                            strcpy(b[m], token);
                            ++m;
                            token = strtok(NULL, " ");
                        }
                        
                        // BƯỚC QUAN TRỌNG: Sắp xếp mảng a theo từ điển
                        sx(a, n);
                        
                        // Tìm và in kết quả
                        for(int i = 0; i < n; i++){
                            // Bỏ qua các từ trùng lặp liền kề nhau
                            while(i < n - 1 && strcmp(a[i], a[i+1]) == 0){
                                i++;
                            }
                            
                            int ok = 1; 
                            // Kiểm tra a[i] có nằm trong b không
                            for(int j = 0; j < m; j++){
                                if(strcmp(a[i], b[j]) == 0){
                                    ok = 0;
                                    break;
                                }
                            }
                            
                            // Nếu ok vẫn bằng 1 (không có trong b) thì in
                            if(ok == 1){
                                printf("%s ", a[i]);
                            }
                        }
                        printf("\n");
                    }
                } 
```

