# Bài 14. Từ có số lần xuất hiện nhiều nhất trong xâu
Thực hiện đếm số lần xuất hiện của các từ trong xâu, không phân biệt hoa thường. In ra từ có số lần xuất hiện nhiều nhất, nếu có nhiều từ có cùng số lần xuất hiện nhiều nhất thì chọn từ có thứ tự từ điển nhỏ hơn.

**Input**
Dòng duy nhất chứa xâu có không quá 1000 kí tự

**Output**
Từ có số lần xuất hiện nhiều nhất và có thứ tự từ điển nhỏ nhất.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| PYTHON Java &nbsp; &nbsp; php php java pyTHON C | java 2 |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                int main(){
                    char c[1005];
                    gets(c);
                    // chuyển về chữ in thường 
                    strlwr(c);
                    char a[20][50];
                    char *token = strtok(c," ");
                    int n = 0;
                    while(token != NULL){
                        strcpy(a[n],token);
                        ++n;
                        token = strtok(NULL," ");
                    }
                    int max = 0, idx;
                    for(int i =0;i<n;i++){
                        int cnt  = 1;
                        for(int j = i + 1; j < n;j++){
                            if(strcmp(a[i],a[j])==0){
                                cnt++;
                            }
                        }
                        // tìm kỉ lục 
                        if(cnt > max){
                            max = cnt;
                            idx = i;
                        }
                        // nếu cùng số lần xuất hiện 
                        else if(cnt == max){
                            if(strcmp(a[i],a[idx])<0){
                                idx = i;
                            }
                        }
                        
                    }
                    printf("%s %d",a[idx],max);
                } 
```

# Bài 15. Liệt kê các từ xuất hiện trong câu
Thực hiện liệt kê các từ trong câu theo thứ tự xuất hiện

**Input**
Dòng duy nhất chứa xâu có không quá 1000 kí tự

**Output**
In ra các từ trong câu theo thứ tự xuất hiện, mỗi từ chỉ in 1 lần.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| lap &nbsp; trinh &nbsp; python &nbsp; &nbsp; &nbsp; &nbsp; java python c lap trinh | lap trinh python java c |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
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
                    // duyệt qua từng từ 
                    for(int i =0;i<n;i++){
                        //kiểm tra xem đã xuất hiện ở trước đó chưa 
                        int ok = 1;
                        for(int j = 0;j < i;j++){
                            if(strcmp(a[i],a[j])==0){
                                ok = 0;
                                // break này để thoát khỏi vòng lặp j 
                                break;
                            }
                        }
                        if(ok){
                            printf("%s ",a[i]);
                        }
                    }
                } 
```
