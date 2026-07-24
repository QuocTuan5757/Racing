#include<iostream>
#include<conio.h>
#include<ctime>
#include<cstdlib>
#include<windows.h>

using namespace std;
struct Point{
    int x, y;
};
struct Car{
    int score;
    Point pos;
    int car[9];
    int direct;
};
void initCar(Car*c, int width, int height){
    c->score = 0;
    c->pos.x = 12;
    c->pos.y = 11;
    c->car[0].x = x;
    c->car[0].y = y;
    c->car[1].x = x-1;
    c->car[1].y = y;
    c->car[2].x = x+1;
    c->car[2].y = y;
    c->car[3].x = x-1;
    c->car[3].y = y+2;
    c->car[4].x = x+1;
    c->car[4].y = y+2;
    c->direct = 'w';
}
string check( int width, int height, int i, int j, Car*c){
    if (i == 0 || i == height - 1 || j == 0 || j == 4|| j == 8|| j == 12||j==16|| j == width - 1) {
        return "+ ";
    }
    if(c->car[0].x == j && c->car[0].y == i){
        
    }

    return "  ";
}
void border(int width, int height, Car*c){
   for (int i = 0; i < height; i++) {
        for (int j = 0; j < width ; j++) {
            // Sửa thành == ở cả 2 vế
            string prt = check(width, height, i, j, c);
            cout<< prt;
        }
        cout << endl;
    }

}
int main(){
    int width = 21;
    int height = 14;
    Car c;   
    border(width, height, &c);
}