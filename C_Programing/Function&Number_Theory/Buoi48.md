**Bài 39. Mã hàng hóa**

Trong mã hàng hóa người ta thường ghi kèm theo mã số quốc gia sản xuất. Nếu sản xuất tại Việt Nam thì mã tương ứng là 084. Bài toán đặt ra là cho một dãy mã dạng số nguyên không quá 18 chữ số. Hãy loại bỏ đoạn mã 084 ra khỏi mã ban đầu.

Dữ liệu đảm bảo dãy mã luôn có duy nhất một lần cụm 084.

**Input**

Dòng đầu ghi số bộ test. Mỗi test là một số nguyên có ít nhất 4 chữ số nhưng không quá 18 chữ số.

**Output**

Ghi ra kết quả sau khi loại bỏ 084

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 3<br>123084567<br>3300478808445<br>1084 | <br>123567<br>3300478845<br>1 |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <math.h>

                void solve(char c[]) {
                    int len = strlen(c);
                    for (int i = 0; i < len; i++) {
                        // Kiểm tra xem 3 ký tự tính từ i có phải là 084 không
                        // i <= len - 3 : Đảm bảo rằng khi ta truy cập c[i+1] và c[i+2] không bị vượt ra ngoài phạm vi của chuỗi
                        // c[i] == '0' && c[i+1] == '8' && c[i+2] == '4' : Kiểm tra xem 3 ký tự tính từ i có phải là 084 không
                        if (i <= len - 3 && c[i] == '0' && c[i+1] == '8' && c[i+2] == '4') {
                            // Tăng i thêm 2 để nhảy qua '8' và '4' 
                            i += 2; 
                            continue;
                        }
                        printf("%c", c[i]);
                    }
                }

                int main() {
                    int t;
                    scanf("%d", &t);
                    while (t--) {
                        char c[25];
                        scanf("%s", c);
                        solve(c);
                        printf("\n");
                    }
                    return 0;
                }
```