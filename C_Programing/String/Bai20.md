## Bài 27. Xâu kí tự đầy đủ

Một xâu kí tự được gọi là đầy đủ nếu xóa đi 0 hoặc 1 số kí tự trong xâu ta thu được xâu abcdefghijklmnopqrstuvwxyz.

Tìm số lượng kí tự cần chèn vào xâu để tạo được xâu đầy đủ

**Input:**

Xâu duy nhất chỉ chứa chữ cái in thường có không quá 100 kí tự

**Output:**

Số lượng kí tự cần chèn vào xâu để được xâu đầy đủ

**Ví dụ:**

| Input | Output |
| --- | --- |
| abczzzzzzzx | 22 |
| zyx | 25 |

** Code **
```cpp
                    #include <stdio.h>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <ctype.h>
                    
                    int lis_calc(char s[]){
                        int n = strlen(s);
                        // dp[i]: chiều dài dãy con đúng thứ tự bảng chữ cái dài nhất kết thúc tại vị trí i
                        int dp[n];
                        
                        for(int i = 0; i < n; i++){
                            dp[i] = 1; // Ban đầu mỗi kí tự tự tạo thành dãy con có độ dài 1
                            // Xét lại các kí tự đứng trước vị trí i
                            for(int j = 0; j < i; j++){
                                // Điều kiện 1: s[i] > s[j] (Kí tự sau phải đứng sau trong bảng chữ cái)
                                // Điều kiện 2: Ghép s[i] vào dãy kết thúc tại j sẽ tạo ra dãy dài hơn dp[i] hiện tại
                                if(s[i] > s[j] && dp[i] < dp[j] + 1){
                                    dp[i] = dp[j] + 1;
                                }
                            }
                        }
                        
                        // Tìm độ dài của dãy con dài nhất trong toàn bộ mảng dp
                        int max_len = 0;
                        for(int i = 0; i < n; i++){
                            if(dp[i] > max_len){
                                max_len = dp[i];
                            }
                        }
                        // Số kí tự cần chèn là 26 trừ đi chiều dài dãy con dài nhất đã có sẵn
                        return 26 - max_len;
                    }

                    int main(){
                        char s[1000];
                        gets(s); 
                        int res = lis_calc(s);
                        printf("%d", res);
                        return 0;
                    }
```

## Bài 28. Xếp đá

Có n viên đá trên bàn liên tiếp, mỗi viên có thể có màu đỏ, xanh lá cây hoặc xanh dương. Đếm số lượng đá tối thiểu cần lấy từ bàn để bất kỳ hai viên đá lân cận nào có màu khác nhau. Đá liên tiếp được coi là lân cận nếu không có đá khác giữa chúng.

**Input:**
Dòng đầu tiên chứa số nguyên n (1 <= n <= 50) - số lượng đá trên bàn.
Dòng tiếp theo chứa chuỗi s, đại diện cho màu sắc của đá. Chúng tôi sẽ xem xét các viên đá trong hàng được đánh số từ 1 đến n từ trái sang phải. Sau đó, ký tự thứ i bằng "R", nếu viên đá thứ i có màu đỏ, "G", nếu nó màu xanh lá cây và "B", nếu nó màu xanh.

**Output:**
In một số nguyên duy nhất - câu trả lời cho vấn đề.

**Ví dụ:**

| Input | Output |
| --- | --- |
| RRRR | 3 |

**Code**
```cpp
                    #include <string.h>
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <ctype.h>

                    int main(){
                        int n;
                        scanf("%d",&n);
                        char c[100];
                        scanf("%s",c);
                        int res = 0;
                        // duyệt tới n - 1 vì ta so sánh i và i + 1, nếu tới n - 1 thì i + 1 sẽ bằng n mà n là chỉ số cuối cùng
                        for(int i = 0; i < n - 1; i++){
                            if(c[i] == c[i+1]){
                                res++;
                            }
                        }
                        printf("%d", res);
                        return 0;
                    }


```