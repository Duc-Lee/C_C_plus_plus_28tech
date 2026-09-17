# Bài 5. Sắp xếp các từ trong xâu theo chiều dài
Cho một xâu có không quá 1000 kí tự, thực hiện sắp xếp các từ trong xâu theo thứ tự chiều dài tăng dần, trong trường hợp có nhiều từ có cùng chiều dài thì từ có thứ tự từ điển nhỏ hơn sẽ xếp trước.

**Input**
Dòng đầu tiên là số lượng test case T (1≤T≤100).
T dòng tiếp theo mỗi dòng chứa xâu có không quá 1000 kí tự

**Output**
Liệt kê các từ trong xâu theo thứ tự đầu bài yêu cầu

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2<br>aa abc aaa a bc z<br>nguyen &nbsp; van &nbsp; long | a z aa bc abc aaa<br>van long nguyen |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                void selection_sort(char a[][50], int n){
                    for(int i = 0; i < n - 1; i++){
                        int min = i;
                        for(int j = i + 1; j < n; j++){
                            // Ưu tiên 1: Chiều dài ngắn hơn thì xếp trước
                            if(strlen(a[j]) < strlen(a[min])){
                                min = j;
                            }
                            // Ưu tiên 2: Nếu chiều dài bằng nhau thì xét thứ tự từ điển
                            else if(strlen(a[j]) == strlen(a[min])){
                                if(strcmp(a[j], a[min]) < 0){
                                    min = j;
                                }
                            }
                        }
                        char tmp[100]; // khai báo mảng kí tự tạm
                        // swap lại 
                        strcpy(tmp, a[min]);
                        strcpy(a[min], a[i]);
                        strcpy(a[i], tmp);
                    }
                }

                int main(){
                    int t;
                    scanf("%d", &t);
                    getchar(); 
                    while(t--){
                        char c[1005];
                        gets(c);
                        // khai báo xâu kí tự 2 chiều (tăng lên 100 từ cho an toàn)
                        char a[100][50];
                        // đếm số lượng từ trong câu 
                        int n = 0;
                        char *token = strtok(c, " ");
                        while(token != NULL){
                            // copy xâu kí tự vừa tách cho vô a[n]
                            strcpy(a[n], token);
                            ++n;
                            token = strtok(NULL, " ");
                        }
                        selection_sort(a, n);
                        // In ra theo thứ tự 
                        for(int i = 0; i < n; i++){
                            printf("%s ", a[i]);
                        }
                        printf("\n");
                    }
                } 
```
