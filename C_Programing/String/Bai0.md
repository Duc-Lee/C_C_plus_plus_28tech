# Bài 0 - Lý thuyết về String ( Mảng xâu kí tự)

## I - Khai báo Mảng kí tự 
- Khi làm việc với String thì chúng ta sẽ khai báo các thư viện giúp xử lí các bài toán về String

```cpp
            #include <ctype.h>
            #include <string.h>
            #include <stdlib.h>
```

- Bản chất String cũng như là một Array, có kiểu dữ liệu mỗi phần tử là `char`

```cpp
            // Khai báo mảng kí tự một chiều
            // Khởi tạo tĩnh
            char a[100] = "Le Anh Duc";
            // Khởi tạo kiểu liệu kê từng kí tự 
            char b[100] = {'a','b','c','d'};

```

- Ví dụ xét mảng kí tự `char a[100] = "Le Anh Duc"` thì trong bộ nhớ (memory) sẽ lưu các phần tử như sau, cùng với index

| Phần tử | 'L' | 'e' | ' ' | 'A' | 'n' | 'h' | ' ' | 'D' | 'u' | 'c' | '\0' |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| Index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |

- Lưu ý : 
    - Khoảnh cách vẫn được tính là một kí tự và có giá trị ASCII riêng bằng 32
    - Kí tự kết thúc xâu là `\0` ( Null terminating ) có nghĩa là kết thúc xâu 
    - Đặc tả của xâu kí tự là `%s`  
    - Đặc tả của một kí tự là `%c`  

```cpp
            char c[100] = "Dien tu vien thong";
            // In ra man hinh xau ki tu 
            printf("%s",c);
```

## II. Một số hàm có sẵn trong Xâu kí tự 

### 1. Hàm `strlen()`
- Hàm `strlen()` là hàm đếm số kí tự trong một xâu kí tự, hàm trả về giá trị số `int` là độ dài của xâu ( chưa tính kí tự `\0` )

```cpp
            char c[100] = "Dientuvienthong";
            int len = strlen(c);
            printf("%d",len);
            // Ket qua : 17
            // Duyet xâu kí tự 
            for(int i =0;i < strlen(c); i++){
                printf("%c ",c[i]);
            }
            // Ket qua : 
            // D i e n t u v i e n t h o n g
```

### 2. Nhập từ bàn phím khai báo string 
- Sử dụng hàm `scanf()`

```cpp
            char c[100];
            // Lưu ý dùng đặc tả %s
            // Không cần &c[] do bản thân xâu đã là một con trỏ rồi 
            scanf("%s",c);
            printf("%s",c);
```

- Lưu ý : Hàm `scanf()` sẽ dừng lại khi gặp các dấu như dấu cách, tab, xuống dòng

```cpp
            char c[100];
            scanf("%s",c);
            // Ví dụ ta nhập "Le Anh Duc" vào thì sẽ chỉ nhận được "Le"
```

- Trong trường hợp muốn nhập cả dấu cách, ta sử dụng hàm `gets()`, hàm `gets()` sẽ dừng nhập khi gặp dấu xuống dòng `\n`

```cpp
            char c[100];
            gets(c);
            // Ví dụ ta nhập "Le Anh Duc" vào thì sẽ nhận được "Le Anh Duc" 
```

- Ví dụ ta nhập mảng xâu có 10 kí tự nhưng ta nhập xâu là " FIL research group" thì sẽ nhận được " FIL reserch" do khi `scanf` gặp dấu ` ` thì nó sẽ dừng lại 

- Tuy nhiên, còn một vấn đề nữa mà `scanf` sẽ không làm như `gets` đó là `scanf` không thêm kí tự `\0` vào sau khi nhập, dẫn đến trường hợp mảng xâu bị tràn bộ nhớ nếu xâu nhập vào lớn hơn kích thước mảng 

```cpp
            char c[100];
            // chỉ cho phép nhập 100 kí tự bằng %100s
            scanf("%100s",c);
            // Ví dụ ta nhập "Le Anh Duc" vào thì sẽ nhận được "Le Anh Duc\0" 
```

- Ví dụ cho một mảng xâu kí tự có không quá 10000 kí tự thì ta nên khai báo là `char a[10005]`

- Nếu trong bộ nhớ đệm có chứa phím enter (\0) thì hàm `gets()` sẽ dừng. Ví dụ : 
```cpp
            int x;
            // Nhập số xong bấm enter thì '\n' sẽ nằm trong bộ nhớ đệm 
            scanf("%d",&x);
            char c[1000];
            // Hàm gets() sẽ đọc luôn kí tự '\n' và dừng 
            gets(c);
            // Kết quả : 
            // 5 
            // [Enter]
            // [Enter]
```

- Để khắc phục điều này thì ta sẽ sử dụng hàm `getchar()`, hàm `getchar()` sẽ đọc và bỏ kí tự trong bộ nhớ đệm. 
```cpp

            int x;
            // Nhập số xong bấm enter thì '\n' sẽ nằm trong bộ nhớ đệm 
            scanf("%d",&x);
            // Hàm getchar() sẽ đọc và bỏ kí tự '\n' trong bộ nhớ đệm 
            getchar();
            char c[1000];
            // Hàm gets() sẽ đọc luôn kí tự '\n' và dừng 
            gets(c);
            // Kết quả : 
            // 5 
            // Le Anh Duc
```

- Hoặc ta cũng có thể dùng phương pháp 
```cpp
 int x;
            // Nhập số xong bấm enter thì '\n' sẽ nằm trong bộ nhớ đệm 
            scanf("%d",&x);
            // Bỏ qua kí tự '\n' trong bộ nhớ đệm bằng cách yêu cầu nhập kí tự '\n' 
            // hàm scanf sẽ yêu cầu nhập 1 kí tự '\n' vào và bỏ qua nó 
            scanf("\n");
            char c[1000];
            // Hàm gets() sẽ đọc luôn kí tự '\n' và dừng 
            gets(c);
            // Kết quả : 
            // 5 
            // Le Anh Duc
```

- Chú ý : 
    - Hàm `scanf()` để lại phím `\n` trong bộ nhớ đệm
    - Hàm `gets()` không để lại `\n` trong bộ nhớ đệm, nên không cần `getchar()` hay `scanf("\n")` để xử lí 

- Hàm `fflush(stdin)` dùng để xoá bộ nhớ đệm, nhưng hàm này dùng rất nguy hiểm trong một số trường hợp, nên hạn chế sử dụng 

### 3. Hàm `fgets()`

```cpp
            char c[10];
            gets(c);
            // Nếu ta nhập "Le Anh Minh Quan " vào thì sẽ gây ra lỗi tràn bộ nhớ ( buffer overflow )
            // Kết quả không mong muốn 
            printf("%s",c);
```
- Hàm `fgets()` là hàm đọc xâu kí tự, khác với hàm `gets()` là hàm không thể giới hạn độ dài xâu kí tự, hàm `fgets()` sẽ giới hạn độ dài xâu kí tự 

```cpp
            char c[1000];
            fgets(c,1000,stdin);
            printf("%s",c);
```

- Hàm `fgets` có 3 tham số :
    - Tham số thứ nhất : là mảng xâu kí tự cần nhập `c`
    - Tham số thứ hai : là số kí tự tối đa sẽ được nhập vào mảng, kể cả kí tự `\0`, vì nếu ta nhập vào `k` kí tự thì mảng sẽ có `k+1` phần tử 
    - Tham số thứ ba : là địa chỉ của luồng input ( input stream ), với bài toán nhập từ bàn phím ta sẽ dùng `stdin`
    - Ví dụ : nếu ta khai báo `char c[1000]` thì ta chỉ có thể nhập tối đa `999` kí tự 
  
- Hàm `fgets()` dừng khi gặp : 
    - Kí tự xuống dòng `\n`
    - Khi đã đọc đủ `n-1` kí tự 

- Sau chuỗi kí tự, sẽ có kí tự `null` 
```cpp
            char c[10] = "Nguyen van nam";
            printf("%s",c[strlen(c)]);
            // Ket qua : 0
            printf("%c",c[strlen(c)]);
            // Ket qua : 
            // Không in ra kí tự null 
            // Ket thuc xau 
            c[6] = '\0';
            printf("%s",c);
            // Ket qua : Nguyen 
```

- Hàm `fgets()` sẽ để lại kí tự `\n` trong bộ nhớ đệm, để khắc phục ta sẽ dùng như sau : 
```cpp
            char c[1000];
            fgets(c,1000,stdin);
            // Xoá kí tự '\n' trong bộ nhớ đệm 
            c[strlen(c)-1] = '\0';
            printf("%s",c);
```

### III - Xâu kí tự 2 chiều 

- Xâu kí tự 2 chiều thực chất là mảng các xâu kí tự 
- Ví dụ : 
```cpp
            char c[100][100];
            // Khai báo mảng xâu kí tự có 100 xâu , mỗi xâu có tối đa 100 kí tự  
            // Hay còn gọi là một mảng các chuỗi kí tự 
            char name[3][30] = {"Nguyen Van A","Tran Thi B","Le Van C"};
            // Khai báo mảng xâu kí tự có 3 xâu , mỗi xâu có tối đa 30 kí tự 
            // In ra các phần tử 
            for (int i =0;i<3;i++){
                printf("%s\n",name[i]);
            }
            // Ket qua :
            // Nguyen Van A 
            // Tran Thi B 
            // Le Van C 
            // Thao tác với 2 chiều 
            printf("%c",name[0][0]);
            // In ra kí tự đầu tiên của xâu đầu tiên 
```