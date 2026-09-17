**Bài 7. Cặp số nguyên tố.**

Cho số nguyên dương chẵn N>2. Hãy liệt kê các cặp số nguyên tố p, q có tổng đúng bằng N. Ví dụ N = 6 ta có 1 cặp số nguyên tố là 3 + 3 = 6.

**Input**

Dòng đầu tiên đưa vào số lượng bộ test T.

Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số chẵn N.

T, N thỏa mãn ràng buộc : 1≤T≤100; 4≤N≤10000.

**Output**

Đưa ra kết quả mỗi test theo từng dòng.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2 | |
| 4 | 2 2 |
| 6 | 3 3 |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>

                int prime[1000001];
                vói sieve(){
                    // coi tat ca la so nguyen to 
                    for(int i = 0;i<=1000000;i++){
                        prime[i] = 1;
                    }
                    prime[0] = prime[1] = 0;
                    // tim boi cua cac so 
                    for(int i = 2;i <= 1000;i++){
                        if(prime[i]){
                            // loai bo cac boi cua i
                            for(int j = i*i; j <= 1000000;j += i){
                                prime[j] = 0;
                            }
                        }
                    }
                }

                int main(){
                    int t;
                    scanf("%d",&t);
                    sieve();
                    while(t--){
                        int n;
                        scanf("%d",&n);
                        // n = a + b, a va b deu la so nguyen to
                        // neu a la so nguyen to be hon b 
                        // duyet n/2 phan tu 
                        // tim a thi se co so doi la b = n - a
                        for(int i = 2; i <= n/2 ;i++){
                            // 
                            if(prime[i] && prime[n-i]){
                                printf("%d %d",i, n-i);
                            }
                        }
                    }
                }
```