**Bài 3. Đếm thừa số nguyên tố.**

Hãy đếm số lượng thừa số nguyên tố khác nhau trong phân tích thừa số nguyên tố của 1 số nguyên dương n.

**Input**

Dòng đầu tiên là số lượng test case T(1≤n≤100).

T dòng tiếp theo mỗi dòng là một số nguyên dương n (1≤n≤10^9).

**Output**

Số lượng thừa số nguyên tố khác nhau của n.

**Ví dụ**

**Input:**
```text
3
60
```

**Output:**
```text
3
```

**Code**
```cpp
                    #include <stdio.h>
                    #include <math.h>
                    
                    void pt(int n){
                        // dem so luong thua so nguyen to khac nhau
                        int cnt = 0;
                        for(int i = 2; i <= sqrt(n);i++){
                            // neu i la uoc cua n 
                            if(n%i == 0){
                                // chi tinh 1 lan, ko tinh lap lai
                                ++cnt;
                                // dieu kien dung khi n van chia het cho i
                                while(n%i == 0){
                                    n /= i;
                                }
                            }
                        }
                        printf("%d",cnt);
                    }    

                    int main(){
                        int t;
                        scanf("%d",&t);
                        while(t--){
                            int n;
                            scanf("%d",&n);
                            pt(n);
                        }
                        return 0;
                    }
```
