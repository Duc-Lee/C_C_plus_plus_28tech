**Bài 8. Số hoàn hảo.**

Số hoàn hảo là số có tổng các ước thực sự (Không tính chính nó) bằng chính số đó.

Cho một số nguyên dương n, kiểm tra xem n có phải là số hoàn hảo hay không.

**Input**

Dòng đầu tiên là số lượng test case T(1≤n≤100).

T dòng tiếp theo mỗi dòng là 1 số nguyên dương n (1≤n≤10¹⁸)

**Output**

Mỗi test case in ra trên 1 dòng. YES nếu n là số hoàn hảo, ngược lại in NO.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2<br>28<br>2305843008139952128 | <br>YES<br>YES |

**Code**
```cpp
                    #include <stdio.h>
                    #include <math.h>

                    // tinh tong uoc cua so n 
                    long long sum(long long n){
                        long long res = 0;
                        for(long long i = 1; i<= sqrt(n);i++){
                            // neu i la uoc cua n 
                            if(n % i == 0){
                                // neu i ko phai so chinh phuong 
                                if ( i != n/i) res += i + (n/i);
                                // neu la so chinh phuong 
                                else res += i;
                            }
                        }
                        // tru di n vi de bai chi tinh tong "uoc thuc su" (khong tinh chinh no)
                        return res - n;
                    }

                    int check(long long n){
                        if(n == sum(n)) return 1;
                        else return 0;
                    }

                    int main(){
                        int t;
                        scanf("%d",&t);
                        while(t--){
                            long long n;
                            scanf("%lld",&n);
                            if(check(n)){
                                printf("YES\n");
                            }
                            else{
                                printf("NO\n");
                            }
                        }
                    }
```

**Cách 2: Tối ưu với Định lý Euclid - Euler (Tránh Time Limit Exceeded)**
```cpp
                    #include <stdio.h>
                    #include <math.h>

                    // Kiem tra so nguyen to
                    int isPrime(int n){
                        if(n < 2) return 0;
                        for(int i = 2; i <= sqrt(n); i++){
                            if(n % i == 0) return 0;
                        }
                        return 1;
                    }

                    // khoi tao mang so hoan hao 
                    // do 2^61 la so hoan hao lon nhat nho hon 10^18 nen chi can luu den do 
                    // chi can 10 so la du 
                    long long perfect[10];
                    int cnt = 0;

                    // Sinh ra cac so hoan hao bang dinh ly Euclid - Euler
                    void init(){
                        // tu 2 den 31  y nghia la so mu cua no nho hon 31
                        for(int p = 2; p <= 31; p++){
                            if(isPrime(p)){
                                // Kiem tra xem 2^p - 1 co phai so nguyen to khong
                                // Dung dich bit (1LL << p) de tinh 2^p thay vi dung ham pow de tranh sai so
                                long long mersenne = (1LL << p) - 1; 
                                if(isPrime(mersenne)){
                                    // Neu dung, tao ra so hoan hao la 2^(p-1) * (2^p - 1)
                                    perfect[cnt++] = (1LL << (p - 1)) * mersenne;
                                }
                            }
                        }
                    }

                    int check(long long n){
                        for(int i = 0; i < cnt; i++){
                            if(perfect[i] == n) return 1;
                        }
                        return 0;
                    }

                    int main(){
                        // Goi ham init 1 lan duy nhat truoc khi xu ly test case
                        init(); 
                        int t;
                        scanf("%d", &t);
                        while(t--){
                            long long n;
                            scanf("%lld", &n);
                            if(check(n)){
                                printf("YES\n");
                            } else {
                                printf("NO\n");
                            }
                        }
                        return 0;
                    }
```