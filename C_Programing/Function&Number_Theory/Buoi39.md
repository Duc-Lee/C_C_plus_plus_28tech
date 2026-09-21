**Bài 27. Chữ số nguyên tố 2**

Liệt kê số lần xuất hiện của chữ số nguyên tố của 1 số theo thứ tự xuất hiện các chữ số.

**Input**

Số nguyên dương n (1 ≤ n ≤ 10^18).

**Output**

Chữ số nguyên tố xuất hiện trong số ban đầu cùng với số lần xuất hiện của nó theo thứ tự xuất hiện.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 722334123232277 | 7 3<br>2 6<br>3 4 |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>

                int rev(int n){
                    int r = 0;
                    while(n != 0){
                        r = r*10 + n%10;
                        n /= 10;
                    }
                    return r;
                }

                // khoi tao mang tan so
                int arr[10] = {0};
                void solve(int n){
                    // dao nguoc 1 so 
                    int rev_val = rev(n);
                    // dem tan suat xuat hien 
                    while( rev_val != 0){
                        int r = rev_val % 10;
                        if(r == 2 || r == 3 || r == 5 || r == 7){
                            arr[r]++;
                        }
                        rev_val /= 10;
                    }
                    // in ket qua theo xuat hien lan luot cac so
                    while(rev_val != 0){
                        int r = rev_val % 10;
                        if(arr[r] != 0){
                            printf("%d %d\n",r,arr[r]);
                            arr[r] = 0;
                        }
                        rev_val /= 10;
                    }
                }
                int main(){
                    int n;
                    scanf("%d", &n);
                    solve(n);
                    return 0;
                }
```

- Xử lí theo String
**Code**
```cpp
                #include <stdio.h>
                #include <math.h>
                #include <string.h>

                void solve(char c[]){
                    int c2= 0, c3= 0, c5 = 0, c7 = 0;
                    int len = strlen(c);
                    for(int i = 0; i< len;i++){
                        if(c[i] == '2') ++c2;
                        else if(c[i] == '3') ++c3;
                        else if(c[i] == '5') ++c5;
                        else if(c[i]== '7') ++c7;
                    }
                    // in ra cac chu so nguyen to theo thu tu xuat hien
                    for(int i = 0 ; i < len; i++){
                        if(c[i] == '2' && c2 != 0 ) {
                            printf("2 %d\n", c2);
                            c2 = 0;
                        }
                        else if(c[i] == '3' && c3 != 0) {
                            printf("3 %d\n", c3);
                            c3 = 0;
                        }
                        else if(c[i] == '5' && c5 != 0) {
                            printf("5 %d\n", c5);
                            c5 = 0;
                        }
                        else if(c[i] == '7' && c7 != 0) {
                            printf("7 %d\n", c7);
                            c7 = 0;
                        }
                    }
                }
                int main(){
                    char c[100];
                    scanf("%s", c);            
                    solve(c);
                    return 0;
                }
```