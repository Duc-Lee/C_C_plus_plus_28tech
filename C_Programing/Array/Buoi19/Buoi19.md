# Bài tập Mảng 1 Chiều - Buổi 19

## Bài 30. Tam giác vuông

Theo định lý Pytago, ta đã biết một bộ 3 số (a, b, c) thỏa mãn $a^2 + b^2 = c^2$ thì đó là ba cạnh của một tam giác vuông.

Cho dãy số A[] gồm có N phần tử. Nhiệm vụ của bạn là kiểm tra xem *có tồn tại bộ ba số thỏa mãn là ba cạnh của tam giác vuông hay không*.

### Input
- Dòng đầu tiên là số lượng bộ test T ($T \le 20$).
- Mỗi test gồm số nguyên N ($1 \le N \le 5000$).
- Dòng tiếp theo gồm N số nguyên A[i] ($1 \le A[i] \le 10^9$).

### Output
- Với mỗi test, in ra trên một dòng "YES" nếu tìm được, và "NO" trong trường hợp ngược lại.

### Ví dụ
| Input | Output |
| :--- | :--- |
| 2<br>5<br>3 1 4 6 5<br>3<br>1 1 1 | YES<br>NO |

### Code
```cpp
                #include <tsdio.h>
                #define ll long long

                void selection_sort(int n, int a[]){
                    for(int i=0;i<n;i++){
                        int m = i;
                        for(int j = i+1;j<n;j++){
                            // sắp xếp tăng dần
                            if(a[m] > a[j]) m = j;
                        }
                        int temp = a[i];
                        a[i] = a[m];
                        a[m] = temp;
                    }
                }

                int 
                
                int main(){
                    int t;
                    scanf("%d",&t);
                    while(t--){
                        int n;
                        scanf("%d",&n);
                        int a[n];
                        for(int i=0;i<n;i++){
                            // nhập phần tử mảng 
                            int x;
                            scanf("%d",&x);
                            // bình phương số vừa nhập lên 
                            a[i] = ll*x*x;
                        }
                        // sắp xếp lại mảng 
                        selection_sort(n,a);
                    }
                }
```