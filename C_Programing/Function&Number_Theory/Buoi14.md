**Bài 1.** Phân tích 1

Hãy phân tích một số nguyên dương n thành thừa số nguyên tố

**Input**

Số nguyên dương n (1≤n≤10^9)

**Output**

Cách phân tích thừa số nguyên tố của n. Bạn hãy thử cài đặt với 5 cách in thừa số nguyên tố sau.

Ví dụ cách phân tích 1.

| Input: | Output: |
| --- | --- |
| 28 | 2 2 7 |

**Code**
```cpp
            #include <stdio.h>
            #include <math.h>

            void pt(int n){
                // duyet tu 2 den can n
                for(int i = 2;i <= sqrt(n);i++){
                    // khi n van con chia het cho i 
                    // tuc la van con uoc cua i 
                    while(n%i == 0){
                        printf("%d ",i);
                        n /= i;
                    }
                }
                // neu n khac 1 sau khi xong vong for 
                // tuc la n la so nguyen to 
                // thi chi co moi chinh no thoi 
                if( n != 1){
                    printf("%d ",n);
                }
            }
            int main(){
                int n;
                scanf("%d",&n);
                pt(n);
                return 0;
            }               
```


Ví dụ cách phân tích 2.(Mỗi thừa số nguyên tố chỉ liệt kê 1 lần).

| Input: | Output: |
| --- | --- |
| 28 | 2 7 |

**Code**
```cpp
            #include <stdio.h>
            #include <math.h>
            
            void pt(int n){
                for(int i = 2; i <= sqrt(n);i++){
                    // neu n chia cho i 
                    if(n % i == 0){
                        // in ra uoc so dau tien 
                        printf("%d ",i);
                        // tim uoc so khac 
                        while(n%i == 0){
                             n /= i;
                        }
                    }
                }
                if(n != 1){
                    printf("%d ",n);
                }
            }
            int main(){
                int n;
                scanf("%d",&n);
                pt(n);
                return 0;
            }
```

Cách phân tích 3. Thừa số nguyên tố được liệt kê kèm theo số mũ.

| Input: | Output: |
| --- | --- |
| 28 | 2(2) 7(1) |

**Code**
```cpp
            #include <stdio.h>
            #include <math.h>

            void pt(int n){
                for(int i = 2; i<= sqrt(n);i++){
                    if(n%i == 0){
                        int cnt = 0; // khoi tao bien dem mu
                        while(n%i == 0){
                            ++cnt;
                            n /= i;
                        }
                        printf("%d(%d) ",i,cnt);
                    }
                }
                if(n != 1){
                    printf("%d(1) ",n);
                }           
            }   
            int main(){
                int n;
                scanf("%d",&n);
                pt(n);
                return 0;
            }
```

Cách phân tích 4. Thêm dấu x vào giữa các thừa số nguyên tố

| Input: | Output: |
| --- | --- |
| 8<br>28 | 2x2x2<br>2x2x7 |

**Code**
```cpp
            #include <stdio.h>
            #include <math.h>

            void pt(int n){
                for(int i = 2; i <= sqrt(n);i++){
                    if(n%i == 0){
                        while(n%i == 0){
                            printf("%d",i);
                            n /= i;
                            // de in dau x 
                            // neu n khac 1 thi van con thua so khac nen in 
                            if(n != 1) 
                                printf("x");
                        }
                    }
                } 
                if(n != 1){
                    printf("%d",n);
                }          
            }   
            int main(){
                int n;
                scanf("%d",&n);
                pt(n);
                return 0;
            }
```

Cách phân tích 5.

| Input: | Output: |
| --- | --- |
| 60 | 60 = 2^2 * 3^1 * 5^1 |

**Code**
```cpp
            #include <stdio.h>
            #include <math.h>

            void pt(int n){
                printf("%d = ",n);
                for(int i = 2; i<= sqrt(n);i++){
                    if(n%i == 0){
                        int cnt = 0;
                        while(n%i == 0){
                            ++cnt;
                            n /= i;
                        }
                        // in ra thừa số nguyên tố kèm số mũ
                        printf("%d^%d",i,cnt);
                        // neu n khac 1 thi van con thua so khac nen in 
                        if(n != 1){
                            printf(" * ");
                        }
                    }
                }
                if(n != 1){
                    printf("%d",n);
                }
            }
            int main(){
                int n;
                scanf("%d",&n);
                pt(n);
                return 0;
            }
```