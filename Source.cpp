#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

class Ball {

    float posY,posX;
    float val=2;
    float val1 = 0.00006f;
    sf::CircleShape shape;




    public:
         void createBall(float ballPosX, float ballPosY) {
    
             //  posY = ballPosY;
               //posX = ballPosX;
            

       
               shape.setRadius(30.f);
               shape.setOutlineColor(sf::Color().White);
               shape.setOutlineThickness(2);
               shape.setFillColor(sf::Color().Red);
              // shape.setPosition(ballPosX, ballPosY);
      


         }

         sf::CircleShape drawBall() {
    
             return shape;
    
         }

         void setPosition(float BallPosX, float BallPosY) {
         
             posY = BallPosY;
             posX = BallPosX;

             shape.setPosition(posX, posY);



         }

         
         int getPositionX() {

             return posX;

         }

         int getPositionY() {

             return posY;

         }


         void bounceBall() {
             
               if (shape.getPosition().y + 30.f > 720) {
                     val = -2;
                     val1 += 0.006f;
                          /* flag = true;*/
                }

               val += val1;
               posY += val;
               shape.setPosition(posX, posY);
           
          }

};

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
   

    std::vector<Ball> shapes;
   // float ballPosY = 0.f, ballPosX = 0.f;
    float ballPosX = 1280 / 2, ballPosY = 720 / 2;

    for (int i = 0; i < 2; i++) {

      //   ballPosX = rand() % 1280 + 1;
     //    ballPosY = rand() % 720 + 1;
        
        Ball ball;
        ball.createBall(ballPosX, ballPosY);
        //sf::CircleShape ballShape = ball.createBall(ballPosX, ballPosY);
        ballPosX += 100;
        ballPosY += 100;
        
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


        sf::Vector2i position = sf::Mouse::getPosition(window);

        shapes[0].setPosition(1280/2, 720/2);
        shapes[1].setPosition(position.x, position.y);
       

        
        if (shapes[1].getPositionX() + 60.f > shapes[0].getPositionX() && 
            shapes[1].getPositionY() < shapes[0].getPositionY() + 60.f &&
            shapes[1].getPositionY() > shapes[0].getPositionY() - 60.f)
            {

            shapes[1].setPosition(shapes[0].getPositionX() - 60.f, shapes[1].getPositionY() - 50);
            
        }

        if (shapes[1].getPositionX() < shapes[0].getPositionX() + 30.f) {
        
        }

        window.clear();

    /*  for (int i = 0; i < 200; i++) {
          
            posX = shapes[i].getPosition().x;
            posY = shapes[i].getPosition().y;
          */
            
        for (int i = 0; i < 2; i++) {
            window.draw(shapes[i].drawBall());
          //  shapes[i].setPosition();
           // shapes[i].bounceBall();
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