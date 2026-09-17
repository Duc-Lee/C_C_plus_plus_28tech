# Bài 8. Số thuần nguyên tố.

Một số được coi là thuần nguyên tố nếu nó là số nguyên tố, tất cả các chữ số là nguyên tố và tổng chữ số của nó cũng là một số nguyên tố. Bài toán đặt ra là đếm xem trong một đoạn giữa hai số nguyên cho trước có bao nhiêu số thuần nguyên tố.

## Input

Dòng đầu tiên ghi số bộ test. Mỗi bộ test viết trên một dòng hai số nguyên dương tương ứng, cách nhau một khoảng trống. Các số đều không vượt quá 9 chữ số.

## Output

Mỗi bộ test viết ra số lượng các số thuần nguyên tố tương ứng

## Ví dụ

| Input | Output |
| --- | --- |
| 2<br>23 199<br>2345 6789 | <br>1<br>15 |

## Code
```cpp
            #include <stdio.h>
            #include <math.h>

            int prime[1000001];
            void sieve(){
                for(int i = 0; i<= 1000000;i++){
                    prime[i] = 1;
                }
                prime[0] = prime[1] = 0;
                for(int i = 2; i<= 1000;i++){
                    if(prime[i]){
                        for(int j = i*i;j <= 1000000; j += i){
                            prime[j] = 0;
                        }
                    }
                }
            }

            int tach(int n){
                int cnt = 0;
                while(n){
                    int res = n % 10;
                    // neu moi chu cai khong phai so nguyen to
                    if(!prime[res]) return 0;
                    // tinh tong so chu so
                    cnt += res;
                    n /= 10;
                }
                // tong chu so co phai so nguyen to ko
                if(!prime[cnt]) return 0;
                return 1;
            }

            int main(){
                int t;
                scanf("%d",&t);
                sieve();
                while(t--){
                    int a, b;
                    scanf("%d %d",&a,&b);
                    // duyet doan tu a den b
                    int cnt = 0;
                    for(int i = a ; i <= b;i++){
                        if(prime[i] && tach(i)) {
                            cnt++;
                        }
                    }
                    printf("%d\n",cnt);
                }
            }
```