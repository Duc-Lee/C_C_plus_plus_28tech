# Bài 6. Đếm số lần xuất hiện của các kí tự trong xâu 3
Thực hiện nhập vào một xâu kí tự có không quá 1000 kí tự. In ra kí tự có tần suất xuất hiện nhiều nhất trong xâu, trong trường hợp có nhiều kí tự có cùng số lần xuất hiện thì in ra kí tự có thứ tự từ điển lớn hơn.

**Input**
Dòng duy nhất là xâu kí tự không quá 5000 kí tự

**Output**
Kí tự có số lần xuất hiện lớn nhất

**Ví dụ**

| Input | Output |
| :--- | :--- |
| baaaabca bbb | b |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                int main(){
                    char c[5005];
                    gets(c);
                    // khởi tạo mảng đếm tần suất
                    int cnt[256] = {0};
                    for(int i = 0;i < strlen(c);i++){
                        cnt[c[i]]++;
                    }
                    // biến tần suất lớn nhất 
                    int res = 0;
                    char kt;
                    for(int i =0; i< strlen(c);i++){
                        if(cnt[i]){
                            // Do đề bài bảo có cùng số lần xuất hiện 
                            //  nên dùng >= 
                            if(cnt[i] >= res ){
                                res = cnt[i];
                                kt = (char)(i);
                            }
                        }
                    }
                    printf("%c",kt);
                } 
```

# Bài 7. Các kí tự xuất hiện ở cả 2 xâu
Cho 2 xâu kí tự, thực hiện liệt kê các kí tự xuất hiện ở cả 2 xâu theo thứ tự từ điển

**Input**
Dòng thứ 1 là xâu 1
Dòng thứ 2 là xâu 2

**Output**
In ra các kí tự xuất hiện ở cả 2 xâu

**Ví dụ**

| Input | Output |
| :--- | :--- |
| Python java PHP<br>Project | Poj |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                int main(){
                    char c1[1005], c2[1005];
                    gets(c1);
                    gets(c2);
                    // Khơi tạo biến đếm tần suất 
                    int cnt[256] = {0};
                    for(int i =0;i< strlen(c1);i++){
                        // nếu xuất hiện thì cho 1
                        cnt[c1[i]] = 1;
                    }                   
                    for(int i = 0;i < strlen(c2);i++){
                        if(cnt[c2[i]]){
                            // gán 2 là đã xuất hiện ở cả 2 xâu 
                            cnt[c2[i]] = 2;
                        }
                    }
                    // in ra kết quả 
                    for(int i=0;i<256;i++){
                        if(cnt[i]==2){
                            printf("%c",i);
                        }
                    }
                } 
```

# Bài 8. Liệt kê các kí tự chỉ xuất hiện trong xâu 1 mà không xuất hiện trong xâu 2
Cho 2 xâu kí tự, thực hiện liệt kê các kí tự xuất hiện ở xâu 1 mà không xuất hiện ở xâu 2. Các kí tự trong 2 xâu chỉ gồm các chữ cái

**Input**
Dòng thứ 1 là xâu 1
Dòng thứ 2 là xâu 2

**Output**
In ra các kí tự theo thứ tự từ điển

**Ví dụ**

| Input | Output |
| :--- | :--- |
| Abcabcabc<br>ac | Ab |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                int main(){
                    char c1[1005], c2[1005];
                    gets(c1);
                    gets(c2);
                    // Khơi tạo biến đếm tần suất 
                    int cnt[256] = {0};
                    for(int i =0;i< strlen(c1);i++){
                        // nếu xuất hiện thì cho 1
                        cnt[c1[i]] = 1;
                    }                   
                    for(int i = 0;i < strlen(c2);i++){
                        if(cnt[c2[i]]){
                            // gán 0 là đã xuất hiện ở xâu 2 rồi  
                            cnt[c2[i]] = 0;
                        }
                    }
                    // in ra kết quả 
                    for(int i=0;i<256;i++){
                        if(cnt[i]!= 0){
                            printf("%c",i);
                        }
                    }
                }
```

# Bài 9. Liệt kê các kí tự xuất hiện ở 1 hoặc 2 xâu.
Cho 2 xâu kí tự, thực hiện liệt kê các kí tự xuất hiện ở xâu 1 hoặc xuất hiện ở xâu 2. Các kí tự trong 2 xâu chỉ gồm các chữ cái

**Input**
Dòng thứ 1 là xâu 1
Dòng thứ 2 là xâu 2

**Output**
In ra các kí tự theo thứ tự từ điển

**Ví dụ**

| Input | Output |
| :--- | :--- |
| Abcdu<br>abcdz | Aabcduz |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                int main(){
                    char c1[1005], c2[1005];
                    gets(c1);
                    gets(c2);
                    // Khơi tạo biến đếm tần suất 
                    int cnt[256] = {0};
                    for(int i =0;i< strlen(c1);i++){
                        // nếu xuất hiện thì cho 1
                        cnt[c1[i]] = 1;
                    }                   
                    for(int i = 0;i < strlen(c2);i++){
                        if(cnt[c2[i]]){
                            // gán 1 là đã xuất hiện ở xâu 2 rồi  
                            cnt[c2[i]] = 1;
                        }
                    }
                    // in ra kết quả 
                    for(int i=0;i<256;i++){
                        if(cnt[i] == 1){
                            printf("%c",i);
                        }
                    }
                } 
```
