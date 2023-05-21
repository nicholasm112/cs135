// Nicholas Morgan
// Lab Quiz 9
// 4/3/23

if (((row%2 == 0) && (col%2 == 0)) || ((row%2 == 1) && (col % 2 == 1))){
    out[row][col] = 0;
}
else 
    out[row][col] = img[row][col];