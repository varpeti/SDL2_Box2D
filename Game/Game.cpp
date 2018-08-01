#include "Game.h"

char f_h_img[] = "data/img/hello.bmp";

Game::Game(SDL_Renderer *_renderer)
{
    renderer = _renderer;

    hello_image1 = new Image(renderer,f_h_img);
    hello_image2 = new Image(renderer,f_h_img,Rect(10,10,160,160));
    hello_image3 = new Image(renderer,f_h_img,Vec2(160,10),Vec2(160,100));
    hello_image4 = new Image(renderer,f_h_img,Rect(100,100,500,500),Rect(300,150,120,120));

    a=0;
}

Game::~Game()
{
    delete hello_image1;
    delete hello_image2;
    delete hello_image3;
    delete hello_image4;
}

void Game::update(float dt)
{
    hello_image1->update(dt);
    hello_image2->update(dt);
    hello_image3->update(dt);
    hello_image4->update(dt);

    a+=dt;
    hello_image2->rotate(a/10);
    hello_image4->rotate(-a/10,Vec2(30,30));

}

void Game::draw()
{
    hello_image1->draw();
    hello_image2->draw();
    hello_image3->draw();
    hello_image4->draw();
}