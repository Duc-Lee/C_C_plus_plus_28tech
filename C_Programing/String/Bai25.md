## Bài 1. Tổng 2 số nguyên lớn

Tính tổng 2 số nguyên lớn, mỗi số có không quá 1000 kí tự

**Input**

Dòng đầu tiên là số lượng test case T (1 ≤ T ≤ 100).

Mỗi test case gồm 2 dòng, mỗi dòng là một số nguyên dương có không quá 1000 số.

**Output**

In ra tổng của 2 số nguyên trên 1 dòng.

**Ví dụ**

| Input | Output |
| --- | --- |
| 1<br><br>812317349123232323232323232323232323232318247124<br><br>1231623712333333333333333333333333331231 | <br><br><br><br>812317349123244639469446565656565656565651578355 |

**Code**
```cpp
                #include <stdio.h>
                #include <stdlib.h>
                #include <string.h>
                #include <ctype.h>

                // hàm đảo ngược 
                void reverse(int a[], int n){
                    int l = 0, r = n - 1;
                    while(l<r){
                        int tmp = a[l];
                        a[l] = a[r];
                        a[r] = tmp;
                        ++l;
                        --r;
                    }
                }
                // quy định la a lon hon b
                void add(char a[],char b[]){
                    int n1 = strlen(a);
                    int n2 = strlen(b);
                    int n = 0;
                    // lưu ý cùng lắm z tăng thêm 1 đơn vị
                    int x[n1], y[n2], z[n1+1];
                    for(int i =0;i<n1;i++){
                        // chuyển giá trị kí tự sang số
                        x[i] = a[i] - '0';
                    }
                    for(int i = 0;i<n2;i++){
                        y[i] = b[i] - '0';
                    }
                    // đảo ngược lại 2 xâu
                    // phai dao nguoc lai vi co the 2 xau khong bang nhau
                    // do cach cong la tu duoi di len
                    // nen phai dao de dam bao ket qua dung
                    reverse(a, n1);
                    reverse(b, n2);
                    for(int i = n2;i<n1;i++){
                        // bù 0 vo 
                        // vi du nhu a = 99, b = 8
                        // bu b de duoc 08
                        y[i] = 0;
                    }
                    int nho = 0;
                    for(int i = 0;i<n1;i++){
                        // nhu phep cong binh thuong
                        int tmp = a[i] + b[i] + nho;
                        // so du don vi và nho
                        z[n++] = tmp%10;
                        nhp = tmp/10;
                    }
                    // neu con nho thi viet len dau nhu truong hop 99 +1 = 100
                    // tinh xong dc 00, nho = 1, viet nho len dc 100
                    if(nho) z[n++] = nho;
                    // duyet nguoc lai
                    for(int i = n - 1;i>=0;i--){
                        printf("%d",z[i]);
                    }
                }
                int main(){
                    int t;
                    scanf("%d",&t);
                    while(t--){
                        char c[1001], d[1001];
                        scanf("%s%s",c,d);
                        if(strlen(c) >= strlen(d)) add(c,d);
                        else add(d,c);
                        printf("\n");
                    }
                }
```