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
    char buffer[HEIGHT][WIDTH];
    clr(buffer);
     //our 3D points
    float points[4][3]= {
        {1,1,3},
        {2,2,3},
        {3,3,3},
        {4,4,3}
    };
     //simply project each point & place in buffer
    for (int i=0;i<4;i++){
        float x = points[i][0];
        float y = points[i][1];
        float z = points[i][2];

        float D = 1 / (z + K);
        int x2D = (int)(x * D * 10);
        int y2D = (int)(y * D * 10);

        int xScreen = C_X + x2D;
        int yScreen = C_Y - y2D;

        if (xScreen >= 0 && xScreen < WIDTH && yScreen >= 0 && yScreen < HEIGHT) {
            buffer[yScreen][xScreen] = '*';
        }
    }
    
}



