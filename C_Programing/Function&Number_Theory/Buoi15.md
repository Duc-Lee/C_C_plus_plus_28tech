**Bài 2. Phân tích 2. (Sử dụng sàng số nguyên tố biến đổi).**

Hãy phân tích một số nguyên dương thành tích các thừa số nguyên tố.

**Input**

Dòng đầu tiên ghi số bộ test.

Mỗi bộ test viết trên một dòng số nguyên dương n không quá 5 chữ số.

**Output**

Mỗi bộ test viết ra thứ tự bộ test, sau đó lần lượt là các số nguyên tố khác nhau có trong tích, với mỗi số viết thêm số lượng số đó. Xem ví dụ để hiểu rõ hơn về cách viết kết quả.

**Ví dụ**

**Input:**
```text
3
60
128
10000
```

**Output:**
```text
#TC1: 2(2) 3(1) 5(1)
#TC2: 2(7)
#TC3: 2(4) 5(4)
```

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>
                
                // thuat toan sang so nguyen to 
                int prime[100001];
                void sieve(){
                    // gan cho cac so tuong uong voi chinh no
                    // coi nhu day la uoc so nho nhat cua no
                    for(int i = 0;i<= 100000 ;i++){
                        prime[i] = i;
                    }
                    for(int i = 2; i<= sqrt(100000);i++){
                        // neu so co uoc chinh no
                        // check lai xem no co uoc nho hon khong
                        if(prime[i] == i){
                            // tim boi cua i
                            for(int j = i*i; j <= 100000; j+= i){
                                // cac so co uoc chinh no 
                                // ma j cung la boi cua i
                                // nen i chinh la uoc cua j
                                if(prime[j] == j){
                                    prime[j] = i;
                                }
                            }
                        }
                    }
                }

                void pt(int n){
                    // neu n khac 1
                    while( n!= 1){
                        // khoi tao bien dem 
                        int cnt = 0;
                        // thua so be nhat hien tai cua n
                        int tmp = prime[n];
                        // khi n van con uoc cua so nguyen to
                        while(n%tmp == 0){
                            ++cnt; // tang bien dem
                            // de xem n con la boi cua tmp ko
                            n /= tmp;
                        } 
                        printf("%d(%d) ",prime[n],cnt);
                    }
                }
                int main(){
                    int t;
                    scanf("%d",&t);
                    while(t--){
                        int n;
                        scanf("%d",&n);
                        printf("#TC%d:",t);
                        pt(n);
                        printf("\n");
                    }
                    return 0;
                }
```