**Bài 13.** Ước số nguyên tố nhỏ nhất.( Sử dụng sàng biến đổi).

Cho số tự nhiên N. Nhiệm vụ của bạn là in ra ước số nguyên tố nhỏ nhất của các số từ 1 đến N. Ước số nguyên tố nhỏ nhất của 1 là 1. Ước số nguyên tố nhỏ nhất của các số chẵn là 2. Ước số nguyên tố nhỏ nhất của các số nguyên tố là chính nó.

**Input**

Dòng đầu tiên đưa vào số lượng test T.

Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số N được ghi trên một dòng.

T, N thỏa mãn ràng buộc: 1≤T≤1000; 1≤N≤100000.

**Output:**

Đưa ra kết quả mỗi test theo từng dòng.

**Ví dụ**

| Input: | Output: |
| --- | --- |
| 2<br>6<br>10 | <br>1 2 3 2 5 2<br>1 2 3 2 5 2 7 2 3 2 |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>
                
                // uoc so nho nhat cua 1 la 1
                // uoc so nho nhat cua so nguyen to la chinh no 
                // tim cac uoc so nho nhat 
                int nt(int n){
                    for(int i = 2; i<= sqrt(n);i++){
                        if(n%i == 0)
                            // uoc so nho nhat cua 1 so binh thuong
                            return i;
                    }
                    // neu ko thi deu la chinh no 
                    // do thuoc 2 truong hop kia
                    return n;
                }                

                // neu n = 6 
                // cac so tu 1 den 6 : 1,2,3,4,5,6 
                // uoc so nho nhat : 
                // 1
                // 2
                // 3
                // 2
                // 5
                // 2 
                int main(){
                    int t;
                    scanf("%d",&t);
                    while(t--){
                        int n;
                        scanf("%d",&n);
                        for(int i = 1; i<= n;i++){
                            printf("%d ",nt(i));
                        }
                        printf("\n");
                    }
                }
```


**Code - Sử dụng sàng số nguyên tố**
```cpp
                #include <stdio.h>
                #include <math.h>
                
                int prime[1000001];
                void sieve(){
                    // gan mang voi so i tuong ung 
                    // prime[i] : so tu 1 den n
                    // i la uoc so nho nhat
                    for(int i = 0; i<= 1000000;i++){
                        prime[i] = i;
                    }
                    for(int i = 2; i<= 1000;i++){
                        // neu van bang nhau 
                        if(prime[i] == i){
                            // xet cac boi cua i 
                            // de gan uoc nho nhat
                            for(int j = i*i; j<= 1000000; j+=i){
                                // gan lai so j co uoc la i 
                                if(prime[j]==j){
                                    prime[j] = i;
                                }
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
                        for(int i = 1; i<= n;i++){
                            printf("%d ",prime[i]);
                        }
                        printf("\n");
                    }
                }
```