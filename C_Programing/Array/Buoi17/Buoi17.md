    # Bài tập Mảng 1 Chiều - Buổi 17

## Bài 28. Dãy ưu thế

Cho dãy A[] chỉ bao gồm các số nguyên dương không quá $10^5$ nhưng không biết trước số phần tử của dãy. Người ta gọi dãy A[] là dãy ưu thế nếu thỏa mãn 1 trong 2 điều kiện sau đây:

- Dãy gọi là ưu thế chẵn nếu số phần tử của dãy là chẵn và số lượng số chẵn trong dãy nhiều hơn số lượng số lẻ.
- Dãy gọi là ưu thế lẻ nếu số phần tử của dãy là lẻ và số lượng số lẻ trong dãy nhiều hơn số lượng số chẵn.

Hãy kiểm tra xem dãy A[] có phải là dãy ưu thế hay không.

### Input
- Dòng đầu ghi số bộ test, không quá 10.
- Mỗi bộ test là một dãy các số nguyên dương (không quá $10^4$) và có không quá 200 số, các số cách nhau 1 khoảng trống, không biết trước số lượng phần tử.

### Output
- Nếu dãy A[] thỏa mãn là dãy ưu thế thì in ra YES, nếu không in ra NO.

### Ví dụ
| Input | Output |
| :--- | :--- |
| 2<br>11 22 33 44 55 66 77<br>23 34 45 56 67 78 89 90 121 131 141 151 161 171 | YES<br>NO |

### Code
```cpp
                int main(){
                    int t;
                    scanf("%d",&t);
                    while(t--){
                        // đếm số lượng phần tử mảng 
                        int n = 0;
                        int c =0, l = 0;
                        char kitu = " ";
                        // Dừng cho đến khi enter
                        while( kitu != "\n"){
                            int x;
                            scanf("%d",&x);
                            // tăng số lượng mảng 
                            ++n;
                            // đếm số lượng phần tử nhập có chẵn không 
                            if (x%2 == 0) c++;
                            // không thì lẻ
                            else l++;
                            // gán lại hàm getchar để xem kí tự cuối là gì 
                            kitu = getchar();
                        }
                        if (n%2 == 0 && c > l || n%2==1 && l>c ){
                            printf("YES");
                        }else{
                            printf("NO");
                        }
                    }
                }
```