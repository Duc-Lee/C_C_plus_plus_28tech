# Bài 12. Đếm số lần xuất hiện của các từ trong xâu
Thực hiện đếm số lần xuất hiện của các từ trong xâu, không phân biệt hoa thường. Kết quả in ra các từ trong xâu theo thứ tự xuất hiện.

**Input**
Dòng duy nhất chứa xâu có không quá 1000 kí tự

**Output**
Các từ trong xâu ở dạng in thường và số lần xuất hiện của chúng

**Ví dụ**

| Input | Output |
| :--- | :--- |
| PYTHON Java &nbsp; &nbsp; php php java pyTHON C | python 2<br>java 2<br>php 2<br>c 1 |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                int main(){
                    char c[1005];
                    gets(c);
                    // chuyển hết c về in thường 
                    for(int i = 0; i < strlen(c); i++){
                        c[i] = tolower(c[i]);
                    }
                    char a[20][50];
                    char *token = strtok(c," ");
                    int n = 0;
                    while(token != NULL){
                        strcpy(a[n],token);
                        ++n;
                        token = strtok(NULL," ");
                    }
                    // Khai báo mảng tần suất 
                    int cnt[n] = {0};
                    
                    for(int i =0;i<n;i++){
                        int res = 1;
                        // Kiểm tra xem từ a[i] đã xuất hiện ở vị trí nào trước đó chưa 
                        for(int j = i + 1;j < n;j++){
                            if(strcmp(a[i],a[j])==0){
                                ++res;
                                // xong gán 1 đánh dấu đã đếm nó rồi 
                                cnt[j] = 1;
                            }
                        }
                        printf("%s %d\n",a[i],res);
                    }
                } 
```

# Bài 13. Đếm số lần xuất hiện của các từ trong xâu 2
Thực hiện đếm số lần xuất hiện của các từ trong xâu, không phân biệt hoa thường. Kết quả in ra các từ trong xâu theo thứ tự từ điển tăng dần.

**Input**
Dòng duy nhất chứa xâu có không quá 1000 kí tự

**Output**
Các từ trong xâu ở dạng in thường và số lần xuất hiện của chúng

**Ví dụ**

| Input | Output |
| :--- | :--- |
| PYTHON Java &nbsp; &nbsp; php php java pyTHON C | c 1<br>java 2<br>php 2<br>python 2 |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                void sx(char a[][50], int n){
                    for(int i = 0;i < n; i++){
                        for(int j = i + 1; j < n; j++){
                            if(strcmp(a[i],a[j])>0){
                                char tmp[50];
                                strcpy(tmp,a[i]);
                                strcpy(a[i],a[j]);
                                strcpy(a[j],tmp);
                            }
                        }
                    }
                }
                int main(){
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
                    sx(a,n); // sắp xếp lại mảng a theo từ điển
                    int cnt = 1;
                    // mảng đã được sắp xếp 
                    for(int i = 0;i < n;i++){
                        while(i < n - 1 && strcmp(a[i],a[i+1])==0){
                            ++cnt;
                            ++i;
                        }                        
                        printf("%s %d\n",a[i],cnt);  
                        // gán cnt lại cho 1 để bắt đầu đếm từ đầu                                      
                        cnt = 1;
                    }
                } 
```
