## Bài 31. Số điện thoại

Số điện thoại là một chuỗi có đúng 11 chữ số, trong đó chữ số đầu tiên là 8. Ví dụ: dãy 80011223388 là số điện thoại, nhưng các dãy 70011223388 và 80000011223388 thì không.

Bạn được cung cấp một chuỗi s có độ dài n, bao gồm các chữ số.

Trong một thao tác, bạn có thể xóa bất kỳ ký tự nào khỏi chuỗi s. Ví dụ: có thể lấy các chuỗi 112, 111 hoặc 121 từ chuỗi 1121.

Bạn cần xác định xem có một chuỗi các hoạt động như vậy (có thể là không), sau đó chuỗi s trở thành số điện thoại.

**Input**

Dòng đầu tiên chứa một số nguyên t (1 ≤ t ≤ 100) - số lượng trường hợp kiểm tra.

Dòng đầu tiên của mỗi trường hợp chứa một số nguyên n (1 ≤ n ≤ 100) - độ dài của chuỗi s.

Dòng thứ hai của mỗi trường hợp kiểm tra chứa chuỗi s (| s | = n) bao gồm các chữ số.

**Output**

Đối với mỗi bài kiểm tra in một dòng.
Nếu có một chuỗi các hoạt động, sau đó s trở thành một số điện thoại, in YES.
Nếu không, in NO.

**Ví dụ**

| Input | Output |
| --- | --- |
| 2<br>13<br>7818005553535<br>11<br>31415926535 | <br><br>YES<br><br>NO |

**Code**
```cpp
                    #include <stdio.h>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <ctype.h>

                    int solve(char s[], int n){
                        int idx = -1;
                        for(int i = 0;i<n;i++){
                            // tìm số 8 đầu tiên trong xâu
                            if(s[i] == '8'){
                                idx = i;
                                break;
                            }
                        }
                        // nếu không có số 8 
                        if(idx == -1) return 0;
                        // nếu tìm đc số 8 rồi
                        // từ số 8 đi ít nhất phải có 10 số 
                        if(n-1-idx >= 10) return 1;
                        return 0;
                    }
                    int main(){
                        int t;
                        scanf("%d",&t);
                        while(t--){
                            int n;
                            char s[1000];
                            scanf("%d%s",&n,s);
                            if(solve(s,n)) printf("YES\n");
                            else printf("NO\n");
                        }
                    }
```

---

## Bài 32. Xâu con chẵn

Bạn được cung cấp một chuỗi s = s1s2...sn có độ dài n, chỉ chứa các chữ số 1, 2, ..., 9.

Một chuỗi con s[l..r] của s là một chuỗi liên tiếp bắt đầu từ vị trí l tới vị trí r ở trong chuỗi ban đầu. Một chuỗi con s[l...r] của s ngay cả khi nó là một chuỗi rỗng.
Tìm số lượng các chuỗi con chẵn của s. Lưu ý rằng ngay cả khi một số chuỗi con giống nhau, nhưng có l và r khác nhau, chúng được tính là các chuỗi con khác nhau.

**Input**

Dòng đầu tiên chứa số nguyên n (1 ≤ n ≤ 65000) - độ dài của chuỗi s.

Dòng thứ hai chứa một chuỗi s có độ dài n. Chuỗi s chỉ bao gồm các chữ số 1, 2, ..., 9.

**Output**

In số lượng các phần tử chẵn của s.

**Ví dụ**

| Input | Output |
| --- | --- |
| 4<br>1234 | <br>6 |
| 4<br>2244 | <br>10 |

**Code**
```cpp
                    #include <stdio.h>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <ctype.h>

                    int main(){
                        int n;
                        scanf("%d",&n);
                        char s[n];
                        scanf("%s",s);
                        int res = 0;
                        for(int i =0;i<strlen(s);i++){
                            // kiểm tra số đó có phải chẵn không
                            // nếu một chuỗi con kết thúc tại i mà nó chẵn
                            // thì có i+1 chuỗi con chẵn kết thúc tại i
                            if((c[i]-'0')%2 == 0){
                                res += i+1;
                            }
                        }
                        printf("%d",res);
                    }
```
