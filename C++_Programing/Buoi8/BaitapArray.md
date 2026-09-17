# Bài tập mảng 1 chiều 

## Bài 1: Sắp đặt dãy số

Cho mảng $A[]$ gồm $n$ phần tử. Nhiệm vụ của bạn là hãy sắp đặt lại các phần tử của mảng sao cho $A[i] = i$. Nếu phần tử $A[j]$ có giá trị khác $j$, hãy ghi vào $-1$. 

Ví dụ với mảng $A[] = \{-1, -1, 6, 1, 9, 3, 2, -1, 4, -1\}$ ta có kết quả $A[] = \{-1, 1, 2, 3, 4, -1, 6, -1, -1, 9\}$.

### Input
- Dòng đầu tiên đưa vào số lượng bộ test $T$.
- Những dòng kế tiếp đưa vào $T$ bộ test. Mỗi bộ test gồm hai dòng:
  - Dòng đầu tiên đưa vào $n$ là số phần tử của mảng $A[]$.
  - Dòng kế tiếp đưa vào $n$ số $A[i]$ của mảng, các số được viết cách nhau một vài khoảng trống.
- Ràng buộc: $1 \le T \le 100$; $1 \le n \le 10^7$; $-10^{18} \le A[i] \le 10^{18}$.

### Output
- Đưa ra kết quả mỗi test theo từng dòng.

### Ví dụ
| Input | Output |
| :--- | :--- |
| 2<br>10<br>-1 -1 6 1 9 3 2 -1 4 -1<br>6<br>0 -3 1 -2 3 -4 | -1 1 2 3 4 -1 6 -1 -1 9<br>0 1 -1 3 -1 -1 |

