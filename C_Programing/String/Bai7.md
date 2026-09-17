# Bài 4. Sắp xếp các từ trong xâu theo thứ tự từ điển
Cho một xâu có không quá 1000 kí tự, thực hiện sắp xếp các từ trong xâu theo thứ tự từ điển.

**Input**
Dòng đầu tiên là số lượng test case T (1≤T≤100).
T dòng tiếp theo mỗi dòng chứa xâu có không quá 1000 kí tự

**Output**
Liệt kê các từ trong xâu theo thứ tự từ điển tăng dần

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2<br>aa abc aaa a bc z<br>nguyen &nbsp; van &nbsp; long | a aa aaa abc bc z<br>long nguyen van |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                void selection_sort(char c[][50],int n){
                    for(int i =0;i<n;i++){
                        int min = i;
                        for(int j = i + 1;j<n;j++){
                            // sx tăng dần
                            if(strcmp(a[j],a[m]) < 0) min = j;
                        }
                        char tmp[100]; // khai báo mảng kí tự
                        // swap lại 
                        strcpy(tmp,a[min]);
                        strcpy(a[min],a[i];
                        strcpy(a[i]),tmp);
                    }
                }
                int main(){
                    int t;
                    scanf("%d", &t);
                    getchar(); 
                    while(t--){
                        char c[1005];
                        gets(c);
                        // khai báo xâu kí tự 2 chiều 
                        char a[20][50];
                        // khai báo đếm số lượng từ trong câu 
                        int n =0;
                        char *token = strtok(c," ");
                        while(token != NULL){
                            // copy xâu kí tự vừa tách cho vô a[n]
                            // xâu kh thể gán như số được nên phải dùng strcpy()
                            strcpy(a[n],token);
                            ++n;
                            token = strtok(NULL, " ");
                        }
                        selection_sort(a,n);
                        // In ra theo thứ tự 
                        for(int i = 0; i < n; i++){
                            printf("%s ",a[i]);
                        }
                        printf("\n");
                    }
                } 
```
