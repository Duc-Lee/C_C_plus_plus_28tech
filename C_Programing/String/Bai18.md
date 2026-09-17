# Bài 23. Kí tự không lặp

Cho xâu ký tự S. Nhiệm vụ của bạn là in ra tất cả các ký tự không lặp khác nhau trong S.
Ví dụ S ="ABCDEABC" ta nhận được kết quả là "DE".

**Input:**

Dòng đầu tiên đưa vào số lượng bộ test T.

Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một xâu ký tự S được viết trên một dòng.

T, S thỏa mãn ràng buộc: 1 ≤ T ≤ 100; 1 ≤ Length(S) ≤ 10^5.

**Output:**

Đưa ra kết quả mỗi test theo từng dòng. In ra theo thứ tự bảng chữ cái.

**Ví dụ**

| Input | Output |
| --- | --- |
| 2<br>ABCDEAABC<br>ABC | DE<br>ABC |

**Code**
```cpp
                        #include <stdio.h>
                        #include <string.h>
                        #include <stdlib.h>
                        #include <ctype.h>

                        int main(){
                            char s[100];
                            gets(s);
                            int cnt[256] = {0};
                            for(int i = 0;i<strlen(s);i++){
                                cnt[s[i]]++;
                            }
                            // in ra cac ki tu khong lap 
                            // theo thu tu xuat hien 
                            for(int i = 0;i<strlen(s);i++){
                                if(cnt[s[i]] == 1){
                                    printf("%c",s[i]);
                                }
                            }
                        }
```

---

# Bài 24. Tính tổng các số trong xâu

Cho xâu ký tự S bao gồm các ký tự 'a',...,'z' và các chữ số. Nhiệm vụ của bạn là hãy tính tổng các số có mặt trong xâu.

**Input:**

Dòng đầu tiên đưa vào số lượng bộ test T.

Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một xâu ký tự S.

T, S thỏa mãn ràng buộc: 1 ≤ T ≤ 100; 0 ≤ Length(S) ≤ 10^5.

Input đảm bảo đáp án không vượt quá 10^9.

**Output:**

Đưa ra kết quả mỗi test theo từng dòng.

**Ví dụ**

| Input | Output |
| --- | --- |
| 3<br>1abc23<br>1abc2x30yz67<br>123abc | 24<br>100<br>123 |

**Code**
```cpp
                        #include <stdio.h>
                        #include <string.h>
                        #include <stdlib.h>
                        #include <ctype.h>

                        int main(){
                            int t;
                            scanf("%d",&t);
                            getchar(); // Xóa kí tự \n bị thừa sau scanf
                            while(t--){
                                char s[100];
                                gets(s);
                                // khoi tao bien dem va bien tong
                                long long res = 0, sum = 0;
                                int len = strlen(s);
                                for(int i = 0; i < len; i++){
                                    if(isdigit(s[i])){ 
                                        // tăng hàng chục lên 
                                        res = res * 10 + s[i] - '0';
                                    }else{
                                        sum += res;
                                        res = 0;
                                    }
                                    // Hoặc cũng có thể 
                                    /*
                                    while(isdigit(s[i])){
                                        res = res * 10 + s[i] - '0';
                                        ++i;
                                    }
                                    sum += res;
                                    */
                                }
                                // Nếu kí tự cuối là số 
                                // theo trên thì chỉ cập sum đến n - 2 thôi 
                                if(len > 0 && isdigit(s[len-1])) sum += res;
                                printf("%lld\n",sum);
                            }
                        }
```

---

# Bài 25. Số lớn nhất trong xâu

Cho xâu ký tự S bao gồm các ký tự 'a',...,'z' và các chữ số. Nhiệm vụ của bạn là hãy tìm số lớn nhất có mặt trong xâu.

**Input:**

Dòng đầu tiên đưa vào số lượng bộ test T.

Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một xâu ký tự S.

T, S thỏa mãn ràng buộc: 1 ≤ T ≤ 100; 0 ≤ Length(S) ≤ 10^5.

Input đảm bảo đáp số không vượt quá 10^9.

**Output:**

Đưa ra kết quả mỗi test theo từng dòng.

**Ví dụ**

| Input | Output |
| --- | --- |
| 3<br>100klh564abc365bg<br>abvhd9sdnkjdfs<br>abchsd0sdhs | 564<br>9<br>0 |

**Code**
```cpp
                    #include <stdio.h>
                    #include <string.h>
                    #include <ctype.h>
                    #include <stdlib.h>

                    int max(int a, int b){
                        return a < b ? b : a;
                    }
                    int main(){
                        int t;
                        scanf("%d",&t);
                        getchar();
                        while(t--){
                            char s[100];
                            gets(s);
                            int res = 0;
                            int cnt = 0; // biến kỉ lục 
                            for(int i =0 ;i<strlen(s);i++){
                                if(isdigit(s[i])){
                                    res = res * 10 + s[i] - '0';
                                }
                                if(res > cnt) cnt = res;   
                            }
                            printf("%d",cnt);
                        }
                    }

```