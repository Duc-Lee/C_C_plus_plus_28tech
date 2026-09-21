**Bài 38. Số cắt đôi**

Với một vài số nguyên dương có 1 chữ số, khi cắt đôi số đó theo chiều ngang và lấy nửa phía trên thì ta vẫn có một số nguyên. Cụ thể:
- Số 0 cắt đôi vẫn ra số 0
- Số 1 cắt đôi vẫn ra số 1
- Số 8 cắt đôi ra số 0
- Số 9 cắt đôi ra số 0
- Các số khác cắt đôi sẽ không hợp lệ.

Cho một số nguyên dương không quá 18 chữ số. Hãy in ra kết quả "cắt đôi" của số đó.

Nếu không hợp lệ thì ghi ra INVALID. Chú ý: nếu cắt đôi ra một dãy toàn 0 thì cũng được coi là không hợp lệ. Kết quả cắt đôi thì không tính chữ số 0 ở đầu.

**Input**

Dòng đầu ghi số bộ test. Mỗi bộ test ghi một số nguyên dương không quá 18 chữ số.

**Output**

Ghi ra kết quả tính toán

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 3<br>1890<br>3681<br>8919 | <br>1000<br>INVALID<br>10 |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>

                void solve(char c[]) {
                    int len = strlen(c);
                    for (int i = 0; i < len; i++) {
                        // Chỉ có các số 0, 1, 8, 9 là hợp lệ
                        if (c[i] == '0' || c[i] == '8' || c[i] == '9') {
                            c[i] = '0';
                        } else if (c[i] == '1') {
                            c[i] = '1';
                        } else {
                            // Gặp bất kỳ số nào khác thì không hợp lệ
                            printf("INVALID\n");
                            return; // Thoát hàm luôn
                        }
                    }
                    // In ra và loại bỏ các số 0 ở đầu
                    int ok = 0; // Biến kiểm tra xem đã gặp chữ số khác 0 chưa
                    // kết quả cắt đôi sẽ không có số 0 ở đầu
                    for (int i = 0; i < len; i++) {
                        if (c[i] != '0') {
                            ok = 1; // Đã gặp số khác 0
                        }
                        if (ok == 1) {
                            printf("%c", c[i]);
                        }
                    }
                    // Nếu ok vẫn bằng 0, tức là chuỗi sau khi cắt đôi là toàn số 0
                    // => cũng coi là không hợp lệ
                    if (ok == 0) {
                        printf("INVALID\n");
                    } else {
                        printf("\n");
                    }
                }

                int main() {
                    int t;
                    scanf("%d", &t);
                    while (t--) {
                        char c[25]; 
                        scanf("%s", c);
                        solve(c);
                    }
                    return 0;
                }
```
                        