### Hướng dẫn sử dụng
Dùng câu lệnh `cd` tới thư mục release có file `main`. Chạy các câu lệnh trên terminal:
- Vẽ đường thẳng bằng thuật toán DDA: `./main 0 x1 y1 x2 y2`
- Vẽ đường thẳng bằng thuật toán Bresenham: `./main 1 x1 y1 x2 y2`
- Vẽ đường tròn bằng thuật toán Midpoint: `./main 2 x y r`
- Vẽ đường elip bằng thuật toán Midpoint: `./main 3 x y a b`
- Vẽ đường parabol bằng thuật toán Midpoint: `./main 4 x y a b`
- Vẽ đường hyperbol bằng thuật toán Midpoint: `./main 5 x y a b`

Chương trình sẽ in ra 2 dòng. 
- Dòng thứ 1 là thời gian chạy (ms) cho thuật toán tự code. 
- Dòng thứ 2 là thời gian chạy (ms) cho thư viện OpenGL.
