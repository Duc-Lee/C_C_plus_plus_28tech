# Bài 26. Tổng 2 đa thức

Tính tổng của 2 đa thức.

**Input:**
Dòng đầu tiên là số lượng bộ test T (1 ≤ T ≤ 100).

Mỗi bộ test gồm 2 dòng, dòng đầu chứa đa thức thứ 1.

Dòng thứ 2 chứa đa thức thứ 2.

Chú ý đa thức được liệt kê cả mũ 0. Bậc của 2 đa thức không vượt quá 10000.

**Output:**
In ra kết quả mỗi test case trên 1 dòng.

**Ví dụ:**

| Input | Output |
| --- | --- |
| 1<br><br>2*x^5 + 3*x^2 + 5*x^0<br><br>4*x^5 + 2*x^1 + 10*x^0 | #Test 1: 6*x^5 + 3*x^2 + 2*x^1 + 15*x^0 |

**Code**
```cpp
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <string.h>
                    #include <ctype.h>

                    // bac mu khong vuot qua 10000
                    int dt[10000], cnt = 0;

                    void solve(char c[]){
                        for(int i =0 ;i < strlen(c);i++){
                            if(isdigit(c[i])){
                                int heso = 0;
                                // Tinh đến khi gặp * trong heso *x^ mu
                                // gặp * thì dừng
                                while(c[i] != '*'){
                                    heso = heso * 10 + c[i] - '0';
                                }
                                // nhảy cóc biến i lên thêm 3 đơn vị 
                                // do *x^ : đây là khoảng cách giữa hệ số và và mũ
                                i += 3;
                                // gặp dấu cách thì dừng 
                                while(c[i] != " "){
                                    mu = mu * 10 + c[i] - '0';
                                }
                                // tinh tong he so 
                                dt[mu] += heso;
                            }
                        }
                    }

                    int main(){
                        int t;
                        scanf("%d",&t);
                        getchar();
                        for(int i = 1;i<=t;i++){
                            char c1[100],c2[100];
                            gets(c1);
                            gets(c2);
                            // reset mảng dt[] về lại ban đầu
                            memset(dt,0,sizeof(dt));
                            int cnt = 0;
                            // cộng hệ số
                            solve(c1);
                            solve(c2);
                            for(int i = 10000; i>=0;i--){
                                // đếm xem có bao nhiêu hệ số 
                                if(dt[i]) ++cnt;
                            }
                            printf("#Test %d: ",i);
                            for(int i = 10000;i>=0;i--){
                                // nếu hệ so khác 0
                                if(dt[i] != 0){
                                    printf("%d*x^%d",dt[i],i);
                                    // giảm biến đếm đi 
                                    --cnt;
                                    // nếu hệ số vẫn còn thì 
                                    if(cnt != 0){
                                        printf(" + ");
                                    }
                                }
                            }
                            printf("\n");
                        }
                    }
```