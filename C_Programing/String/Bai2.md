# Bài 2. Nhập vào một xâu kí tự và chuyển các kí tự trong xâu thành kí tự in thường

**Input**
Xâu đầu vào không quá 1000 kí tự

**Output**
Xâu đầu ra trên 1 dòng

**Ví dụ**

| Input | Output |
| :--- | :--- |
| Python JAVA @ | python java @ |

**Code**
```cpp
                #include <stdio.h>
                #include <ctype.h>
                #include <string.h>
                #include <stdlib.h>

                int main(){
                    char c[1005];
                    gets(c);
                    for(int i =0;i< strlen(c);i++){
                        // chuyển in hoa về in thường ( nếu có)
                        // không thì giá trị vẫn giữ nguyên 
                        c[i] = tolower(c[i]);
                    }
                    printf("%s",c);
                }       
```

# Bài 3. Đếm số lượng chữ cái, kí tự số, kí tự đặc biệt trong xâu

**Input**
Xâu đầu vào không quá 1000 kí tự

**Output**
In kết quả trên 1 dòng

**Ví dụ**

| Input | Output |
| :--- | :--- |
| Python 123@@ | 6 3 3 |

**Code**
```cpp
                #include <stdio.h>
                #include <ctype.h>
                #include <string.h>
                #include <stdlib.h>

                int main(){
                    char c[1005];
                    gets(c);
                    // Khởi tạo 2 biến đếm 
                    int cnt1 = 0, cnt2 = 0;
                    for(int i =0;i< strlen(c);i++){
                        // kiểm tra xem kí tự có phải chữ không
                        if(isalpha(c[i])) ++cnt1;
                        // kiểm tra xem có phải số không
                        else if(isdigital(c[i])) ++cnt2;
                    }
                    // số lượng kí tự đặc biệt 
                    int cnt3 = strlen(c) - cnt1 - cnt2;
                    printf("%d %d %d",cnt1, cnt2, cnt3);
                } 

```

# Bài 4. Đếm số lần xuất hiện của các kí tự trong xâu 1
Nhập vào một xâu có không quá 1000 kí tự chỉ gồm các chữ cái in thường (in hoa). Thực hiện in ra các chữ cái cùng số lần xuất hiện của nó theo thứ tự từ điển

**Input**
Xâu đầu vào không quá 1000 kí tự chỉ gồm các chữ cái in thường (in hoa)

**Output**
In ra các kí tự và số lần xuất hiện tương ứng

**Ví dụ**

| Input | Output |
| :--- | :--- |
| aaababca | a 5<br>b 2<br>c 1 |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                int main(){
                    char c[1005];
                    gets(c);
                    // khởi tạo mảng kí tự
                    // 1 a -> z có 26 kí tự 
                    int cnt[26] = {0};
                    // Ý tưởng lưu kí tự + tần suất 
                    // a : 97 -> 0
                    // b : 98 -> 1
                    // c : 99 -> 2
                    // ....
                    // z : 122 -> 25
                    // nên để lưu được như v thì cnt[c[i] - 97]
                    for(int i =0;i< strlen(c);i++){
                        // đếm tần suất 
                        cnt[c[i] - 97]++;
                    }
                    // in kết quả 
                    for(int i =0;i < 26;i++){
                        if(cnt[i] != 0){
                            // i+97 là chuyển lại kí tự 
                            printf("%c %d\n",i+97,cnt[i]);
                        }
                    }
                } 
```

- Lưu ý : Nếu xâu cho kí tự in hoa thì 
```cpp
                            #include <stdio.h>
                            #include <string.h>
                            #include <stdlib.h>
                            #include <ctype.h>
                            
                            int main(){
                                char c[1005];
                                gets(c);
                                // khởi tạo mảng kí tự
                                // 1 A -> Z có 26 kí tự 
                                int cnt[26] = {0};
                                // Ý tưởng lưu kí tự + tần suất 
                                // A : 65 -> 0
                                // B : 66 -> 1
                                // C : 67 -> 2
                                // ....
                                // Z : 90 -> 25
                                // nên để lưu được như v thì cnt[c[i] - 65]
                                for(int i =0;i< strlen(c);i++){
                                    // đếm tần suất 
                                    cnt[c[i] - 65]++;
                                }
                                // in kết quả 
                                for(int i =0;i < 26;i++){
                                    if(cnt[i] != 0){
                                        // i+65 là chuyển lại kí tự 
                                        printf("%c %d\n",i+65,cnt[i]);
                                    }
                                } 
                            }  
```

# Bài 5. Đếm số lần xuất hiện của các kí tự trong xâu 2
Nhập vào một xâu có không quá 1000 kí tự (có thể bao gồm chữ cái, chữ số, kí tự đặc biệt). Thực hiện đếm và in ra các kí tự cùng số lần xuất hiện của nó theo thứ tự xuất hiện trong xâu, chú ý mỗi kí tự chỉ liệt kê một lần.

**Input**
Xâu đầu vào không quá 1000 kí tự

**Output**
In ra các kí tự và số lần xuất hiện tương ứng

**Ví dụ**

| Input | Output |
| :--- | :--- |
| baaaabc@##@AWNTE | b 2<br>a 4<br>c 1<br>@ 2<br># 2<br>A 1<br>W 1<br>N 1<br>T 1<br>E 1 |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                
                int main(){
                    char c[1005];
                    gets(c);
                    // khởi tạo mảng đếm 
                    int cnt[256] = {0};
                    for(int i =0;i< strlen(c);i++){
                        // Vì mảng có 256 phần tử, ta dùng luôn mã ASCII của kí tự làm index
                        cnt[c[i]]++;
                    }
                    for(int i =0;i< strlen(c);i++){
                        // Nếu đếm != 0 tức là kí tự này chưa được in ra
                        if(cnt[c[i]] != 0){
                            printf("%c %d\n", c[i], cnt[c[i]]);
                            // Sau khi in xong, gán bằng 0 để các lần gặp kí tự này về sau không bị in trùng
                            cnt[c[i]] = 0;
                        }
                    }                   
                } 
```
