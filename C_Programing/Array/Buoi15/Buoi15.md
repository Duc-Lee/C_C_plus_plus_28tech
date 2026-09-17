# Bài tập Mảng 1 Chiều - Buổi 15

## Bài 25. Số xuất hiện nhiều lần nhất trong dãy

Cho một dãy số nguyên dương không quá 100 phần tử, các giá trị trong dãy không quá 30000. Hãy xác định xem số nào là số xuất hiện nhiều lần nhất trong dãy. 

*Chú ý: Trong trường hợp nhiều số khác nhau cùng xuất hiện số lần bằng nhau và là lớn nhất thì in ra tất cả các số đó theo thứ tự xuất hiện trong dãy ban đầu.*

### Input
- Dòng đầu là số bộ test, không quá 20.
- Mỗi bộ test gồm hai dòng:
  - Dòng đầu ghi số phần tử của dãy.
  - Dòng tiếp theo ghi các phần tử của dãy.

### Output
- Với mỗi bộ test, đưa ra số xuất hiện nhiều lần nhất trong dãy đã cho.

### Ví dụ
| Input | Output |
| :--- | :--- |
| 2<br>10<br>1 2 3 1 2 3 1 2 3 1<br>10<br>1 2 3 4 5 6 7 8 9 0 | 1<br>1 2 3 4 5 6 7 8 9 0 |

### Code
```cpp
                int main(){
                    int t;
                    scanf("%d",&t);
                    while(t--){
                        int n;
                        scanf("%d",&n);
                        int a[n];
                        for(int i=0;i<n;i++){
                            scanf("%d",&a[i]);
                        }
                        int cnt[1000001] = {0};
                        // Đếm tần suất 
                        for(int i=0;i<n;i++){
                            cnt[a[i]]++;
                        }
                        // Tìm kỉ lục xuất hiện nhiều nhất
                        int res =0;
                        for(int i =0;i<n;i++){
                            if(res < cnt[a[i]])
                                res = cnt[a[i]];    
                        }
                        // In những số xuất hiện nhiều nhất 
                        for(int i=0;i<n;i++){
                            if(res == cnt[a[i]]){
                                printf("%d ",a[i]);
                                // gán lại để không in lại lần nữa
                                cnt[a[i]] = 0;
                            }
                        }
                        printf("\n");
                    }
                }
```

## Bài 26. Trộn 2 dãy và sắp xếp

Cho hai dãy số nguyên dương A và B không quá 100 phần tử, các giá trị trong dãy không quá 30000 và số phần tử của hai dãy bằng nhau. Hãy trộn hai dãy với nhau sao cho dãy A được đưa vào các vị trí có chỉ số chẵn, dãy B được đưa vào các vị trí có chỉ số lẻ. Đồng thời, dãy A được sắp xếp tăng dần, còn dãy B được sắp xếp giảm dần. *(Chú ý: Chỉ số tính từ 0)*

### Input
- Dòng đầu tiên ghi số bộ test.
- Với mỗi bộ test:
  - Dòng đầu tiên ghi số $n$.
  - Dòng tiếp theo ghi $n$ số nguyên dương của dãy A.
  - Dòng tiếp theo ghi $n$ số nguyên dương của dãy B.

### Output
- Với mỗi bộ test, đưa ra thứ tự bộ test và dãy kết quả.

### Ví dụ
| Input | Output |
| :--- | :--- |
| 2<br>5<br>1 2 3 1 2<br>3 1 2 3 1<br>4<br>4 2 7 1<br>5 6 2 8 | Test 1:<br>1 3 1 3 2 2 2 1 3 1<br>Test 2:<br>1 8 2 6 4 5 7 2 |

### Code
```cpp
                void sx_tang(int n, int a[]){
                    for(int i=0;i<n;i++){
                        int m = i;
                        for(int j = i+1;j<n;j++){
                            // Sắp xếp tăng dần 
                            if(a[m] > a[j]) m = j;
                        }
                        int temp = a[m];
                        a[m] = a[i];
                        a[i] = temp;
                    }
                }
                void sx_giam(int n, int a[]){
                    for(int i=0;i<n;i++){
                        int m = i;
                        for(int j = i+1;j<n;j++){
                            // Sắp xếp giảm dần 
                            if(a[m] < a[j]) m = j;
                        }
                        int temp = a[m];
                        a[m] = a[i];
                        a[i] = temp;
                    }
                }
                int main(){
                    int t;
                    scanf("%d",&t);
                    for(int i = 1;i<=t;i++){
                        int n;
                        scanf("%d",&n);
                        int a[n], b[n];
                        // Nhap 2 mang 
                        for(int i = 0;<n;i++){
                            scanf("%d",&a[i]);
                        }
                        for(int i = 0;i<n;i++){
                            scanf("%d",&b[i]);
                        }
                        // sx theo yeu cau
                        sx_tang(n,a);
                        sx_giam(n,b);
                        prinf("Test %d:",t);
                        for(int i =0; i< n;i++){
                            printf("%d %d ",a[i],b[i]);
                        }
                        printf("\n");
                    }
                }

```