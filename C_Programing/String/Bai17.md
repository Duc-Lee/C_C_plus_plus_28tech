# Bài 21. Xâu con

Cho 2 chuỗi a và b, nếu chuỗi a xuất hiện trong chuỗi b in ra YES, ngược lại in NO.

**Input**
2 xâu a và b trên 2 dòng. 2 xâu a và b chỉ chứa kí tự thường.

**Output**
Kết quả của bài toán.

**Ví dụ**

| Input | Output |
| --- | --- |
| abcde<br>azhuywfjalzabcde | YES |


**Code**
```cpp
                        #include <stdio.h>
                        #include <string.h>
                        #include <stdlib.h>
                        #include <ctype.h>

                        // Xây dựng hàm strstr()
                        // Tuy nhiên hàm này đã có sẵn trong thư viện string.h
                        char *strstr1(char *a,char *b){
                            int len1 = strlen(a);
                            int len2 = strlen(b);
                            // len1 - len2 là độ dài tối đa mà chuỗi b có thể chứa chuỗi a 
                            for(int i = 0; i <= len1 - len2; i++){
                                if(strncmp(&a[i],b,len2) == 0){
                                    return &a[i];
                                }
                            }
                            return NULL;
                        }

                        int main(){
                            char a[100],b[100];
                            gets(a);
                            gets(b);
                            // Kiểm tra a có trong xâu b hay không 
                            // Nếu không xuất hiện trong xâu b 
                            // thì trả về con trỏ NULL 
                            if(strstr(a,b) != NULL){
                                printf("YES");
                            }else{
                                printf("NO");
                            }
                        }
```

---

# Bài 22. Xâu đối xứng 3

Kiểm tra xem có thể hoán đổi vị trí các kí tự trong một chuỗi cho trước để tạo thành chuỗi đối xứng hay không. In ra YES nếu có thể, ngược lại in ra NO.

**Input**
Dòng đầu tiên là số lượng test case t.
T dòng tiếp theo mỗi dòng chứa một xâu.

**Output**
In kết quả trên mỗi dòng.

**Ví dụ**

| Input | Output |
| --- | --- |
| 2<br>abcabcabcabcabcabczzz<br>ttyz$$$$*************ywai4o43p4 | YES<br>NO |

**Code**
```cpp
                            #include <stdio.h>
                            #include <string.h>
                            #include <stdlib.h>
                            #include <ctype.h>

                            int main(){
                                int t;
                                scanf("%d",&t);
                                getchar();
                                while(t--){
                                    char s[1000];
                                    gets(s);
                                    // Khởi tạo mảng đếm tần suất 
                                    int cnt[256] = {0};
                                    for(int i = 0 ;i<strlen(c);i++){
                                        // kí tự sẽ tự chuyển về mã ASCII
                                        cnt[s[i]]++;
                                    }
                                    // khoi tao bien dem so ki tu le
                                    int res = 0;
                                    for(int i =0;i<256;i++){
                                        // neu tan suat la le 
                                        if(cnt[i] % 2 == 1) ++res;
                                    }
                                    // Neu so ki tu le nho hon hoac bang 1 
                                    // thi co the tao thanh chuoi doi xung
                                    // nguoc lai thi khong the
                                    // Bản chất là chia đều các kí tự 
                                    // Nếu chẵn hết thì chia đôi đều ra 2 bên là được
                                    // Nếu có 1 lẻ thì cho ra giữa, còn lại chia đôi ra 2 bên là được
                                    // Nếu có >2 lẻ thì không thể chia đều ra 2 bên được
                                    if(res <= 1) printf("YES\n");
                                    else printf("NO\n");
                                }
                            }
```