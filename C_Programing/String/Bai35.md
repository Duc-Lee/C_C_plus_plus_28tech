## Bài 17. Số nhị phân chia hết cho 2^x

Kiểm tra một số nguyên dương được biểu diễn dưới dạng số nhị phân có chia hết cho 2^x hay không.

**Input**

Dòng đầu tiên là số lượng bộ test, mỗi bộ test gồm một dòng bao gồm số nhị phân n có không quá 1000 bit và số tự nhiên x (1 <= x <= 1000).

**Output**

In YES nếu n chia hết cho 2^x, ngược lại in NO.

**Ví dụ**

**Input**
```text
2
10101010101010101010101010101000000000 6
1111111111111110101010101010101010101010101010101010101010101010101010101010101010101011011111111111111111111111111111110111111111111111111111111111111111111111111100000000000000000000000000000000000000000000000001111111101010 3
```

**Output**
```text
YES
NO
```

**Code**
```cpp
                    #include <stdio.h>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <ctype.h>
                    
                    // một số n chia hết cho 2^x khi và chỉ khi n có ít nhất x số 0 ở cuối 
                    int check(char c[], int k){
                        // nếu chiều dài xâu < k thì return 0 luôn 
                        if(strlen(c) < k) return 0;
                        // duyệt k số cuối 
                        for(int i = 0;i<k;i++){
                            // nếu có số 1 ở cuối thì return 0
                            if(c[strlen(c)-i-1] == '1'){
                                return 0;
                            }
                        }
                        return 1;
                    }
                    int main(){
                        int t;
                        scanf("%d",&t);
                        while(t--){
                            char c[1001];
                            int k;
                            scanf("%s%d",c,&k);
                            if(check(c,k)) printf("YES\n");
                            else printf("NO\n");
                        }
                    }
```