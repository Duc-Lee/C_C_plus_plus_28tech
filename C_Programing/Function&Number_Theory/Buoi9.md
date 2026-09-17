# Bài 9. Nguyên tố cùng nhau.

Viết chương trình nhập hai số nguyên dương a,b thỏa mãn 2<a<b<100.

Một cặp số (i,j) được gọi là nguyên tố cùng nhau nếu i ≠ j và ước số chung lớn nhất của i với j là 1

Hãy liệt kê các cặp số nguyên tố cùng nhau trong đoạn [a,b] theo thứ tự từ nhỏ đến lớn.

## Input

Chỉ có một dòng ghi hai số a,b

## Output

Các cặp số i,j thỏa mãn được viết lần lượt trên từng dòng theo định dạng (i,j), theo thứ tự từ điển.

## Ví dụ

| Input | Output |
| --- | --- |
| 5 8 | (5,6)<br><br>(5,7)<br><br>(5,8) |

## Code
```cpp
                #include <stdio.h>

                int gcd(int a, int b){
                    if(b == 0)
                        return a;
                    else return gcd(b,a%b);
                }


                int main(){
                    int a,b;
                    scanf("%d %d",&a,&b);
                    for(int i = a; i <= b;i++){
                        for(int j = i + 1; j<=b;j++){
                            if(gcd(i,j) == 1){
                                printf("(%d,%d)\n",i,j);
                            }
                        }
                    }
                }
```