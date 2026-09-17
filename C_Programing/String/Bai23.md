## Bài 35. Số La Mã

Trước khi xuất hiện chữ số Ả Rập - là các chữ số từ 0 đến 9 mà chúng ta đang sử dụng rộng rãi ngày nay - trong thời cổ đại và trung đại người ta sử dụng số La Mã. Số La Mã gồm 7 ký tự tương ứng với các số Ả Rập như sau:

| Kí tự | Giá trị |
| --- | --- |
| I | 1 (một) |
| V | 5 (năm) |
| X | 10 (mười) |
| L | 50 (năm mươi) |
| C | 100 (một trăm) |
| D | 500 (năm trăm) |
| M | 1000 (một ngàn) |

Người ta quy định các chữ số I, X, C, M không được lặp lại quá ba lần liên tiếp; các chữ số V, L, D không được lặp lại quá một lần liên tiếp. Chính vì thế mà có 6 nhóm chữ số đặc biệt được nêu ra trong bảng sau:

| Kí tự | Giá trị |
| --- | --- |
| IV | 4 |
| IX | 9 |
| XL | 40 |
| XC | 90 |
| CD | 400 |
| CM | 900 |

Quy tắc viết: ký tự lớn viết trước, ký tự nhỏ viết sau tương tự như hàng trăm, hàng chục, hàng đơn vị trong số Ả rập. Với các ký tự trên, số La Mã có thể biểu diễn các con số từ 1 đến 3999.

Ví dụ: III = 3, VIII = 8, XIX = 19, XXXII = 32, XLV = 45, MMMCMXCIX = 3999.

**Input**

Dòng đầu tiên là số lượng test case T (1 ≤ T ≤ 100).

Mỗi test case là một số La Mã

**Output**

In ra dạng thập phân của số La Mã

**Ví dụ**

| Input | Output |
| --- | --- |
| 2<br><br>III<br><br>MMMCMXCIX | <br><br>3<br><br>3999 |

**Code**
```cpp
                #include <stdio.h>
                #include <string.h>
                #include <stdlib.h>
                #include <ctype.h>
                // khoi tao mang gia cua moi ki tu 
                int val[] = {1, 5, 10, 50, 100, 500, 1000};
                // khoi tao mang chu la ma
                char s[] = "IVXLCDM";
                // hàm tìm kiếm
                int findpos(char c){
                    for(int i = 0;i<7;i++){
                        // nếu kí tự có trong hàm chữ la mã
                        if(s[i] == c) return i;
                    }
                }
                int solve(char c[]){
                    int n = strlen(c);
                    // ánh xạ kí tự sang giá trị tương ứng
                    int res = val[findpos[c[n-1]]];
                    // duyệt ngược về vì tính 1 giá trị la mã sẽ ngược về
                    for(int i = n - 1;i>0;i--){
                        int pos1 = findpos[c[i]];
                        int pos2 = findpos[c[i-1]];
                        if(val[pos1] <= val[pos2]){
                            res += val[pos2];
                        }else{
                            res -= val[pos2];
                        }
                    }
                    return res;
                }
                int main(){
                    int t;
                    scanf("%d",&t);
                    while(t--){
                        char c[1000];
                        scanf("%d",c);
                        printf("%d\n",solve(c));
                    }
                }

```