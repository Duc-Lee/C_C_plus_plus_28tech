**Bài 5. Số nguyên tố và chữ số nguyên tố**

Viết chương trình đếm xem trong đoạn [a,b] có bao nhiêu số là số nguyên tố và tất cả các chữ số của nó cũng là số nguyên tố.

**Input**

Dòng đầu ghi số bộ test.

Mỗi bộ test ghi 2 số a, b (1<a<b<10^6).

**Output**

Với mỗi bộ test, ghi ra số lượng số thỏa mãn trên một dòng.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2 | |
| 10 100 | 4 |
| 1234 5678 | 26 |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>
                
                // Sang so nguyen to 
                int prime[1000001];
                void sieve(){
                    // coi tat ca cac so la so nguyen to 
                    for(int i = 0;i<1000000;i++){
                        prime[i] = 1;
                    }
                    prime[0] = prime[1] = 0;
                    // sang so nguyen to 
                    for(int i = 2;i<=sqrt(1000000);i++){
                        if(prime[i]){
                            // loai bo cac boi so cua i 
                            for(int j = i *i; j <= 1000000; j += i){
                                prime[j] = 0;
                            }
                        }
                    }
                }
                // Tach cac chu so ra kiem tra co phai so nguyen to hay khong
                int digitPrime(int n){
                    while(n){
                        int res = n % 10;
                        if (res != 2 && res != 3 && res != 5 && res != 7){
                            return 0;
                        }
                        n /= 10;
                    }
                    return 1;
                }
                int main(){
                    int t;
                    scanf("%d",&t);
                    sieve();
                    while(t--){
                        int l,r;
                        scanf("%d %d",&l,&r);
                        int cnt  = 0; // bien dem
                        for(int i = l; i <= r;i++){
                            if(digitPrime(i) && prime[i]){
                                ++cnt;
                            }
                        }
                        printf("%d\n",cnt);
                    }
                }
```