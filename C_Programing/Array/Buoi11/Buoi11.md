# Bài tập Mảng 1 Chiều - Buổi 11

## Bài 19. Số lặp đầu tiên
Cho mảng các số nguyên. Tìm phần tử lặp đầu tiên trong mảng.

**Input**
Dòng đầu tiên là số lượng test case. T (1≤T≤100).
Mỗi test case bao gồm 2 dòng :
- Dòng đầu tiên là số lượng phần tử trong mảng n. (1≤n≤10000).
- Dòng thứ 2 là các phần tử ai trong mảng . (0≤ai≤10^6).

**Output**
In ra số đầu tiên lặp, nếu không có phần tử nào bị lặp in ra -1.

**Ví dụ**

| Input | Output |
|---|---|
| 2<br>5<br>1 2 3 2 1<br>5<br>1 2 3 4 5 | 2<br>-1 |

**Code**
```cpp
            // Khỏi tạo mảng đếm
            int cnt[1000001] = {0};
            int main(){
                int t;
                scanf("%d",&t);
                while(t--){
                    int n;
                    scanf("%d",&n);
                    int a[n];
                    // nhập mảng 
                    for(int i=0;i<n;i++){
                        scanf("%d",&a[i]);
                    }
                    int ok = 0;
                    for(int i=0;i<n;i++){
                        // xuất hiện lần 2 thì tần suất 1 rồi 
                        // Cứ in các phần tử ấy ra
                        if(cnt[a[i]] == 1){
                            printf("%d\n",a[i]);
                            ok = 1;
                            break;
                        }
                        // đánh dấu các số xuất hiện lần 1
                        cnt[a[i]] = 1;
                    }
                    if(!ok) printf("-1\n");
                    // reset mảng đếm chỉ cho các phần tử đã xuất hiện
                    for(int i=0;i<n;i++){
                        cnt[a[i]] = 0;
                    }
                }
            }
```