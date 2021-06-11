#include <iostream>
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