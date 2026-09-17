# Mảng 1 chiều trong ngôn ngữ lập trình C

## 1. Khái niệm:
- Là tập hợp các phần tử cùng kiểu dữ liệu và được lưu trữ liên tiếp trong bộ nhớ.

## 2. Cú pháp:
- Khai báo: `kiểu_dữ_liệu tên_mảng[kích_thước];`

- Ví dụ : 
```cpp
            // Khai báo 1 mảng có tối đa 100 phần tử số nguyên 
            int a[100];
            // Khai báo 100 phần tử có giá trị 0 
            int b[100] = {0};
            // Khai báo mảng rỗng 
            int c[5]= { };
```
- Khi khai báo mảng `a` với `100` phần tử thì mảng `a` có chỉ số từ `0` đến `99` do hệ điều hành cấp cho 100 ô nhớ liên tiếp nhau, mỗi ô nhớ có kích thước là `sizeof(int)`.
- Mỗi phần tử đều có kiểu dữ liệu là `int`.
- Kích thước thực tế của mảng `a` là `100 * sizeof(int)`.
- Để truy cập vào phần tử thứ `i` của mảng `a` ta dùng `a[i]`.

- Ví dụ :
```cpp
                int arr[5] = {10,4,2,7,89};
                // In ra các phần tử 
                for(int i =0;i < 5;i++){
                    printf("%d",arr[i]);
                }
```

Minh họa bộ nhớ :
```text
+----------+----------+----------+----------+----------+
|    10    |    4     |    2     |    7     |    89    |  <-- Giá trị (Value)
+----------+----------+----------+----------+----------+
     0          1          2          3          4        <-- Chỉ số (Index)
```
- Truy cập mỗi phần tử `arr[i]` với độ phức tạp thời gian là `O(1)`
- Ví dụ : 
```cpp
                int a[5] = {10,4,2,7,89};
                cout << a[0] << endl; // In ra 10
                cout << a[4] << endl; // In ra 89
```

- Ví dụ : Nhập các phần tử trong mảng và in ra 
```cpp
                int a[5];
                // Nhập các phần tử trong mảng 
                for (int i =0;i<5;i++){
                    scanf("%d",&a[i]);
                    // câu lệnh này có thể tương đương 
                    // scanf("%d",a+i);
                }
                // In ra các giá trị 
                for(int i =0;i<5;i++){
                    printf("%d",a[i]);
                }
```
- Cũng có thể khai báo động 
```cpp
                int n;
                scanf("%d",&n);
                int a[n];
                for(int i=0;i<n;i++){
                    scanf("%d",a+i);
                }
                for(int i=0;i<n;i++){
                    printf("%d",a[i]);
                }
```

- Ví dụ : Truyền tham số cho hàm 
```cpp
                void nhap(int n, int a[]){
                    for (int i=0;i<n;i++){
                        scanf("%d",&a[i]);
                    }
                }
                void xuat(int n, int a[]){
                    for (int i=0;i<n;i++){
                        printf("%d ",a[i]);
                    }
                }
                int main(){
                    int n;
                    scanf("%d",&n);
                    int a[n];
                    nhap(n,a);
                    xuat(n,a);
                    return 0;
                }
```
- Lưu ý : 
    - Dù truyển tham số cho hàm nhưng những giá trị truyền có thể làm thay đổi mảng do mảng là kiểu dữ liệu tham chiếu, bản chất vẫn vẫn là **hằng con trỏ**
    - Khi truyền vào trong hàm giá trị của `a` thực chất là `&a[0]`, tức là đang thao tác trực tiếp trên vùng nhớ `a[i]` nên những gì thay đổi sẽ được giữ nguyên sau khi kết thúc hàm.

- Ví dụ : Tổng các phần tử trong mảng 
```cpp
                void nhap(int n, int a[]){
                    for(int i=0;i<n;i++){
                        scanf("%d",&a[i]);
                    }
                }

                int sum_array(int n, int a[]){
                    int sum = 0;
                    for (int i =0;i<n;i++){
                        sum += a[i];
                    }
                    return sum;
                }
                
                int main(){
                    int n;
                    scanf("%d",&n);
                    int a[n];
                    nhap(n,a);
                    printf("%d",sum_array(n,a));
                    return 0;
                }
```

## 3. Các thao tác cơ bản 
### a. Kiểm tra tính chất các phần tử trong mảng như đếm số nguyên tố, đếm số chẵn, đếm số lẻ, số hoàn hảo,...

```cpp
                // Kiểm tra số nguyên tố
                int nt(int n){
                    for(int i =2;i<= sqrt(n);i++){
                        return 0;
                    }
                    return n > 1;
                }

                int main(){
                    int n;
                    scanf("%d",&n);
                    int a[n];
                    for (int i =0;i<n;i++){
                        scanf("%d",&a[i]);
                    }
                    // Đếm số nguyên tố trong mảng 
                    int cnt = 0;
                    for (int i = 0;i<n;i++){
                        if(nt(a[i])){
                            cnt++;
                        }
                    }
                    printf("%d",cnt);
                    return 0;
                }
```
### b. Tìm phần tử lớn nhất, nhỏ nhất trong mảng
```cpp
                int n;
                scanf("%d",&n);
                int a[n];
                for (int i =0;i<n;i++){
                    scanf("%d",&a[i]);
                }
                // Gán max hiện tại cho a[0]
                int max = a[0];
                for(int i =1;i <n ;i++){
                    // Min thì ngược lại 
                    if(max<a[i]){
                        max=a[i];
                    }
                }
                printf("%d",max);
```

### c. Sắp xếp, tìm kiếm 
### d. Mảng cộng dồn, cửa sổ trượt, hai con trỏ



