**Bài 4. Kiểm tra số nguyên tố 2.**

**Input**

Dòng đầu tiên là số lượng test case T. (1≤T≤1000).

Mỗi test case là một số nguyên n (0≤n≤10^6).

**Output**

In ra kết quả mỗi test case trên một dòng. In YES nếu n là số nguyên tố, ngược lại in NO.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 4 | |
| 2 | YES |
| 3 | YES |
| 20 | NO |
| 188 | NO |

**Code**
```cpp
            #include <stdio.h>
            #include <math.h>

            int nt(int n){
                // la so nguyen to khi chia het cho 1 va chinh no 
                for(int i = 2;i<=sqrt(n);i++){
                    // neu n chia het cho i thi khong phai so nguyen to 
                    if(n%i==0){
                        return 0;
                    }
                }
                // ko chia het cho bat ki so nao tu 2 den can n thi la so nguyen to 
                return n>1;
            }

            int main(){
                int t;
                scanf("%d",&t);
                while(t--){
                    int n;
                    scanf("%d",&n);
                    if(nt(n)){
                        printf("YES\n");
                    }else{
                        printf("NO\n");
                    }
                }
            }
```
- Cách 2 : Dùng sàng số nguyên tố
```cpp
            #include <stdio.h>
            #include <math.h>

            int prime[1000001];
            // sang so nguyen to 
            void sieve(){
                // coi tat ca la so nguyen to 
                for(int i = 0; i <= 1000000;i++){
                    prime[i] = 1;
                }
                prime[0] = prime[1] = 0;
                // loc boi so cua so nguyen to i 
                for(int i = 2;i <= sqrt(1000000);i++){
                    // neu la so nguyen to 
                    if(prime[i]){
                        // loai bo boi so 
                        for(int j = i*i; j <= 1000000; j += i){
                            prime[j] = 0;
                        }
                    }
                }
            }
            int main(){
                int t;
                scanf("%d",&t);
                while(t--){
                    int n;
                    scanf("%d",&n);
                    if(prime[n]){
                        printf("YES\n");
                    }else{
                        printf("NO\n");
                    }
                }
            }
```