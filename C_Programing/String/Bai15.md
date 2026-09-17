# Bài 19. Xóa từ trong câu
Thực hiện xóa từ trong xâu không phân biệt hoa thường. Cho trước 1 xâu chỉ gồm chữ cái và khoảng trắng và một từ. Thực hiện tìm kiếm từ trong xâu 1 không phân biệt hoa thường và loại bỏ từ khỏi xâu

**Input**
Dòng đầu tiên là số lượng test case T (1≤T≤100).
Mỗi test case gồm 2 dòng :
Dòng đầu tiên là xâu 1 có không quá 1000 kí tự
Dòng 2 là từ có không quá 100 kí tự

**Output**
Thực hiện xóa từ khỏi xâu, có in kèm số thứ tự test case (xem ví dụ).

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2<br>ngon &nbsp; ngu &nbsp; lap trinh C python lap trinh<br>trinh<br>aaa AAA bcd bc Aaa ZZZ<br>aaa | #Test 1: ngon ngu lap C python lap<br>#Test 2: bcd bc ZZZ |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                // Hàm so sánh 2 chuỗi không phân biệt hoa thường
                // Trả về 1 nếu giống nhau, 0 nếu khác nhau
                int strcmp1(char a[], char b[]){
                    int n1 = strlen(a);
                    int n2 = strlen(b);
                    if(n1 != n2) return 0;
                    for(int i = 0; i < n1; i++){
                        if(tolower(a[i]) != tolower(b[i]))
                            return 0;
                    }
                    return 1;
                }

                int main(){
                    int t;
                    scanf("%d", &t);
                    getchar(); 
                    for(int tc = 1; tc <= t; tc++){
                        char c[1005], w[105];
                        gets(c);
                        scanf("%s", w);
                        // CỰC KÌ QUAN TRỌNG: Xóa dấu enter thừa sau khi dùng scanf
                        // Nếu không vòng lặp sau hàm gets(c) sẽ bị trôi lệnh!
                        getchar();
                        
                        printf("#Test %d: ", tc);
                        char *token = strtok(c, " ");
                        while(token != NULL){
                            // Nếu trả về 0 (nghĩa là token KHÁC w) thì mới in
                            if(strcmp1(token, w) == 0){
                                printf("%s ", token);
                            }
                            token = strtok(NULL, " ");
                        }
                        printf("\n");
                    }
                } 
```
