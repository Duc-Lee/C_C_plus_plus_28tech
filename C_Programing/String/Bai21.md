## Bài 29. Hello

Vasya gần đây đã học cách gõ và đăng nhập vào Internet. Anh lập tức bước vào một phòng chat và quyết định nói xin chào với mọi người. Vasya gõ từ s. Vasya được coi là nói xin chào nếu một vài chữ cái có thể bị xóa khỏi từ đã gõ để nó dẫn đến từ "hello". Ví dụ: nếu Vasya gõ từ "ahhellllloou", anh ta sẽ nói rằng anh ta nói xin chào, và nếu anh ta gõ "hlelo", sẽ bị coi là Vasya bị hiểu lầm và anh ta không thể nói xin chào. Xác định xem Vasya có thể nói xin chào bằng từ đã cho không.

**Input:**

Dòng đầu tiên và duy nhất chứa từ s, mà Vasya đã gõ. Từ này liên quan đến các chữ cái Latinh viết thường, độ dài của nó không dưới 1 và không quá 100 chữ cái.

**Output:**

Nếu Vasya có thể nói xin chào, hãy in "YES", nếu không thì in "NO".

**Ví dụ:**

| Input | Output |
| --- | --- |
| ahhellllloou | YES |

**Code**
```cpp
                    #include <string.h>
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <ctype.h>

                    int solve(char c[]){
                        // khoi tao mang 'hello'
                        char d[5] = {'h','e','l','l','o'};
                        // dem index của xâu hello
                        int cnt = 0;
                        for(int i = 0;i < strlen(s);i++){
                            // so sanh trace
                            if(c[i] == d[cnt]){
                                ++cnt;
                            }
                            if(cnt==5) return 1; // đủ đki tạo xâu hello
                        }
                        // không đủ điều kiện 
                        return 0;
                    }
                    int main(){
                        char s[1000];
                        scanf("%s", s);
                        if(solve(s)) printf("YES");
                        else printf("NO");
                        return 0;
                    }
```

---

## Bài 30.1303A Codeforces

Bạn được cung cấp một chuỗi s. Mỗi ký tự là 0 hoặc 1.

Bạn muốn tất cả các số 1 trong chuỗi tạo thành một phân đoạn liền kề. Ví dụ: nếu chuỗi là 0, 1, 00111 hoặc 01111100, thì tất cả 1 đều tạo thành một phân đoạn liền kề và nếu chuỗi là 0101, 100001 hoặc 11111111111101, thì điều kiện này không được đáp ứng.

Bạn có thể xóa một số (có thể không) 0 khỏi chuỗi. Số 0 tối thiểu mà bạn phải xóa là bao nhiêu?

**Input**

Dòng đầu tiên chứa một số nguyên t (1 ≤ t ≤ 100) - số lượng trường hợp kiểm tra.

Sau đó t dòng tiếp theo, mỗi dòng đại diện cho một trường hợp thử nghiệm. Mỗi dòng chứa một chuỗi s (1 ≤ |s| <= 100); mỗi ký tự của s là 0 hoặc 1.

**Output**

In số nguyên t, trong đó số nguyên thứ i là câu trả lời cho mẫu thử thứ i (số tối thiểu là 0 mà bạn phải xóa khỏi s).

**Ví dụ**

| Input | Output |
| --- | --- |
| 3<br>010011<br>0<br>1111000 | <br>2<br>0<br>0 |

**Code**
```cpp
                        #include <stdio.h>
                        #include <stdlib.h>
                        #include <string.h>
                        #include <ctype.h>
                        
                        int main(){
                            int t;
                            scanf("%d",&t);
                            while(t--){
                                char s[1000];
                                scanf("%s",s);
                                // khoi tao bien dem 
                                int idx = -1, cnt = 0;
                                for(int i =0;i<strlen(s);i++){
                                    // kiểm tra xem kí tự có phải số 1 ko?
                                    if(c[i] == '1'){
                                        // nếu idx == -1 thì cập nhật lại
                                        // idx chỉ số 1 đầu chuỗi
                                        if(idx == -1) idx = i;
                                        // nếu không tính số số 0 cần xoá
                                        else {
                                            // đếm số 0 cần xoá
                                            // số cuối trừ số đầu rồi -1 
                                            // theo cthuc khoảng [a,b] : b - a 
                                            res += i - idx - 1;
                                            idx = i;
                                        }
                                    }
                                }
                                printf("%d\n",res);
                            }
                        }
```