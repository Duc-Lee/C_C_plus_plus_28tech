# Bài tập Mảng 1 Chiều - Buổi 7

## Bài 11. Các số xuất hiện trong mảng
Cho mảng các số nguyên. Thực hiện liệt kê các giá trị xuất hiện trong mảng theo thứ tự xuất hiện, mỗi giá trị xuất hiện chỉ liệt kê một lần.

**Input**
Dòng đầu tiên là số lượng phần tử trong mảng n. (1≤n≤10^6).
Dòng thứ 2 là các phần tử ai trong mảng. (0≤ai≤10^6).

**Output**
Kết quả của bài toán.

| Input | Output |
|---|---|
| 10<br>1 2 3 3 3 3 1 9 9 0 | 1 2 3 9 0 |

**Code**
```cpp
            // Khai báo ngoài để tránh tràn bộ nhớ stack 
            // mảng mark dùng để lưu xem số có xuất hiện chưa
            // nếu rồi thì sẽ gán 1 
            int mark[1000001] = {0};
            int main(){
                int n;
                scanf("%d",&n);
                int a[n];
                for(int i=0;i<n;i++){
                    scanf("%d",&a[i]);
                }
                // duyệt mảng 
                for(int i=0;i<n;i++){
                    if(mark[a[i]] == 0){
                        printf("%d ",a[i]);
                        mark[a[i]] = 1;
                    }
                }
            }
```

## Bài 12. Tần suất lớn nhất 1
Cho mảng các số nguyên. Thực hiện tìm số có số lần xuất hiện nhiều nhất trong mảng, trong trường hợp có nhiều số có cùng số lần xuất hiện thì lấy số có giá trị nhỏ hơn.

**Input**
Dòng đầu tiên là số lượng phần tử trong mảng n. (1≤n≤10000).
Dòng thứ 2 là các phần tử ai trong mảng . (0≤ai≤10^6).

**Output**
In ra số có số lần xuất hiện nhiều nhất và số lần xuất hiện của nó

| Input | Output |
|---|---|
| 10<br>1 2 3 3 3 3 9 9 9 9 | 3 4 |

**Code**
```cpp
            // Khởi tạo mảng tần suất
            int cnt[1000001] = {0};
            int main(){
                int n;
                scanf("%d",&n);
                int a[n];
                for(int i=0;i<n;i++){
                    scanf("%d",&a[i]);
                }
                // đếm tần số xuất hiện mỗi phần tử 
                for(int i =0 ;i<n;i++){
                    cnt[a[i]]++;
                }
                // khởi tạo
                int res = 0, dem = 0;
                for(int i = 0; i<n;i++){
                    // Tìm kỉ lục tần suất nhất 
                    if(dem < cnt[a[i]]){
                        dem = cnt[a[i]];
                        res = a[i];
                    // nếu tần suất hiện tại = kỉ lục
                    // thì lấy kết quả phần tử bé hơn 
                    }else if(cnt[a[i]] == dem){
                        if(res > a[i]){
                            res = a[i];
                        }
                    }
                }
                // In ra kết quả 
                printf("%d %d",res,dem);
            }
```

## Bài 13. Tần suất lớn nhất 2
Cho mảng các số nguyên. Thực hiện tìm số có số lần xuất hiện nhiều nhất trong mảng, trong trường hợp có nhiều số có cùng số lần xuất hiện thì lấy số xuất hiện trước trong mảng.

**Input**
Dòng đầu tiên là số lượng phần tử trong mảng n. (1≤n≤10000).
Dòng thứ 2 là các phần tử ai trong mảng. (0≤ai≤10^6).

**Output**
In ra số có số lần xuất hiện nhiều nhất và số lần xuất hiện của nó

| Input | Output |
|---|---|
| 10<br>1 2 9 9 9 9 3 3 3 3 | 9 4 |

**Code**
```cpp
            // Cách trâu bò O(n^2)
            int cach_trau(int n,int a[]){
                int dem = 0, res = 0, cnt = 0;
                for(int i =0 ;i<n;i++){
                    for(int j = i + 1;j<n;j++){
                        if(a[i] == a[j]){
                            ++dem;
                        }
                    }
                    if(dem > cnt){
                        cnt = dem;
                        res = a[i];
                    }
                }
            }

            // Khởi tạo mảng tần suất
            int cnt[1000001] = {0};
            int main(){
                int n;
                scanf("%d",&n);
                int a[n];
                for(int i=0;i<n;i++){
                    scanf("%d",&a[i]);
                }
                // đếm tần số xuất hiện mỗi phần tử 
                for(int i =0 ;i<n;i++){
                    cnt[a[i]]++;
                }
                // khởi tạo
                int res = 0, dem = 0;
                for(int i = 0; i<n;i++){
                    // Tìm kỉ lục tần suất nhất 
                    if(dem < cnt[a[i]]){
                        dem = cnt[a[i]];
                        res = a[i];
                }
                // In ra kết quả 
                printf("%d %d",res,dem);
            }       
```

## Bài 14. Tần suất 3
Cho mảng các số nguyên không âm, thực hiện liệt kê các giá trị trong mảng và số lần xuất hiện.

**Input**
Dòng đầu tiên là số lượng phần tử trong mảng n. (1≤n≤10000).
Dòng thứ 2 là các phần tử ai trong mảng. (0≤ai≤10^6).

**Output**
In ra các giá trị trong mảng và số lần xuất hiện.

| Input | Output |
|---|---|
| 10<br>1 2 9 9 9 9 3 3 3 3 | 1 1<br>2 1<br>9 4<br>3 4 |

**Code**
```cpp
            // Khởi tạo mảng tần suất 
            int cnt[1000001] = {0};
            int main(){
                int n;
                scanf("%d",&n);
                int a[n];
                for(int i=0;i<n;i++){
                    scanf("%d",&a[i]);
                }
                // đếm số lần xuất hiện mỗi phần tử 
                for(int i=0;i<n;i++){
                    ++cnt[a[i]];
                }
                // In số lần xuất hiện 
                for(int i = 0;i<n;i++){
                    // Để có thể in 1 lần 
                    if(cnt[a[i]] != 0){
                        printf("%d %d\n",a[i],cnt[a[i]]);
                        // gán lại bằng 0
                        // để không in lại lần nữa
                        cnt[a[i]] = 0;
                    }
                }
            }
```

## Bài 15. Liệt kê các số chỉ xuất hiện một lần trong mảng
Cho mảng các số nguyên không âm, thực hiện liệt kê các số chỉ xuất hiện một lần trong mảng.

**Input**
Dòng đầu tiên là số lượng phần tử trong mảng n. (1≤n≤10000).
Dòng thứ 2 là các phần tử ai trong mảng . (0≤ai≤10^6).

**Output**
In ra các số chỉ xuất hiện một lần trong mảng.

| Input | Output |
|---|---|
| 10<br>1 2 9 9 9 9 3 3 3 3 | 1 2 |

**Code**
```cpp
            int cnt[1000001] = {0};
            int main(){
                int n;
                scanf("%d",&n);
                int a[n];
                for(int i=0;i<n;i++){
                    scanf("%d",&a[i]);
                }
                // Đếm số lần xuất hiện 
                for(int i=0;i<n;i++){
                    ++cnt[a[i]];
                }
                // In những số chỉ xuất hiện 1 lần 
                for(int i =0;i<n;i++){
                    if(cnt[a[i]] == 1){
                        printf("%d ",a[i]);
                    }
                }
            }

```
