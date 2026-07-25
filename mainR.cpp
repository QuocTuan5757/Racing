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
    Point car[7];
    int direct;
    int lenght;
};
void initCar(Car*c, int width, int height){

    c->lenght = 7;
    c->score = 0;
    c->pos.x = 10;
    c->pos.y = 12;
    int x = c->pos.x;
    int y = c->pos.y;
    c->car[0] = {x, y};
    c->car[1] = {x-1, y};
    c->car[2] = {x+1,y};
    c->car[3] ={x-1,y-2};
    c->car[4] = {x+1, y-2};
    c->car[5] = {x, y-1};
    c->car[6] = {x, y-2};
    
    c->direct = 'w';
}
string check( int width, int height, int i, int j, Car*c){
    if (i == 0 || i == height - 1 || j == 0 || j == 4|| j == 8|| j == 12||j==16|| j == width - 1) {
        return "+ ";
    }
    for( int k = 0; k < c->lenght; k++){
        if(c->car[k].x == j && c->car[k].y == i){
            if(k == 6){
                return "A ";
            }
            if(k==1 || k == 2 || k==3 || k==4 ){
                return "0 ";
            }
            if(k == 5||k == 0){
                return "H ";
            }
        }
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
    initCar(&c, width, height);   
    border(width, height, &c);
    
}