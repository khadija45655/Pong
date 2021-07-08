#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;
enum eDirection { STOP=0, LEFT=1, UPLEFT=2, DOWNLEFT=3, RIGHT=4, UPRIGHT=5, DOWNRIGHT=6};
class cBall{
    private:
        //used for storing the position of the ball on the screen
        int x;
        int y;

        //the original x and y coordinates
        int originX, originY;

        eDirection direction;
    public:
        cBall(int posX, int posY){
            //saves the original position of the ball
            originX = posX;
            originY = posY;

            //sets the current position of the ball
            x = posX;
            y = posY;
            direction = STOP;

        }
        //used to reset he position of he ball
        void Reset(){
            x = originX;
            y = originY;
            direction = STOP;
        }

        void changeDirection(eDirection d){
            direction = d;
        }
        //generates random numbers from 1 to 6 to change the direction randomly
        void randomDirection(){
            direction = (eDirection)((rand()%6)+1);
        }

        int getX(){
            return x;
        }
        int getY(){
            return y;
        }
        eDirection getDirection(){
            return direction;
        }

        //function for moving
        void Move(){
            switch(direction){
                case STOP:
                    break;
                case LEFT:
                    //reversed coordinate system
                    x--;
                    break;
                case RIGHT:
                    x++;
                    break;
                case UPLEFT:
                    x--; y--;
                    break;
                case DOWNLEFT:
                    x--; y++;
                    break;
                case UPRIGHT:
                    x++; y--;
                    break;
                case DOWNRIGHT:
                    x++; y++;
                    break;
                default:
                    break;
            }
        }

        //outputs the ball's location
        friend ostream & operator<<(ostream & o, cBall c){
            o << "Ball ("<<c.x<<","<<c.y<<")("<<c.direction<<")";
            return o;
        }

};
//the player
class cPaddle{
private: 
    int x,y;
    int originX, originY;
public:
    cPaddle(){
        x = y = 0;
    }
    cPaddle(int posX, int posY) : cPaddle(){
        originX = posX;
        originY = posY;
        x = posX;
        y = posY;
    }
    void Reset(){
        x = originX;
        y = originY;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    void moveUp(){
        y--;
    }
    void moveDown(){
        y++;
    }
    friend ostream & operator<<(ostream & o, cPaddle c){
        o << "Paddle ("<<c.x<<","<<c.y<<")";
        return o;
    }
};

class cGameManager{
    private:
        //defining the width and height of the level
        int width, height;

        //keeping track of scores
        int score1, score2;

        //defining the controls
        char up1, down1, up2, down2;

        bool quit;

        cBall * ball;
        cPaddle *player1;
        cPaddle *player2;

    public:
        cGameManager(int w, int h){

            srand(time(NULL));

            quit = false;

            up1 = 'w';
            up2 = 'i';
            down1 = 's';
            down2 = 'k';

            score1 = 0;
            score2 = 0;
            width = w;
            height = h;

            //places the ball in the middle of the screen
            ball = new cBall(w/2, h/2);

            player1 = new cPaddle(1,h/2-3);
            player2 = new cPaddle(w-2,h/2-3);

        }
        //Thanos snap
        ~cGameManager(){
            delete ball, player1, player2;
        }

        void scoreUp(cPaddle * player){
            if(player == player1){
                score1++;
            }
            else if (player == player2){
                score2++;
            }
            ball -> Reset();
            player1 -> Reset();
            player2 -> Reset();
        }

        void Draw() {
            //clears the screen
            system("cls");

            //print the walls of the game
            for (int i = 0; i < width + 2; i++) {
                cout << "#";
            }
            cout << endl;

            //i is y-coordinate
            for (int i = 0; i < height; i++) {
                //j is x-coordinate
                for (int j = 0; j < width; j++) {

                    int ballx = ball->getX();
                    int bally = ball->getY();

                    int player1x = player1->getX();
                    int player1y = player1->getY();

                    int player2x = player2->getX();
                    int player2y = player2->getY();

                    if (j == 0) {
                        cout << "#";
                    }

                    //Prints content of the map and position of where players and ball are
                    if (ballx == j && bally == i) {
                        //prints the ball
                        cout << "O";
                    }
                    else if (player1x == j && player1y = i) {
                        //prints player 1
                        cout << "/";
                    }

                    else if (player2x == j && player2y = i) {
                        //prints player 2
                        cout << "\";
                    }
                    
                    else {
                        cout << " ";
                    }

                    if (j == width - 1) {
                        cout << "#";
                    }
                }


            }

            for (int i = 0; i < width + 2; i++) {
                cout << "#";
            }
            cout << endl;

        }
};
int main(){

    cPaddle p1(0,0);
    cPaddle p2(10,0);
    cout<<p1<<endl;
    cout<<p2<<endl;
    p1.moveUp();
    p2.moveDown();
    cout<<p1<<endl;
    cout<<p2<<endl;

    return 0;
}