**Bài 5. Tính tổng ước của 1 số nguyên dương n.**

**Input**

Dòng đầu tiên là số lượng test case T(1≤n≤100).

T dòng tiếp theo mỗi dòng là 1 số nguyên dương n (1≤n≤10⁹)

**Output**

Mỗi test case in ra trên 1 dòng.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2<br>10<br>28 | <br>18<br>56 |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>
                
                int sum(int n){
                    int sum = 0;
                    // duyet den can bac hai cua n
                    for(int i = 1; i<= sqrt(n);i++){
                        if(n % i == 0){
                            // ta tim duoc 2 uoc la i va n/i
                            // vi du n = 28 thi i = 4 va n/i = 7
                            // cong ca 2 uoc vao tong neu chung khac nhau
                            if(i != n/i) sum += i + (n/i);
                            // neu la so chinh phuong thi uoc bi trung
                            // vi du n = 9 thi i = 3, n/i = 3
                            // ta chi cong 1 lan
                            else sum += i;
                        }
                    }
                    return sum;
                }

                // neu de hoi dem so luong uoc cua so n 
                int count(int n){
                    int count = 0;
                    for(int i = 1; i<= sqrt(n);i++){
                        if(n % i == 0){
                            // neu khac nhau dem 2
                            // vi du n = 28 thi i = 4 va n/i = 7
                            // ta dem 2 vì 4 và 7 là 2 uoc khac nhau
                            if(i != n/i) count += 2;
                            // neu trung thi dem 1
                            // vi du n = 9 thi i = 3, n/i = 3
                            // ta chi dem 1 vi 3 la 1 uoc duy nhat
                            else count += 1;
                        }
                    }
                    return count;
                }
                
                int main(){
                    int t;
                    scanf("%d",&t);
                    while(t--){
                        int n;
                        scanf("%d",&n);
                        printf("%d\n",sum(n));
                    }
                }
```