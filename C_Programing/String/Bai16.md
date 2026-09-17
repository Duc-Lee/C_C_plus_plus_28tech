# Bài 20. Từ lặp đầu tiên trong xâu
Chỉ ra từ đầu tiên lặp trong xâu, nếu không có từ nào lặp in ra -1.

**Input**
Dòng đầu tiên là số lượng test case T (1≤T≤100).
Mỗi test case gồm 1 dòng duy nhất là xâu có không quá 1000 kí tự

**Output**
Từ lặp đầu tiên trong xâu hoặc chỉ ra rằng nó không tồn tại (xem ví dụ).

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2<br>ngon &nbsp; ngu &nbsp; lap trinh C python lap trinh ngon<br>a abcd aa aaa bc d | #Test 1: lap<br>#Test 2: -1 |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                int main(){
                    int t;
                    scanf("%d", &t);
                    getchar(); 
                    for(int tc = 1; tc <= t; tc++){
                        char c[1005];
                        gets(c);
                        char a[100][50];
                        int n = 0;
                        char *token = strtok(c, " ");
                        while(token != NULL){
                            strcpy(a[n], token);
                            ++n;
                            token = strtok(NULL, " ");
                        }
                        for(int i = 0; i < n; i++){
                            int ok = 0;
                            for(int j = 0;j < i;j++){
                                // lấy đc ptu lặp đầu tiên 
                                if(strcmp(a[i], a[j]) == 0){
                                    ok = 1;
                                    break;
                                }
                            }
                            if(ok){
                                printf("%s\n", a[i]);
                                break;
                            }
                        }                        
                        if(!res) printf("-1");
                        printf("#Test %d: ", tc);
                    }
                } 
```
