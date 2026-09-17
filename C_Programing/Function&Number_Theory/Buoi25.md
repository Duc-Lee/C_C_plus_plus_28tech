**Bài 4. Đếm số lượng chính phương trong đoạn.**

Đếm số lượng các số chính phương trong đoạn từ a tới b.

**Input**

Dòng đầu tiên là số lượng test case T(1≤n≤100).

T dòng tiếp theo mỗi dòng là 2 số nguyên dương a, b (1≤a≤b≤10⁶)

**Output**

Mỗi test case in ra trên 1 dòng.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 2<br>1 50<br>10 20 | <br>7<br>1 |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>
                
                int main(){
                    int t;
                    scanf("%d",&t);
                    while(t--){
                        int a, b;
                        scanf("%d %d",&a,&b);
                        // tinh can bac hai cua a va b
                        // khi ep kieu int , can bac hai se bi lam tron xuong
                        // vd 49 -> 7
                        // vd 50 -> 7
                        int s1 = sqrt(a);
                        int s2 = sqrt(b);
                        // tinh so chinh phuong trong doan [a,b]
                        int cnt = s2 - s1;
                        // neu s1*s1 == a tuc la a la so chinh phuong
                        if(s1*s1 == a) cnt++;
                        // neu s2*s2 == b tuc la b la so chinh phuong 
                        // (vì s2 đã được làm tròn xuống nên nếu s2*s2 == b, ta không cần cộng thêm vì s2 đã được tính trong s2 - s1 rồi)
                        printf("%d\n",cnt);
                    }
                    return 0;
                }
```