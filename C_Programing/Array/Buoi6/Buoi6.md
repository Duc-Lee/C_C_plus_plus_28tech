# Bài tập Mảng 1 Chiều - Buổi 6

## Bài 9. Dãy tăng

Một đoạn tăng trong một dãy số nguyên là một đoạn liên tiếp trong dãy sao cho phần tử phía sau lớn hơn phần tử phía trước. Cho dãy số với n phần tử (n không quá 100, các phần tử đều không quá 1000). Viết chương trình tìm các đoạn tăng liên tiếp trong dãy mà số phần tử là nhiều nhất.

**Input:** Dòng đầu ghi số bộ test. Mỗi test gồm 2 dòng, dòng đầu ghi số N là số phần tử của dãy. Dòng sau ghi N số của dãy. N không quá 100, các số trong dãy đều nguyên dương và không quá 1000.

**Output:** Với mỗi bộ test, ghi ra thứ tự bộ test. Sau đó là 1 dòng ghi độ dài của đoạn tăng dài nhất. Tiếp theo là một số dòng ghi lần lượt các đoạn tăng dài nhất, từ trái qua phải trong dãy ban đầu.

**Ví dụ:**

| Input | Output |
|---|---|
| 2<br>16<br>2 3 5 7 4 5 8 9 7 11 8 9 6 7 10 12<br>12<br>2 3 2 3 2 3 2 2 2 3 4 1 | Test 1:<br>4<br>2 3 5 7<br>4 5 8 9<br>6 7 10 12<br>Test 2:<br>3<br>2 3 4 |

**Code**
```cpp
                    int max(int a, int b){
                        return a < b ? b : a;
                    }

                    int main(){
                        // nhập test case
                        int t;
                        scanf("%d",&t);
                        for(int k = 1;k<=t;k++){
                            int n;
                            scanf("%d",&n);
                            int a[n];
                            // nhập mảng 
                            for(int i =0;i<n;i++){
                                scanf("%d",&a[i]);
                            }
                            printf("Test %d:\n",k);
                            // Biến tính độ dài của mảng con dài nhất
                            int res = 0; 
                            int dem = 1;
                            // khởi tạo mảng lưu index
                            int b[n], idx = 0;
                            for(int i =1;i<n;i++){
                                // nếu mảng tăng thì tăng biến đếm
                                if(a[i]>a[i-1]) ++dem;
                                // nếu không thì gán lại biến 
                                else dem = 1;
                                if(dem > res){
                                    // lưu kỉ lục 
                                    res = dem;
                                    // lưu index bđ của dãy con đầu tiên 
                                    b[0] = i - res +1;
                                    idx = 1; 
                                // Trường hợp cùng bằng thì lưu index mảng con thứ 2
                                }else if (dem == res){
                                    // index bắt đầu mảng con thứ tiếp theo
                                    b[idx] = i - res + 1;
                                    idx++;
                                }
                                // in kết quả ra 
                                printf("%d\n",res);
                                // In các mảng con 
                                for(int i =0;i<idx;i++){
                                    // mỗi mảng con có cùng chiều dài res
                                    for(int j = 0;j<res;j++){
                                        // b[i] = index bắt đầu mảng con 
                                        printf("%d ",a[ b[i] + j]);
                                    }
                                    printf("\n");
                                }
                            }
                        }
                    }        
```
