## Bài 10. Số chia hết cho 25

Nhập vào một số nguyên dương n (1<=n<=10^1000). Xác định xem n có chia hết cho 25 hay không?

**Input**

Dòng đầu tiên là số bộ test T (1<=T<=100).

Mỗi bộ test bao gồm một dòng chứa số nguyên dương cần kiểm tra.

**Output**

In 1 nếu n chia hết cho 25, ngược lại in 0. 

**Ví dụ**

| Input | Output |
|---|---|
| 2<br><br>18<br><br>18283128381238182812481248182480912481284812412841824875 | <br><br>NO<br><br>YES |

**Code**
```cpp
                    #include <stdio.h>
                    #include <string.h>
                    #include <ctype.h>
                    #include <stdlib.h>
                    
                    int check(char c[]){
                        // nếu th chỉ có 1 chứ số
                        if(strlen(c) == 1) return 0;
                        // lấy 2 số cuối 
                        int tmp = (c[strlen(c)-2]-'0') * 10 + (c[strlen(c)-1]-'0');
                        // kiểm tra 2 số cuối đó có chia hết cho 25 không
                        if(tmp % 25 == 0 ) return 1;
                        else return 0;
                    }
                    int main(){
                        int t;
                        scanf("%d",&t);
                        while(t--){
                            char c[1001];
                            scanf("%s",c);
                            if(check(c)) printf("1\n");
                            else printf("0\n");
                        }
                        return 0;
                    }
```

## Bài 11. Số chia hết cho 8

Nhập vào một số nguyên dương n (1<=n<=10^1000). Xác định xem n có chia hết cho 8 hay không?

**Input**

Dòng đầu tiên là số bộ test T (1<=T<=100).

Mỗi bộ test bao gồm một dòng chứa số nguyên dương cần kiểm tra.

**Output**

In YES nếu n chia hết cho 8, ngược lại in NO.

**Ví dụ**

| Input | Output |
|---|---|
| 2<br><br>16<br><br>12381289471245812581251275129581258128512851825182541257800 | <br><br>YES<br><br>YES |

**Code**
```cpp
                        #include <string.h>
                        #include <stdio.h>
                        #include <stdlib.h>
                        #include <ctype.h>
                        
                        int check(char c[]){
                            // nếu th chỉ có 1 hoặc 2 chữ số 
                            if(strlen(c) == 1){
                                if((c[0]-'0') % 8 == 0) return 1;
                                else return 0;
                            }
                            // nếu có 2 chữ số 
                            else if(strlen(c) == 2){
                                int tmp = (c[0]-'0') * 10 + (c[1]-'0');
                                if(tmp % 8 == 0) return 1;
                                else return 0;
                            }
                            // nếu từ 3 số trở lên 
                            // số chia hết cho 8 là số có 3 chữ số cuối cùng chia hết cho 8
                            int tmp = (c[strlen(c)-3] - '0')*100 + (c[strlen(c)-2] - '0')*10 + (c[strlen(c)-1] - '0');
                            if(tmp % 8 == 0) return 1;
                            else return 0;
                        }

                        int main(){
                            int t;
                            scanf("%d",&t);
                            while(t--){
                                char c[1001];
                                scanf("%s",c);
                                if(check(c)) printf("YES\n");
                                else printf("NO\n");
                            }
                            return 0;
                        }
```

## Bài 12. Số chia hết cho 2, 3, và 5

Kiểm tra xem một số nguyên dương có chia hết cho cả 2 3 và 5 hay không

**Input**

Dòng đầu tiên là số lượng test case T (1≤T≤100).

Mỗi test case gồm 1 dòng, mỗi dòng là một số nguyên dương có không quá 1000 số.

**Output**

In YES nếu số đã cho thỏa mãn yêu cầu đầu bài, ngược lại in NO

**Ví dụ**

| Input | Output |
|---|---|
| 2<br><br>12944471241828581825818235818583885<br><br>263730746028908374890 | <br><br>NO<br><br>YES |

**Code**
```cpp
                    #include <stdio.h>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <ctype.h>
                    
                    int check(char c[]){
                        // số chia hết cho 2,3 và 5 là số có tổng chữ số chia hết cho 3, số tận cùng phải là 0
                        // kiểm tra số tận cùng có phải 0 ko ? 
                        if(c[strlen(c)-1] != '0'){
                            return 0;
                        }
                        // tính tổng các chữ số 
                        int sum = 0;
                        for(int i =0;i<strlen(c);i++){
                            sum += c[i] -'0';
                        }
                        if(sum % 3 == 0) return 1;
                        else return 0;
                    }
                    int main(){
                        int t;
                        scanf("%d",&t);
                        while(t--){
                            char c[1001];
                            scanf("%s",c);
                            if(check(c)) printf("YES\n");
                            else printf("NO\n");
                        }
                        return 0;
                    }
```
                    