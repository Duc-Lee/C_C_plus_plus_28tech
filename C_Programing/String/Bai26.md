## Bài 2. Hiệu 2 số nguyên lớn

Tính hiệu 2 số nguyên lớn, mỗi số có không quá 1000 kí tự, ta lấy trị tuyệt đối của kết quả.

**Input**

Dòng đầu tiên là số lượng test case T (1 ≤ T ≤ 100).

Mỗi test case gồm 2 dòng, mỗi dòng là một số nguyên dương có không quá 1000 số.

**Output**

In ra hiệu của 2 số nguyên trên 1 dòng, chú ý lấy trị tuyệt đối của kết quả.

**Ví dụ**

| Input | Output |
| --- | --- |
| 3<br><br>192389123919239123912912931923912931923<br>81239123912931290491284912498<br><br>88888888888888888888888888888888888888888888888888888888<br>88888888888888888888888888888888888888888888888888888886<br><br>912939123912931923912391283473572347237421347124124102789541906274512<br>912939123912931923912391283473572347237421347124124102789541906274512 | <br><br>192389123837999999999981641432628019425<br><br><br>2<br><br><br>0 |

**Code**
```cpp
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <string.h>
                    #include <ctype.h>
                    // ham dao nguoc
                    void reverse(char a[], int n){
                        int l = 0, r = n-1;
                        while(l<r){
                            char tmp = a[l];
                            a[l] = a[r];
                            a[r] = tmp;
                            ++l;
                            --r;
                        }
                    }
                    // quy dinh mang a > b
                    void sub(char a[], char b[]){
                        int n1= strlen(a);
                        int n2 = strlen(b);
                        int n = 0;
                        int x[n1],y[n2],z[n1+1];
                        // chuyển kí tự về số 
                        for(int i = 0;i<n1;i++){
                            x[i] = a[i]- '0';
                        }
                        for(int i = 0;i<n2;i++){
                            y[i] = b[i]- '0';
                        }
                        // phần tử còn lại cho số 0;
                        for(int i = n2;i<n1;i++){
                            y[i] = 0;
                        }
                        // đảo ngược 2 xâu 
                        reverse(a,n1);
                        reverse(b,n2);
                        int muon = 0;
                        for(int i = 0;i<n1;i++){
                            // tinh phep tru 
                            int tmp = x[i] - y[i] - muon;
                            // nếu x[i] < y[i]
                            if(tmp < 0){
                                muon = 1;
                                // x[i] + 10 - y[i] - muon
                                z[n++] = 10 + tmp;
                            }else{
                                // thi kết quả đúng, ko cần phải mượn
                                z[n++] = tmp;
                                muon = 0;
                            }
                        }
                        // bỏ số 0 vô nghĩa ở đâu khi in kết quả
                        // hàm z ví dụ la {3,2,1,0,0}
                        // duyệt ngược -> in 123
                        int ok = 0;
                        for(int i = n - 1;i>=0;i--){
                            // kiểm tra z[i] != 0
                            if(ok == 0 && z[i] != 0){
                                ok = 1;
                            }
                            // nếu ok = 1 thì in ra số
                            if(ok) printf("%d",z[i]);
                        }
                        // ví dụ ket qua la 000 -> in 0
                        if(ok == 0) printf("0");
                        printf("\n");
                    }
                    int main(){
                        int t;
                        scanf("%d",&t);
                        while(t--){
                            char c[1001], d[1001];
                            scanf("%s%s",c,d);
                            // kiểm tra nếu xâu c > d hoặc cùng độ dài thì số hàm c phải > d
                            if(strlen(c) > strlen(d) || (strlen(c) == strlen(d) && strcmp(c,d) > 0)){
                                sub(c,d);
                            }else{
                                sub(d,c);
                            }
                        }
                        return 0;
                    }

```