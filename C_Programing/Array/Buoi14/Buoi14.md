# Bài tập Mảng 1 Chiều - Buổi 14

## Bài 23. Sắp xếp chẵn lẻ

Cho mảng có $n$ số nguyên, thực hiện sắp xếp các phần tử trong mảng sao cho các số chẵn xếp trước, các số lẻ xếp sau, các số đều được xếp theo thứ tự tăng dần.

### Input
- Dòng đầu tiên là số lượng phần tử trong mảng $n$ ($1 \le n \le 1000$).
- Dòng thứ 2 là $n$ phần tử trong mảng ($-10^6 \le a_i \le 10^6$).

### Output
- In ra kết quả theo yêu cầu đề bài.

### Ví dụ
| Input | Output |
| :--- | :--- |
| 10<br>9 8 1 2 3 6 5 4 7 10 | 2 4 6 8 10 1 3 5 7 9 |

### Code
```cpp
                // Hàm sắp xếp selection sort
                void selection_sort(int n, int a[]){
                    for(int i =0;i<n;i++){
                        int m = i;
                        for(int j = i + 1;j<n;j++){
                            // Sắp xếp tăng dần 
                            if(a[m] > a[j]) m = j;
                        }
                        // Swap phần tử có index nhỏ nhất với phần tử tại vị trí i 
                        int temp = a[i];
                        a[i] = a[m];
                        a[m] = temp;
                    }
                }

                int main(){
                    int n;
                    scanf("%d",&n);
                    int chan[n],le[n],c = 0,l = 0;
                    // Nhập hàm chẵn vô hàm chẵn
                    // Hàm lẻ vô hàm lẻ 
                    for(int i=0;i<n;i++){
                        int x;
                        scanf("%d",&x);
                        if(x%2 == 0) chan[c++] = x;
                        else le[l++] = x;
                    }
                    selection_sort(c,chan);
                    selection_sort(l,le);
                    // In chẵn theo tăng dần
                    for(int i=0;i<c;i++){
                        printf("%d ",chan[i]);
                    }
                    // In lẻ theo tăng dần
                    for(int i = 0;i<l;i++){
                        printf("%d ",le[i]);
                    }
                }
```

## Bài 24. Sắp xếp chẵn lẻ 2

Cho mảng có $n$ số nguyên, thực hiện sắp xếp các phần tử trong mảng sao cho các số chẵn xếp trước, các số lẻ xếp sau, các số chẵn được xếp tăng dần, các số lẻ được xếp giảm dần.

### Input
- Dòng đầu tiên là số lượng phần tử trong mảng $n$ ($1 \le n \le 1000$).
- Dòng thứ 2 là $n$ phần tử trong mảng ($-10^6 \le a_i \le 10^6$).

### Output
- In ra kết quả theo yêu cầu đề bài.

### Ví dụ
| Input | Output |
| :--- | :--- |
| 10<br>9 8 1 2 3 6 5 4 7 10 | 2 4 6 8 10 9 7 5 3 1 |

### Code
```cpp
                ```cpp
                // Hàm sắp xếp selection sort
                void selection_sort(int n, int a[]){
                    for(int i =0;i<n;i++){
                        int m = i;
                        for(int j = i + 1;j<n;j++){
                            // Sắp xếp tăng dần 
                            if(a[m] > a[j]) m = j;
                        }
                        // Swap phần tử có index nhỏ nhất với phần tử tại vị trí i 
                        int temp = a[i];
                        a[i] = a[m];
                        a[m] = temp;
                    }
                }

                int main(){
                    int n;
                    scanf("%d",&n);
                    int chan[n],le[n],c = 0,l = 0;
                    // Nhập hàm chẵn vô hàm chẵn
                    // Hàm lẻ vô hàm lẻ 
                    for(int i=0;i<n;i++){
                        int x;
                        scanf("%d",&x);
                        if(x%2 == 0) chan[c++] = x;
                        else le[l++] = x;
                    }
                    selection_sort(c,chan);
                    selection_sort(l,le);
                    // In chẵn theo tăng dần
                    for(int i=0;i<c;i++){
                        printf("%d ",chan[i]);
                    }
                    // In lẻ theo tăng dần
                    for(int i = l-1;i>=0;i--){
                        printf("%d ",le[i]);
                    }
                }
```
