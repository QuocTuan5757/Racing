#include<iostream>
#include<math.h>
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
    char direct;
    int lenght;
    bool isEnemy;
};
void initCar(Car*c, int startX, int startY, bool isEnemy ){
    c->lenght = 7;
    c->score = 0;
    c->pos.x = startX;
    c->pos.y = startY;
    c-> isEnemy = isEnemy;
    c->direct ='s';
    int x = c->pos.x;
    int y = c->pos.y;
    c->car[0] = {x, y};
    c->car[1] = {x-1, y};
    c->car[2] = {x+1,y};
    c->car[3] ={x-1,y-2};
    c->car[4] = {x+1, y-2};
    c->car[5] = {x, y-1};
    c->car[6] = {x, y-2}; 
}
string check( int width, int height, int i, int j, Car*c, Car*ec){
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
    for( int k = 0; k < ec->lenght; k++){
        if(ec->car[k].x == j && ec->car[k].y == i){     
            if(k == 0){
                return "V ";
            }
            if(k==1 || k == 2 || k==3 || k==4 ){
                   return "0 ";
            }
            if(k == 5||k == 6){
               return "H ";
            } 
        }
    }
    return "  ";
}
int randLanesE(){
    int lanes[5] = {2, 6, 10, 14, 18};
    return lanes[rand()%5];

}
void border(int width, int height, Car*c, Car*ec){
   for (int i = 0; i < height; i++) {
        for (int j = 0; j < width ; j++) {
            // Sửa thành == ở cả 2 vế
            string prt = check(width, height, i, j, c, ec);
            cout<< prt;
        }
        cout << endl;
    }
}
void move(Car*ec){
    if(ec -> direct == 's'){
        ec->pos.y++;
    }
    initCar(ec, ec->pos.x, ec->pos.y+1, true );

}
int main(){
    srand(time(0));
    int width = 21;
    int height = 14;
    Car c;
    Car ec;
    initCar(&c, 10, 12, false );   
    initCar(&ec, randLanesE(), 3, true );  
    while(true){
        system("cls");
        border(width, height, &c, &ec);
        move(&ec);
        Sleep(150);
    }
    system("pause");
    return 0;
}