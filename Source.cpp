#include <SFML/Graphics.hpp>
#include <iostream>


class Ball {

    float posY,posX;
    float val=0.1f;
    sf::CircleShape shape;

    public:
         void createBall(float ballPosX, float ballPosY) {
    
               posY = ballPosY;
               posX = ballPosX;
            

       
               shape.setRadius(7.f);
               shape.setFillColor(sf::Color().Red);
              shape.setPosition(ballPosX, ballPosY);
      


         }

         sf::CircleShape drawBall() {
    
             return shape;
    
         }



         void bounceBall() {
             
               if (shape.getPosition().y + 14.f > 720) {
                     val = -0.6f;
                     //val1 += 0.00006f;
                          /* flag = true;*/
                }

               val += 0.0006f;
               posY += val;
               shape.setPosition(posX, posY);
           
          }

};

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
   

    std::vector<Ball> shapes;
    float ballPosY = 0.f, ballPosX = 0.f;


    for (int i = 0; i < 1000; i++) {

        ballPosX = rand() % 1280 + 1;
        ballPosY = rand() % 720 + 1;

        Ball ball;
        ball.createBall(ballPosX, ballPosY);
        //sf::CircleShape ballShape = ball.createBall(ballPosX, ballPosY);
        
        
        shapes.push_back(ball);

    }



    //shape.setFillColor(sf::Color().Red);
    //shape.setPosition(1280/2, 720/2);
     float posX = 1280/2, posY = 720/2;
     float val = 0.3f;
     float val1 = 0.00006f;

    bool flag = false;

   


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

    /*  for (int i = 0; i < 200; i++) {
          
            posX = shapes[i].getPosition().x;
            posY = shapes[i].getPosition().y;
          */
            
        for (int i = 0; i < 1000; i++) {
            window.draw(shapes[i].drawBall());
            shapes[i].bounceBall();
        }
           

       //     if (shapes[i].getPosition().y + 40.f > 720) {
       //         val = -0.2f;
       //         val1 += 0.00006f;
       //         /* flag = true;*/
       //     }
       //     
       //     posY += val;

       //     shapes[i].setPosition(posX, posY);
       //}
       //

      



        //if (flag){
        //    val += 0.00006f;
        //    
        //
        //}

        //else {
        //    val += 0.00006f;
        //}
       
       // val += val1;
        
       // shape.setPosition(posX, posY);
        
        window.display();
    }

    return 0;
}