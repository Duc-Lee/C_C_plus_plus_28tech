# Bài tập Mảng 1 Chiều - Buổi 5

## Bài 8 : Dãy con liên tiếp các phần tử kề nhau đều khác nhau

Cho một dãy số nguyên có n phần tử. Tìm dãy con liên tiếp có các phần tử liền kề khác nhau có độ dài lớn nhất.

**Input**

Dòng đầu tiên là số lượng phần tử trong mảng n. (1≤n≤10^6).

Dòng thứ 2 là các phần tử ai trong mảng . (-10^9≤ai≤10^9).

**Output**

Kết quả của bài toán.

**Ví dụ**

| Input | Output |
| :--- | :--- |
| 10<br>1 2 3 3 3 4 5 2 1 3 | 6 |

**Code**
```cpp
                int max(int a, int b){
                    return a < b ? b : a;
                }
                int check(int n, int a[]){
                    int res = 0, cnt = 1;
                    // duyệt từ a[1] vì phần tử đầu tiên luôn đúng 
                    // check xem số trc có khác không 
                    for(int i=1;i<n;i++){
                        if(a[i]!=a[i-1]){
                            // khác thì tăng biến cnt
                            ++cnt;
                        }else {
                            // Gán lại cnt, đếm lại 
                            cnt = 1;
                        }
                        // tìm giá trị max  
                        // cập nhật ngoài if để tránh TH a[n-1]
                        // thì cnt sẽ không đc cập nhật
                        res = max(res,cnt)
                    }
                }

```

### **Ý b:** Tìm dãy con liên tiếp có các phần tử giống nhau có độ dài dài nhất.

| Input | Output |
| :--- | :--- |
| 10<br>1 2 3 3 3 4 5 2 1 3 | 3 |

**Code**
```cpp
                int max(int a, int b){
                    return a < b ? b : a;
                }
                int check(int n, int a[]){
                    int res = 0, cnt = 1;
                    // duyệt từ a[1] vì phần tử đầu tiên luôn đúng 
                    // check xem số trc có khác không 
                    for(int i=1;i<n;i++){
                        if(a[i]==a[i-1]){
                            // giống thì tăng biến cnt
                            ++cnt;
                        }else {
                            // Gán lại cnt, đếm lại 
                            cnt = 1;
                        }
                        // tìm giá trị max  
                        // cập nhật ngoài if để tránh TH a[n-1]
                        // thì cnt sẽ không đc cập nhật
                        res = max(res,cnt)
                    }
                }
```

### **Ý c:** Tìm dãy con liên tiếp có 2 phần tử liền kề nhau trái dấu có độ dài dài nhất.

| Input | Output |
| :--- | :--- |
| 10<br>1 2 3 -4 4 5 -2 1 -3 | 2 |

**Code**
```cpp
                int max(int a, int b){
                    return a < b ? b : a;
                }
                int check(int n, int a[]){
                    int res = 0, cnt = 1;
                    // duyệt từ a[1] vì phần tử đầu tiên luôn đúng 
                    // check xem số trc có khác không 
                    for(int i=1;i<n;i++){
                        if(a[i]*a[i-1]<0){
                            // nhân với nhau < 0 thì trái dấu, tăng biến cnt
                            ++cnt;
                        }else {
                            // không thì Gán lại cnt, đếm lại 
                            cnt = 1;
                        }
                        // tìm giá trị max  
                        // cập nhật ngoài if để tránh TH a[n-1]
                        // thì cnt sẽ không đc cập nhật
                        res = max(res,cnt)
                    }
                }
```

### **Ý d:** Tìm dãy con tăng liên tiếp có độ dài dài nhất.

| Input | Output |
| :--- | :--- |
| 10<br>1 2 3 3 3 4 5 2 1 -3 | 3 |

**Code**
```cpp
                    int max(int a, int b){
                        return a < b ? b : a;
                    }
                    int check(int n, int a[]){
                        int res = 0, cnt = 1;
                        // duyệt từ a[1] vì phần tử đầu tiên luôn đúng 
                        // check xem số trc có khác không 
                        for(int i=1;i<n;i++){
                            if(a[i]>a[i-1]){
                                // lớn hơn thì tăng biến cnt
                                ++cnt;
                            }else {
                                // không thì Gán lại cnt, đếm lại 
                                cnt = 1;
                            }
                            // tìm giá trị max  
                            // cập nhật ngoài if để tránh TH a[n-1]
                            // thì cnt sẽ không đc cập nhật
                            res = max(res,cnt)
                        }
                    }
```

### **Ý e:** In dãy con tăng liên tiếp có độ dài dài nhất, nếu có nhiều dãy cùng chiều dài hãy in ra dãy đầu tiên.

| Input | Output |
| :--- | :--- |
| 10<br>1 2 3 2 3 4 5 2 1 -3 | 2 3 4 5 |

**Code**
```cpp
                int check(int n, int a[]){
                    int res = 0, cnt = 1, idx;
                    // duyệt từ a[1] vì phần tử đầu tiên luôn đúng 
                    // check xem số trc có khác không 
                    for(int i=1;i<n;i++){
                        if(a[i]>a[i-1]){
                            // lớn hơn thì tăng biến cnt
                            ++cnt;
                        }else {
                            // không thì Gán lại cnt, đếm lại 
                            cnt = 1;
                        }
                        if(cnt > res){
                            res = cnt;
                            // idx là index của phần tử đầu tiên trong dãy con
                            // i -res +1 : sau khi tìm đc dãy con thì i đang trỏ phần tử cuối của dãy
                            // i - (res-1) để lùi về phần tử đầu tiên dãy
                            // lưu ý mảng bắt đâu từ 0 đến n-1
                            idx = i - (res - 1);
                        }
                    }
                    // In từ idx
                    for(int i =0;i<res;i++){
                        printf("%d ",a[i+idx]);
                    }
                }
```