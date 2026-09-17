## Bài 42. Trộn xâu - SPOJ/P178PROG

Cho hai xâu ký tự S1 và S2 với độ dài N và chỉ chứa các ký tự từ A đến H. Chúng ta thực hiện thao tác như sau:

- Bước đầu tiên tạo S12 bằng cách lấy các ký tự lần lượt trong S1 và S2 từ trái sang phải, lấy một ký tự trong S2 trước, sau đó đến 1 ký tự trong S1 và cứ như vậy. Ví dụ S1 = ABCHAD, S2 = DEFDAC thì S12 = DAEBFCDHAACD
- Sau đó ta lại lấy nửa bên trái của S12 thành S1 mới, nửa bên phải thành S2 mới. Trong ví dụ trên S1 mới là DAEBFC, S2 mới là DHAACD. Rồi lại tiếp tục như vậy trong các bước tiếp theo.

Cho trước một xâu S có độ dài 2*N. Bài toán đặt ra là liệu có thể tạo ra xâu S sau một số lần lặp hay không.

**Dữ liệu vào**

Có nhiều bộ test, mỗi bộ test có bốn dòng. Dòng đầu ghi số N không quá 200. Dòng thứ 2 ghi S1, dòng thứ 3 ghi S2. Dòng cuối ghi xâu S. Input kết thúc với một dòng ghi số 0.

**Kết quả**

Ghi ra số bước lặp cần thiết. Nếu không thể tìm được thì ghi ra -1.

**Ví dụ**
**Input**
```text
4
AHAH
HAHA
HHAAAAHH
3
CDE
CDE
EEDDCC
0
```

**Output**
```text
2
-1
```

**Code**
```cpp
                        #include <stdio.h>
                        #include <string.h>
                        #include <stdlib.h>
                        #include <ctype.h>
                        
                        // tron 2 xau 
                        void tron(char s1[], char s2[], char s12[], int n){
                            int j = 0;
                            for(int i = 0;i < n ;i++){
                                // trộn s2 s1 vô xâu s12
                                s12[j++] = s2[i];
                                s12[j++] = s1[i];
                            }
                            // cho cuối là kí tự null 
                            // đánh dấu kết thúc xâu 
                            s12[j] = '\0';
                        }
                        void tach(char s1[], char s2[], char s12[], int n){
                            // nửa bên trái thu đc s2 mới
                            // nửa còn lại thu đc s1 mới
                            int j = 0;
                            for(int i = 0;i<n;i++) s2[i] = s12[j++];
                            for(int i = 0;i<n;i++) s1[i] = s12[j++];
                        }
                        // hàm tính toán xem 
                        // có biến đổi xâu trở về như ban đầu không 
                        int solve(){
                            int n;
                            scanf("%d",&n);
                            // khai báo xâu s12 có 2*n thưa 5 để cho thoải mái
                            char s1[n], s2[n], s12[2*n + 5], tmp[2*n +5];
                            scanf("%s%s%s",s1,s2,s12);
                            // khai báo biến đếm 
                            int cnt = 0;
                            // khai báo mảng nhớ tạm 
                            // do truyền vô con trỏ mảng nên sẽ thay đổi mảng ban đầu
                            int t1[n], t2[n];
                            strcpy(t1,s1);
                            strcpy(t2,s2);
                            while(1){
                                ++cnt; // tăng biến lặp 
                                // trộn 2 xâu 
                                tron(t1,t2,tmp,n);
                                // kiểm tra xem sau khi trộn có thu đc xâu theo yêu cầu không
                                if(strcmp(s12,tmp) == 0) return cnt;
                                // tách 2 xâu 
                                tach(t1,t2,tmp,n);
                                // sau khi tách xong 
                                // kiểm tra xem sau 1 bước nào đó
                                // xâu s1 và xâu s2 quay trở lại đúng giá trị ban đầu
                                // mà vẫn chưa đạt được yêu cầu 
                                // thì nó sẽ quay mãi lại như vậy
                                if(! strcmp(s1,t1) && !strcmp(s2,t2)) return -1;
                            }
                            return -1;
                        }

                        int main(){
                            while(1){
                                int n;
                                scanf("%d",&n);
                                if(n!=0){
                                    printf("%d\n",solve());
                                }
                                else break;
                            }
                            return 0;
                        }
```