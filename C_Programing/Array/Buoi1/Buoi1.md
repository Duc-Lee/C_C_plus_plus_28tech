# Buổi 1 : Bài tập Mảng 1 chiều cơ bản 

## Bài 1. Các bài toán làm quen với mảng một chiều.
Cho mảng một chiều bao gồm các số nguyên.

### Input
- Dòng đầu tiên là số lượng phần tử trong mảng n. ($1 \le n \le 10^6$).
- Dòng thứ 2 là các phần tử trong mảng $a_1, a_2, a_3, \dots, a_n$ được đặt cách nhau một vài khoảng trắng. ($-10^9 \le a_i \le 10^9$).

### Output
- In ra kết quả tương ứng với yêu cầu của đề bài.

---

### a. In ra số lớn nhất và nhỏ nhất trong mảng.

#### Ví dụ:
| Input | Output |
| :--- | :--- |
| `5`<br>`-2 10 2 9 3` | `10 -2` |

#### Code:
```cpp
                    int n;
                    scanf("%d",&n);
                    int a[n];
                    for (int i =0;i<n;i++){
                        scanf("%d",&a[i]);
                    }
                    int max = a[0], min = a[0];
                    // Tim số lớn nhất và nhỏ nhất 
                    for(int i=0;i<n;i++){
                        // Tìm phần lớn nhất 
                        if(max < a[i]) max = a[i];
                        // Tìm phần tử nhỏ nhất 
                        if(min > a[i]) min = a[i];
                    }
                    printf("%d %d",max,min);
```

---

### b. Đếm số lượng số chẵn, lẻ trong mảng.

#### Ví dụ:
| Input | Output |
| :--- | :--- |
| `5`<br>`2 10 2 9 3` | `3 2` |

#### Code:
```cpp
                    int n;
                    scanf("%d",&n);
                    int a[n];
                    for (int i =0;i<n;i++){
                        scanf("%d",&a[i]);
                    }
                    int chan = 0, le = 0;
                    for (int i =0;i<n;i++){
                        if(a[i]%2==0){
                            chan++;
                        }else{
                            le++;
                        }
                    }
                    printf("%d %d",chan,le);
```

---

### c. Liệt kê các số nguyên tố trong mảng.

#### Ví dụ:
| Input | Output |
| :--- | :--- |
| `5`<br>`2 10 2 9 3` | `2 2 3` |

#### Code:
```cpp
                    int nt(int n) {
                        for (int i = 2; i * i <= n; i++) {
                            if (n % i == 0) return 0;
                        }
                        return n > 1;
                    }

                    int main() {
                        int n;
                        scanf("%d", &n);
                        int a[n];
                        for (int i = 0; i < n; i++) {
                            scanf("%d", &a[i]);
                        }
                        for (int i = 0; i < n; i++) {
                            if (nt(a[i])) {
                                printf("%d ", a[i]);
                            }
                        }
                        return 0;
                    }
```

---

### d. Tìm và in ra chỉ số của số nhỏ nhất (lớn nhất) trong mảng, nếu có nhiều số có cùng giá trị nhỏ nhất thì in ra chỉ số đầu tiên (cuối cùng).

#### Ví dụ:
| Input | Output |
| :--- | :--- |
| `5`<br>`2 10 2 9 3` | `0` |

| Input | Output |
| :--- | :--- |
| `5`<br>`2 10 2 9 3` | `2` |

*(Giải thích: Output `0` tương ứng với chỉ số đầu tiên của số nhỏ nhất 2. Output `2` tương ứng với chỉ số cuối cùng của số nhỏ nhất 2).*

#### Code:

##### Hướng 1: In ra chỉ số đầu tiên của số nhỏ nhất (Ứng với Output = 0)
```cpp
                    int n;
                    scanf("%d", &n);
                    int a[n];
                    for (int i = 0; i < n; i++) {
                        scanf("%d", &a[i]);
                    }
                    int min_val = a[0];
                    int min_idx = 0;
                    for (int i = 1; i < n; i++) {
                        if (a[i] < min_val) {
                            min_val = a[i];
                            min_idx = i;
                        }
                    }
                    printf("%d", min_idx);
```

##### Hướng 2: In ra chỉ số cuối cùng của số nhỏ nhất (Ứng với Output = 2)
```cpp
                    int n;
                    scanf("%d", &n);
                    int a[n];
                    for (int i = 0; i < n; i++) {
                        scanf("%d", &a[i]);
                    }
                    int min_val = a[0];
                    int min_idx = 0;
                    for (int i = 1; i < n; i++) {
                        if (a[i] <= min_val) { // Dùng dấu <= để lấy phần tử cuối cùng
                            min_val = a[i];
                            min_idx = i;
                        }
                    }
                    printf("%d", min_idx);
```

##### Hướng 3: In ra chỉ số cuối cùng của số lớn nhất (Phần trong ngoặc đơn của đề bài)
```cpp
                    int n;
                    scanf("%d", &n);
                    int a[n];
                    for (int i = 0; i < n; i++) {
                        scanf("%d", &a[i]);
                    }
                    int max_val = a[0];
                    int max_idx = 0;
                    for (int i = 1; i < n; i++) {
                        if (a[i] >= max_val) { // Dùng dấu >= để lấy phần tử cuối cùng
                            max_val = a[i];
                            max_idx = i;
                        }
                    }
                    printf("%d", max_idx);
```

---

### e. Tìm và in ra số lớn nhất và lớn thứ 2 trong mảng. Các bạn làm thêm với số nhỏ nhất và nhỏ thứ 2.

#### Ví dụ:
| Input | Output |
| :--- | :--- |
| `5`<br>`2 10 2 9 10` | `10 10` |

#### Code:
```cpp
                    int main(){
                        int n;
                        scanf("%d",&n);
                        int a[n];
                        for( int i =0;i<n;i++){
                            scanf("%d",&a[i]);
                        }
                        int max1 = -1e9, max2 = -1e9;
                        for(int i=1;i<n;i++){
                            if(max1 < a[i]){
                                max2 = max1;
                                max1 = a[i];
                            }else if(max2 < a[i]){
                                max2 = a[i];
                            }
                        }
                        printf("%d %d",max1,max2)
                    }
```

---

### f. Tìm và in ra số lớn nhất và lớn thứ 2 trong mảng, 2 số này là 2 số có giá trị khác nhau. Nếu không có số lớn thứ 2 in ra -1 cho số thứ 2. Các bạn làm thêm với số nhỏ nhất và nhỏ thứ 2.

#### Ví dụ:
| Input | Output |
| :--- | :--- |
| `5`<br>`2 10 2 9 10` | `10 9` |

| Input | Output |
| :--- | :--- |
| `5`<br>`9 9 9 9 9` | `9 -1` |

#### Code:
```cpp
                        int main(){
                            int n;
                            scanf("%d",&n);
                            int a[n];
                            for(int i=0;i<n;i++){
                                scanf("%d",&a[i]);
                            }
                            int max1 = -1e9, max2 = -1e9;
                            for(int i=0;i<n;i++){
                                if( max1 < a[i]){
                                    max2 = max1;
                                    max1 = a[i];
                                }else if (max2 < a[i] &&  a[i] != max1){
                                    max2 = a[i]
                                }
                            }
                            // In theo điều kiện 
                            if(max2 == -1e9){
                                printf("%d %d",max1,-1);
                            }else{
                                printf("%d %d",max1,max2);
                            }
                        }
```

---

### g. Đếm và liệt kê các số toàn chữ số lẻ trong mảng.

#### Ví dụ:
| Input | Output |
| :--- | :--- |
| `5`<br>`3 5 7 11 23` | `4`<br>`3 5 7 11` |

#### Code:
```cpp
                        // check các số trong chữ số ấy có lẻ không ?
                        int check(int n){
                            while(n != 0){
                                int r = n%10;
                                if(r%2 == 0) return 0;
                                n /= 10;
                            }
                            return 1;
                        }
                        int main(){
                            int n;
                            scanf("%d",&n);
                            int a[n];
                            for(int i=0;i<n;i++){
                                scanf("%d",&a[i]);
                            }
                            int dem = 0;
                            for(int i=0;i<n;i++){
                                if(check(a[i])){
                                    ++dem;
                                }
                            }
                            // In ra các số toàn lẻ
                            for(int i =0;i<n;i++){
                                if(check(a[i])){
                                    printf("%d ",a[i]);
                                }
                            }
                        }
```
- Cách 2 : 
```cpp
                        int dem = 0;
                        int b[n]; // dùng mảng để lưu mảng con
                        for(int i=0;i<n;i++){
                            if(check(a[i])){
                                b[dem] = a[i];
                                ++dem;
                            }
                        }
                        // In ra kết quả 
                        for(int i=0;i<dem;i++){
                            printf("%d ",b[i]);
                        }
```

---

### h. Cho mảng các số nguyên khác nhau đôi một. Liệt kê các phần tử trong mảng có ít nhất 2 phần tử khác lớn hơn nó.

#### Ví dụ:
| Input | Output |
| :--- | :--- |
| `5`<br>`3 5 7 11 23` | `3 5 7` |

#### Code:
```cpp
                        int main(){
                            int n;
                            scanf("%d",&n);
                            int a[n];
                            for(int i=0;i>n;i++){
                                scanf("%d",&a[i]);
                            }
                            // tìm phần tử lớn thứ 2
                            int max1 = -1e9, max2 = -1e9;
                            for (int i=0;i<n;i++){
                                if(max1 < a[i]){
                                    max2 = max1;
                                    max1 = a[i];
                                }esle if(max2 < a[i]){
                                    max2 = a[i];
                                }
                            }
                            // In những phần tử nhỏ hơn max2
                            for(int i=0;i<n;i++){
                                if(a[i]<max2){
                                    printf("%d ",a[i]);
                                }
                            }
                            return 0;
                        }
```

---

### i. Một số được định nghĩa là số đẹp nếu nó chứa cả chữ số 1 và chữ số 9. In ra các số đẹp trong mảng. Nếu mảng không tồn tại số đẹp thì in ra -1.

#### Ví dụ:
| Input | Output |
| :--- | :--- |
| `5`<br>`3 5 7 11 91900` | `91900` |

#### Code:
```cpp
                        int check(int n){
                            int c1 = 0, c2 = 0;
                            while( n != 0){
                                int r = n % 10;
                                if (r == 9)
                                    c2 = 9;
                                if (r == 1)
                                    c1 = 1;
                                n /= 10;
                            }
                            // chỉ cần 1 0 thì phép && cho 0 luôn 
                            // chỉ đúng khi 1 1
                            return c1&&c2;
                        }
                        int main(){
                            int n;
                            scanf("%d",&n);
                            int a[n];
                            for(int i=0;i<n;i++){
                                scanf("%d",&a[i]);
                            }
                            // khởi tạo biến ok để kiểm tra xem có tìm đc số đẹp hay không ?
                            int ok = 0;
                            for(int i =0;i<n;i++){
                                if(check(a[i])){
                                    printf("%d",a[i]);
                                    ok = 1;
                                }
                            }
                            if(ok == 0){
                                printf("-1");
                            }
                            return 0;
                        }
```

---

### j. Cho mảng một chiều các số nguyên, liệt kê các phần tử có ít nhất một phần tử liền kề trái dấu với nó.

#### Ví dụ:
| Input | Output |
| :--- | :--- |
| `7`<br>`-1 2 3 -1 5 8 9` | `-1 2 3 -1 5` |

#### Code:
```cpp
                        int main(){
                            int n;
                            scanf("%d",&n);
                            int a[n];
                            for(int i=0;i<n;i++){
                                scanf("%d",&a[i]);
                            }
                            // kiểm tra trái dấu 
                            for(int i=0;i<n;i++){
                                // Kiểm tra đầu tránh tràn số
                                if(i == 0 && a[0] * a[1] < 0 ){
                                    printf("%d ",a[0]);
                                // Kiểm tra đầu để tránh tràn số 
                                }else if(i == n-1 && a[n-1]*a[n-2]<0){
                                    printf("%d",a[n-1]);
                                }
                                else if(a[i]*a[i-1] < 0 || a[i]*a[i+1] < 0){
                                    printf("%d ",a[i]);
                                }
                            }
                        }
```

---

### k. Kiểm tra xem mảng có đối xứng hay không, nếu có in YES, ngược lại in NO.

#### Ví dụ:
| Input | Output |
| :--- | :--- |
| `7`<br>`1 2 3 4 3 2 1` | `YES` |

#### Code:
```cpp
                        int main(){
                            int n;
                            scanf("%d",&n);
                            int a[n];
                            for(int i=0;i<n;i++){
                                scanf("%d",&a[i]);
                            }
                            // khai báo kiến check 
                            int check = 1;
                            int right = n-1, left = 0;
                            while(left < right){
                                // kiểm tra xem có bất đối xứng ko
                                if (a[left] != a[right]){
                                    check = 0;
                                    break;
                                }
                                ++left;
                                --right;
                            }
                            if(check == 1){
                                printf("YES");
                            }
                            else{
                                printf("NO");
                            }
                        }
```




