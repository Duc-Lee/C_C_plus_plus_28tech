# Bài 1. Các hàm xử lý chuỗi cơ bản
Xây dựng các hàm:

`int is_lower(char c)` : Kiểm tra 1 kí tự có phải là chữ in thường hay không. Nếu đúng trả về 1, sai trả về 0.

`int is_upper(char c)` : Kiểm tra 1 kí tự có phải là chữ in hoa hay không?

`int is_alphar(char c)` : Kiểm tra 1 kí tự có phải là chữ cái hay không?

`int is_digit(char c )` : Kiểm tra 1 kí tự có phải là kí tự hay không?

`char to_lower(char c )` : Trả về dạng in thường của kí tự c

`char to_upper(char c )` : Trả về dạng in hoa của kí tự c

`int strlen(char c )` : Trả về chiều dài xâu

`char* strlwr(char c[])` : Viết thường tất cả các kí tự trong xâu

`char* strupr(char c[])` : Viết hoa tất cả các kí tự trong xâu

`int strcmp(char a[], char b[])` : So sánh 2 xâu a và b theo thứ tự từ điển, nếu a>b trả về 1, a=b trả về 0, a < b trả về -1

`int strcmp(char a[], char b[])` : So sánh 2 xâu a và b theo thứ tự từ điển không phân biệt hoa thường, nếu a>b trả về 1, a=b trả về 0, a < b trả về -1

`long long atoll(char a[])` : Chuyển 1 xâu kí tự số thành số nguyên long long

`char* strrev(char c[])` : Viết hàm đảo ngược 1 xâu

## 1. Kiểm tra 1 kí tự có phải là chữ in thường hay không ?
```cpp
            int is_lower(char c){
                // cũng có thể kiểm tra nằm trong khoảng 
                // c >= 97 && c <= 122 ( ASCII )
                if(c >= 'a' && c <= 'z' )
                    return 1;
                return 0;
            }
```

## 2. Kiểm tra 1 kí tự có phải là chữ in hoa hay không ?
```cpp
            int is_upper(char c){
                // cũng có thể kiểm tra nằm trong khoảng 
                // c >= 65 && c <= 90 ( ASCII )
                if(c >= 'A' && c <= 'Z' ){
                    return 1;
                }
                return 0;
            }
```

## 3. Kiểm tra 1 kí tự có phải là chữ cái hay không ?
```cpp
            int is_alpha(char c){
                // kí tự sẽ là chữ in thường hoặc chữ in hoa
                if(( c >= 65 && c <= 90) || (c >= 97 && c <= 122)){
                    return 1;
                } 
                return 0;
            }
```

## 4. Kiểm tra 1 kí tự có phải là chữ số hay không ?
```cpp
            int is_digit(char c ){
                if(c >= '0' && c <= '9' ){
                    return 1;
                }
                return 0;
            }
```

## 5. Trả về dạng in thường của kí tự c
```cpp
            char to_lower(char c){
                // kiểm tra kí tự c có phải in hoa hay không ? 
                if(c >= "A" && c <= "Z"){
                    // đổi chữ in hoa thành chữ thường 
                    // bằng cách cộng 32 vào ASCII 
                    c += 32;             
                }
                // không phải thì không thay đổi gì
                return c;
            }
```

## 6. Trả về dạng in hoa của kí tự c
```cpp
            char to_upper(char c ){
                // kiểm tra kí tự c có phải chữ in thường hay không ? 
                if(c >= 'a' && c <= 'z'){
                    // đổi chữ in thường thành chữ in hoa 
                    // bằng cách trừ 32 vào ASCII 
                    c -= 32;            
                }
                return c;
            }
```

## 7. Trả về chiều dài xâu
```cpp
            int strlen(char c){
                int cnt = 0;
                // lưu ý : cuối xâu là kí tự null
                while(c[cnt] != '\0'){
                    ++cnt;
                }
                return cnt;
            }
```

## 8. Viết thường tất cả các kí tự trong xâu
```cpp
            // Hàm con trỏ này truy cập vào mảng xâu để thay đổi giá trị 
            // nếu không cấp con trỏ thì hàm sẽ lỗi
            char *strlwr(char c[]){
                for(int i =0;i< strlen(c);i++){
                    // nếu kí tự c[i] là chữ hoa
                    if(c[i] >= 'A' && c[i] <= 'Z'){
                        c[i] += 32;
                    }
                }
                return c
            }      
```

## 9. Viết hoa tất cả các kí tự trong xâu
```cpp
            char *strupr(char c[]){
                for(int i = 0; i < strlen(c); i++){
                    // nếu kí tự c[i] là chữ thường
                    if(c[i] >= 'a' && c[i] <= 'z'){
                        c[i] -= 32;
                    }
                }
                return c;
            }    
```

## 10. So sánh 2 xâu a và b theo thứ tự từ điển, nếu a>b trả về 1, a=b trả về 0, a < b trả về -1
```cpp
            // Hàm này đã có sẵn rồi 
            int strcmp(char a[], char b[]){
                int n1 = strlen(a);
                int n2 = strlen(b);
                // so sánh từng kí tự cùng index 
                for(int i =0;i < min(n1,n2);i++){
                    if(a[i]!b[i]){
                        // kiểm tra xem có lơn hơn hay nhỏ hơn
                        if(a[i] > b[i]) return 1;
                        else return -1;
                    }
                }  
                // kiểm tra các trường hợp về độ dài sâu
                if (n1 == n2)
                    return 0;
                else if (n1 > n2) return 1;
                else return -1;             
            }   
```

## 11. So sánh 2 xâu a và b theo thứ tự từ điển không phân biệt hoa thường
```cpp
            // Hàm này đã có sẵn rồi 
            int strcmp(char a[], char b[]){
                int n1 = strlen(a);
                int n2 = strlen(b);
                // chuyển hết 2 xâu về dạng in thường 
                strlwr(a);
                strlwr(b);
                // so sánh từng kí tự cùng index 
                for(int i =0;i < min(n1,n2);i++){
                    if(a[i]!b[i]){
                        // kiểm tra xem có lơn hơn hay nhỏ hơn
                        if(a[i] > b[i]) return 1;
                        else return -1;
                    }
                }  
                // kiểm tra các trường hợp về độ dài sâu
                if (n1 == n2)
                    return 0;
                else if (n1 > n2) return 1;
                else return -1;             
            }       
```

## 12. Chuyển 1 xâu kí tự số thành số nguyên long long
```cpp
            long long atoll(char c[]){
                long long res = 0;
                for(int i =0;i< strlen(c);i++){
                    // chuyển kí tự về số 
                    // lưu ý c[i] - '0' là lấy giá trị ASCII - kí tự đầu tiên, tức là đang lấy số
                    res = res * 10 + c[i] -'0';
                }
                return res;
            }
```

## 13. Viết hàm đảo ngược 1 xâu
```cpp
            char* strrev(char c[]){
                int l =0, r = strlen(c) - 1;
                while(l < r){
                    // swap giá trị index
                    char tmp = c[l];
                    c[l] = c[r];
                    c[r] = tmp;
                    // tăng giảm giá trị index
                    l++;
                    r--;
                }
                return c;
            }             
```
- **Lưu ý đối với hàm trả về con trỏ (`char *`)**: Khi viết hàm trả về một chuỗi, bạn phải truyền mảng (hoặc con trỏ) từ bên ngoài vào làm tham số, thao tác trên đó rồi trả về chính nó. Tuyệt đối không được khai báo mảng cục bộ bên trong hàm rồi trả về địa chỉ của mảng đó, vì vùng nhớ của biến cục bộ sẽ bị giải phóng khi hàm kết thúc, gây ra lỗi chương trình (Undefined Behavior).