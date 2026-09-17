## Bài 34. Ghép xâu

Cho trước các từ, hãy ghép các từ này thành một xâu sao cho xâu được ghép có thứ tự từ điển nhỏ nhất

**Input**

Dòng đầu tiên là số lượng test case T (1<=T<=100).

Mỗi test case gồm 1 dòng gồm số đầu tiên là n - số từ trong test case, theo sau là n từ

**Output**

In ra xâu ghép có thứ tự từ điển nhỏ nhất

**Ví dụ**

**Input**
```text
2

4 java python c php

5 a b cdef zabc word
```

**Output**
```text
cjavaphppython

abcdefwordzabc
```

**Code**
```cpp
                            #include <stdio.h>
                            #include <string.h>
                            #include <stdlib.h>
                            #include <ctype.h>
                            
                            void selection(char a[][100], int n){
                                for(int i = 0; i < n - 1; i++){
                                    int min_idx = i;
                                    for(int j = i + 1; j < n; j++){
                                        // Tạo xâu xy = a[min_idx] + a[j]
                                        char xy[205];
                                        // copy xâu a[min_idx] vào xâu xy
                                        strcpy(xy, a[min_idx]);
                                        // nối xâu bằng hàm strcat
                                        strcat(xy, a[j]);
                                        // Tạo xâu yx = a[j] + a[min_idx]
                                        char yx[205];
                                        // copy xâu a[j] vào xâu yx
                                        strcpy(yx, a[j]);
                                        // nối xâu a[min_idx] vào xâu yx
                                        strcat(yx, a[min_idx]);
                                        // So sánh xy và yx
                                        if(strcmp(yx, xy) < 0){
                                            // nếu yx < xy thì đổi chỗ cho nhau
                                            min_idx = j;
                                        }
                                    }
                                    // Hoán vị 2 xâu
                                    char tmp[100];
                                    strcpy(tmp, a[i]);
                                    strcpy(a[i], a[min_idx]);
                                    strcpy(a[min_idx], tmp);
                                }
                            }
                            int main(){
                                int t;
                                scanf("%d",&t);
                                while(t--){
                                    int n;
                                    scanf("%d",&n);
                                    // khai báo xâu 2 chiều
                                    // có n dòng 
                                    char a[n][100];
                                    for(int i = 0;i<n;i++){
                                        scanf("%s",a[i]);
                                    }
                                    // sắp xếp lại xâu
                                    selection(a, n);
                                    // in kết quả
                                    for(int i = 0;i<n;i++){
                                        printf("%s",a[i]);
                                    }
                                    printf("\n");
                                }
                            }
                            ```