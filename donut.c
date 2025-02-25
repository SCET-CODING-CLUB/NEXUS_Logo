#include<stdio.h>
#include<math.h>
#include<string.h>

#define HEIGHT 20
#define WIDTH  40
#define C_X (WIDTH/2)
#define C_Y (HEIGHT/2)
#define K 3.0

/*
    ->simply put, our axes in a computer are different then in math
      so its starts from top-right corner(origin),
    ->k is a  perspective constant
      fancy word for depth of field(perceived)
    ->it doesn't need to be 3.0 
      1.0 =big & close;
      5.0 =small & far;
    */

void clr(char buffer [HEIGHT][WIDTH]){
    for(int i=0;i<HEIGHT;i++){
        memset(buffer[i], ' ', WIDTH);
    }
}
 /*
 we CAN use clrscr() from conio.h but memset is better,
 cleaner & gives more refined output
 and escape code clearing screen is already there
 */

void display(char buffer[HEIGHT][WIDTH]){;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            putchar(buffer[i][j]);
        }
        putchar('\n');
    }
}
/*
goes row by row and puts chars on the array we made in clr
*/



int main(void){
    
}



