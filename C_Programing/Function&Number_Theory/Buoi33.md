**Bài 15. Đếm chữ số chẵn, lẻ.**

Nhập một số nguyên dương N không quá 9 chữ số. Hãy đếm xem N có bao nhiêu chữ số lẻ và bao nhiêu chữ số chẵn. Nếu không tồn tại số lẻ hoặc số chẵn thì in ra kết quả là 0 cho loại số tương ứng.

**Input**

Số nguyên dương N không quá 9 chữ số.

**Output**

In ra số lượng chữ số lẻ và số lượng chữ số chẵn cách nhau một dấu cách.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 12345678 | 4 4 |

**Code**
```cpp
                #include <stdio.h>
                #include <math.h>
                
                void check(int n){
                    // do 0 khong phai so chan cung khong phai so le
                    if( n == 0) {
                        printf("0 0");
                        return;
                    }
                    // neu khong phai so 0 thi tiep tuc
                    int rev = 0;
                    int chan = 0, le = 0;
                    while(n != 0){
                        rev = n % 10;
                        if(rev % 2 == 0) ++chan;
                        else ++le;
                        n/=10;
                    }
                    printf("%d %d\n",le,chan);
                }
                int main(){
                    int n;
                    scanf("%d",&n);
                    check(n);
                    return 0;
                }
```

---

# **Bài 16. Số Strong.**

Viết chương trình cho phép nhập vào hai số nguyên dương và tìm tất cả các số Strong (là số có tổng giai thừa các chữ số bằng chính nó) nằm trong khoảng đó (nếu không tồn tại số nào thì in ra 0).

**Input**

2 số nguyên dương a, b.

**Output**

In ra tất cả các số Strong trong đoạn [a, b], mỗi số cách nhau một dấu cách (nếu không có số nào thì in ra 0).

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 1 1000 | 1 2 145 |

**Code**
```cpp
                    #include <stdio.h>

                    int gt(int n){
                        if( n == 0) return 1;
                        return gt(n-1) * n;
                    }

                    // ham tinh tong cac chu so
                    int strong_number(int x){
                        int sum = 0, tmp = x;
                        while( x != 0){
                            // tinh tong giai thua cua tung chu so x
                            sum += gt(x % 10);
                            x /= 10;
                        }
                        // kiem tra dieu kien 
                        return tmp == sum;
                    }

                    int main(){
                        int a, b;
                        scanf("%d %d", &a, &b);
                        int ok = 0;
                        // duyet cac so trong doan [a, b]
                        for(int i = a; i <= b; i++){
                            if(strong_number(i)){
                                printf("%d ", i);
                                ok = 1;
                            }
                        }
                        // neu khong ton tai so strong trong doan [a, b]
                        // in ra 0
                        if(ok == 0) printf("0");
                        return 0;
                    }
```
