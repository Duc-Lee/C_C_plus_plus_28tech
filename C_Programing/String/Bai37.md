## Bài 41. Xâu con lớn nhất (C).

Xâu con của một xâu ký tự S được tạo ra bằng cách lấy một hoặc nhiều ký tự trong S và giữ nguyên thứ tự ban đầu.

Cho xâu S chỉ bao gồm các chữ cái viết thường. Hãy in ra xâu con có thứ tự từ điển là lớn nhất.

**Input**

Chỉ có xâu ký tự S, độ dài không quá 100000. Không có khoảng trống.

**Output**

Ghi ra xâu con có thứ tự từ điển lớn nhất.

**Ví dụ**

**Input**
```text
ababba
```

**Output**
```text
bbba
```

**Input**
```text
abbcbccacbbcbaaba
```

**Output**
```text
cccccbba
```

**Code**
```cpp
                        #include <stdio.h>
                        #include <string.h>
                        #include <stdlib.h>
                        #include <ctype.h>

                        int main(){
                            char c[100001];
                            scanf("%s", c);
                            int pos = 0, n = strlen(c);
                            // sau mỗi vòng lặp while 
                            // lại duyệt lại xâu c từ vị trí pos
                            // để tìm phần tử lớn nhất trong đoạn còn lại của xâu
                            // pos được cập nhật ở cuối vòng lặp
                            while(pos < n){
                                // tìm kí tự có thứ tự từ điển lớn nhất
                                // tính pos => n -1
                                char tmp = c[pos];
                                int idx = pos;
                                for(int i = pos; i < n; i++){
                                    // tìm kí tự lớn nhất
                                    if(c[i] > tmp){
                                        tmp = c[i];
                                    }
                                }
                                for(int i = pos; i < n; i++){
                                    if(c[i] == tmp){
                                        printf("%c",c[i]);
                                        // đánh dấu vị trí cuối cùng của kí tự lớn nhất hiện tại 
                                        idx = i; 
                                    }
                                }
                                // tăng biến index xâu lên
                                pos = idx + 1;
                            }
                            return 0;
                        }
                        

```