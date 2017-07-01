#include <Siv3D.hpp> // OpenSiv3D v0.1.5
#include <iostream>
#include <limits>
#include <iomanip>
#include <cmath>
#include "myvector.hpp"

void Main(){
    Graphics::SetTargetFrameRateHz(120);
    Graphics::SetBackground(ColorF(0.8, 0.9, 1.0));
    
    mino2357::vector<> vec1(1., 2.);
    mino2357::vector<> vec2(3., 4.);
    (vec1 + vec2).printPosition();
    
    const Font font(50);
    //const Texture textureCat(Emoji(L"🐈"), TextureDesc::Mipped);
    
    /*
    Print << L"Hello, Siv3D!";
    Print << L"1 + 1 = " << (1 + 1);
    Print << Vec2(12.3, 45.6);
    Print << Rect(100, 200, 500, 300);
    Print << DateTime::Now();
    Print << Range(1, 10);
    */
    
    double t {};
    double r = 100;
    
    while (System::Update()){
        ClearPrint();
        
        Print << Cursor::Pos();
        
        t += System::DeltaTime();
        
        font(L"Hello OpenSiv3D!.").drawAt(Window::Center(), Palette::Black);
        Circle(Window::Width()/2 + r * cos(5*t), Window::Height()/2 - r * sin(6*t), 10).draw(Palette::Red);
        
        /*
        font(L"Hello, Siv3D!🐣").drawAt(Window::Center(), Palette::Black);
        font(Cursor::Pos()).draw(20, 400, ColorF(0.6));
        textureCat.resize(80).draw(540, 380);
        Circle(Cursor::Pos(), 60).draw(ColorF(1, 0, 0, 0.5));
        */
    }
}
