#include<stdio.h>
#include<math.h>
#include<string.h>

#define HEIGHT 20
#define WIDTH  40
#define SCALE  15
#define C_X (WIDTH/2)
#define C_Y (HEIGHT/2)
#define K 1.0

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
        {1,2,3},
        {2,1,3},
        {2,2,3}
    };    
    /*visualization by gpt:
           (x, y, z) coordinates

       (1,2,3)   (2,2,3)
         *--------*
         |        |
         |        |
         *--------*
       (1,1,3)   (2,1,3)

    */


     //simply project each point & place in buffer
    for (int i=0;i<4;i++){
        float x = points[i][0];
        float y = points[i][1];
        float z = points[i][2];

        float D = 1 / (z + K);
        int x2D = (int)(x * D * SCALE);
        int y2D = (int)(y * D * SCALE);

        int xScreen = C_X + x2D;
        int yScreen = C_Y - y2D;

        //debugging 101
        /*printf("x: %.2f, y: %.2f, z: %.2f -> x2D: %d, y2D: %d -> xScreen: %d, yScreen: %d\n",
            x, y, z, x2D, y2D, xScreen, yScreen);*/
     

        if (xScreen >= 0 && xScreen < WIDTH && yScreen >= 0 && yScreen < HEIGHT) {
            buffer[yScreen][xScreen] = 'N';
        }
    }
    
    display(buffer);
    
    return 0;
}



