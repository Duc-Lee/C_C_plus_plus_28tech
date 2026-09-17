## Bài 6. Số đẹp 1

Một số nguyên được coi là chữ số đẹp nếu nó chỉ chứa các chữ số là số nguyên tố và tổng các chữ số của nó có tận cùng là 0.

**Input**

Dòng đầu tiên là số lượng test case T (1 ≤ T ≤ 100).

Mỗi test case gồm 1 dòng, mỗi dòng là một số nguyên dương có không quá 1000 số.

**Output**

In YES nếu số đã cho thỏa mãn yêu cầu đầu bài, ngược lại in NO

**Ví dụ**

| Input | Output |
| --- | --- |
| 3<br>55555555555555555555555555555555555555555555555555<br>235723572357235723572357235723572357235723573<br>2375757575772727272777288727272732737 | <br>YES<br>YES<br>NO |

**Code**
```cpp
                    #include <stdio.h>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <ctype.h>

                    int check(char c[]){
                        int sum = 0;
                        for(int i = 0; i <strlen(c);i++){
                            // chuyển giá trị x sang số
                            int x = c[i] - '0';
                            // kiểm tra xem x có phải số nguyên tố k 
                            if(x!=2 && x!= 3 && x!= 5 && x!= 7){
                                return 0;
                            }
                            sum += x;
                        }
                        // nếu số tận cùng là 0 hay không 
                        if(sum % 10 == 0) return 1;
                        else return 0;
                    }
                    int main() {
                        int t;
                        scanf("%d",&t);
                        while(t--){
                            char c[1001];
                            scanf("%d",c);
                            if(check(c)) printf("YES\n");
                            else printf("NO\n");
                        }
                        return 0;
                    }
```

## Bài 7. Số đẹp 2

Một số nguyên được coi là chữ số đẹp nếu nó chỉ chứa các chữ số là số nguyên tố và là số thuận nghịch

**Input**

Dòng đầu tiên là số lượng test case T (1 ≤ T ≤ 100).

Mỗi test case gồm 1 dòng, mỗi dòng là một số nguyên dương có không quá 1000 số.

**Output**

In YES nếu số đã cho thỏa mãn yêu cầu đầu bài, ngược lại in NO

**Ví dụ**

| Input | Output |
| --- | --- |
| 3<br>55555555555555555555555555555555555555555555555555<br>235723572357235723572357235723572357235723573<br>2375757575772727272777288727272732737 | <br>YES<br>NO<br>NO |

**Code**
```cpp
                    #include <stdio.h>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <ctype.h>

                    int check(char c[]){
                        int l = 0, r = strlen(c) - 1;
                        while(l <= r){
                            int x = c[l] - '0';
                            // nếu không đối xứng
                            if(c[l] != c[r]) return 0;
                            // nếu không phải số nguyên tố 
                            if(x!=2 && x!= 3 && x!= 5 && x!= 7) return 0;
                            ++l;
                            --r;
                        }
                        return 1;
                    }
                    int main() {
                        int t;
                        scanf("%d",&t);
                        while(t--){
                            char c[1001];
                            scanf("%d",c);
                            if(check(c)) printf("YES\n");
                            else printf("NO\n");
                        }
                        return 0;
                    }
```
