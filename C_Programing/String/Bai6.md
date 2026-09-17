# Bài 1. Liệt kê các từ xuất hiện trong câu
Cho một xâu có không quá 1000 kí tự, thực hiện liệt kê các từ trong câu

**Input**
Dòng duy nhất chứa xâu có không quá 1000 kí tự

**Output**
Mỗi từ trong xâu in trên một dòng

**Ví dụ**

| Input | Output |
| :--- | :--- |
| Python &nbsp; &nbsp; Java C++ &nbsp; &nbsp; PHP JS | Python<br>Java<br>C++<br>PHP<br>JS |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                int main(){
                    char c[1005];
                    gets(c);
                    // dùng hàm strtok()
                    // để lọc khoảng cách thì dùng " "
                    // sau mỗi lần tách thì strtok giúp mình trỏ con trỏ vô đầu kí tự 
                    char *token = strtok(c," ");
                    // strtok() trả về con trỏ null
                    while(token != NULL){
                        printf("%s\n",token);
                        // dùng null vì sau lần đầu tiên thì strtok đã ghi nhớ vị trí tách trước đó
                        // mà sau mỗi từ hay gọi là xâu là kí tự "\0" 
                        token = strtok(NULL," ");
                    }
                } 
```
- Giải thích từng bước lặp : 
Giả sử xâu ban đầu nhập vào là `c = "Python      Java C++    PHP JS"`.
Đặc điểm của hàm `strtok` là nó cắt xâu bằng cách đi tìm các kí tự phân cách (ở đây là khoảng trắng `" "`), rồi tráo kí tự đó thành kí tự kết thúc chuỗi `\0`. Đồng thời, nó "âm thầm" tự ghi nhớ vị trí mà nó đang cắt dở để lần sau cắt tiếp.

**1. Khởi tạo (Lần gọi đầu tiên):**
`char *token = strtok(c, " ");`
- Bạn truyền xâu `c` vào. `strtok` sẽ đi tìm từ đầu tiên là `"Python"`.
- Gặp hàng loạt khoảng trắng ngay sau `"Python"`, nó sẽ thay khoảng trắng đầu tiên bằng kí tự `\0`.
- Con trỏ `token` lúc này đang nắm đầu chữ `'P'` của `"Python"`. Đồng thời, `strtok` đã bí mật ghi nhớ vị trí ngay phía sau chữ "Python".

**2. Đi vào vòng lặp `while(token != NULL)`:**
- **Vòng lặp 1:** In ra `"Python"`. Sau đó gọi `token = strtok(NULL, " ");`.
  *Giải thích chữ `NULL`: Bạn truyền `NULL` để báo cho hàm biết là "hãy lấy vị trí cắt dở từ lần trước ra chạy tiếp đi". Hàm tự động bỏ qua các dấu cách thừa, thấy chữ `"Java"`, chèn `\0` vào ngay sau chữ Java, và `token` lúc này trỏ vào chữ `'J'`.
- **Vòng lặp 2:** In ra `"Java"`. Gọi `token = strtok(NULL, " ");`.
  Tiếp tục nhảy đến `"C++"`. `token` trỏ vào `'C'`.
- **Vòng lặp 3:** In ra `"C++"`. Gọi `token = strtok(NULL, " ");`.
  Nhảy đến `"PHP"`. `token` trỏ vào `'P'`.
- **Vòng lặp 4:** In ra `"PHP"`. Gọi `token = strtok(NULL, " ");`.
  Tiến tới cuối xâu gặp chữ `"JS"`. Vì `"JS"` nằm cuối cùng (chạm vách `\0` zin của chuỗi), hàm vẫn bốc được `"JS"` và `token` trỏ vào `'J'`.
- **Vòng lặp 5:** In ra `"JS"`. Gọi `token = strtok(NULL, " ");`.
  Lúc này xâu đã hoàn toàn cạn kiệt, không còn từ nào nữa. `strtok` "chịu thua" và trả về con trỏ `NULL`.
- Gặp vòng lặp `while(token != NULL)` kiểm tra thấy `NULL` -> Sai -> Lập tức bẻ gãy vòng lặp. Kết thúc chương trình.


# Bài 2. Đếm số lượng từ trong câu
Cho một xâu có không quá 1000 kí tự, thực hiện đếm số lượng từ trong xâu.

**Input**
Dòng duy nhất chứa xâu có không quá 1000 kí tự

**Output**
Số lượng từ trong xâu

**Ví dụ**

| Input | Output |
| :--- | :--- |
| Python &nbsp; &nbsp; Java C++ &nbsp; &nbsp; PHP JS | 5 |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                int main(){
                    char c[1005];
                    gets(c);
                    // khoi tao bien dem 
                    int cnt = 0;
                    // tach tu trong cau 
                    char *token = strtok(c," ");
                    while(token != NULL){
                        ++cnt;
                        token = strtok(NULL," ");
                    }   
                    printf("%d",cnt);
                } 
```

# Bài 3. Liệt kê các từ in hoa trong xâu
Cho một xâu có không quá 1000 kí tự, thực hiện liệt kê các từ in hoa trong xâu.

**Input**
Dòng đầu tiên là số lượng test case T (1≤T≤100).
T dòng tiếp theo mỗi dòng chứa xâu có không quá 1000 kí tự

**Output**
Liệt kê các từ in hoa của xâu, kết quả in trên 1 dòng

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2<br>Python &nbsp; &nbsp; Java C++ &nbsp; &nbsp; PHP JS<br>Pham NGOC &nbsp;hai | PHP JS<br>NGOC |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                // Hàm kiểm tra xem 1 từ có phải in hoa toàn bộ hay không
                int check(char c[]){
                    for(int i = 0; i < strlen(c); i++){
                        // nếu chữ in thường 
                        if(tolower(c)){
                            return 0;
                        }
                    }
                    return 1;
                }

                int main(){
                    int t;
                    scanf("%d", &t);
                    // đọc enter thừa
                    getchar(); 
                    while(t--){
                        char c[1005];
                        gets(c);
                        // tách chữ 
                        char *token = strtok(c," ");
                        while(token != NULL){
                            // kiểm tra điều kiện toàn chữ in hoa ko 
                            if(check(token)){
                                printf("%s ",token);
                            }
                        }
                        printf("\n");
                    }
                } 
```

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
                
                int main(){
                    int t;
                    scanf("%d", &t);
                    getchar(); 
                    while(t--){
                        char c[1005];
                        gets(c);
                        
                        
                        printf("\n");
                    }
                } 
```
