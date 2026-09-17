## Bài 3. Tổng chữ số của số nguyên lớn

Tính tổng chữ số của số nguyên lớn

**Input**

Dòng đầu tiên là số lượng test case T (1 ≤ T ≤ 100).

Mỗi test case gồm 1 dòng, mỗi dòng là một số nguyên dương có không quá 1000 số.

**Output**

In ra tổng các chữ số của số nguyên dương.

**Ví dụ**

| Input | Output |
| --- | --- |
| 2<br>8123173491232323232323232323232323232318247124<br>12316237123333333333333333333331231 | <br>143<br>98 |

**Code**
```cpp
                    #include <stdio.h>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <ctype.h>

                    int main() {
                        int t;
                        scanf("%d",&t);
                        while(t--){
                            char c[1001];
                            scanf("%d",c);
                            int sum = 0;
                            for(int i = 0;i<strlen(c);i++){
                                sum += c[i] - '0';
                            }
                            printf("%d\n",sum);
                        }
                        return 0;
                    }
```

## Bài 4. Số nguyên toàn chẵn.

Kiểm tra xem số nguyên đã cho có phải là số thuận nghịch và chứa toàn số chẵn hay không?

**Input**

Dòng đầu tiên là số lượng test case T (1 ≤ T ≤ 100).

Mỗi test case gồm 1 dòng, mỗi dòng là một số nguyên dương có không quá 1000 số.

**Output**

In YES nếu số đã cho thỏa mãn yêu cầu đầu bài, ngược lại in NO

**Ví dụ**

| Input | Output |
| --- | --- |
| 3<br>222222222222222222252222222222222222222222<br>555555555555555555555555555555555555555555<br>28882 | <br>NO<br>NO<br>YES |

**Code**
```cpp
                    #include <stdio.h>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <ctype.h>

                    int check(char c[]){
                        // kiểm tra số thuận nghịch, chứa toàn số chẵn 
                        int l = 0, r = n - 1;
                        while(l <= r){
                            // kiểm tra có bất đối xứng ko 
                            if (c[l] != c[r]) return 0;
                            // nếu c[l] == c[r] rồi, thì xét 1 TH th
                            // kiểm tra số chẵn 
                            if ((c[l]-'0')%2==1){
                                return 0;
                            }
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

