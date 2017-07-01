#include <Siv3D.hpp> // OpenSiv3D v0.1.5
#include <iostream>
#include <limits>
#include <iomanip>
#include <cmath>
#include <vector>

//今は使わない
//#include "myvector.hpp"

constexpr int64 N = 128;
constexpr double L = 3.1415;
constexpr double dt = 0.005;

void Main(){
    Graphics::SetTargetFrameRateHz(120);
    Graphics::SetBackground(ColorF(0.8, 0.9, 1.0));
    
    std::vector<double> u1(N);
    std::vector<double> u2(N);
    std::vector<double> u3(N);

    //for(auto&& x: u1) x = 0.;
    //for(auto&& x: u2) x = 0.;
    //for(auto&& x: u3) x = 0.;

    for(uint64 i=0; i<N; ++i){
        u1[i] = std::exp( - 20 * std::pow(L / (N - 1) * i - L/2, 2));
        u2[i] = std::exp( - 20 * std::pow(L / (N - 1) * i - L/2, 2));
        u3[i] = std::exp( - 20 * std::pow(L / (N - 1) * i - L/2, 2));
    }

    double width  = Window::Width();

    double dWidth = width / (N - 1);

    const Font font(50);
    
    double t {};
    //double r = 100;
    double dx = L / (N - 1);
    double lam = (dt * dt)/(dx * dx);

    while (System::Update()){
        ClearPrint();
        Print << Cursor::Pos();
        t += System::DeltaTime();
        for(auto i=0; i<N; ++i){
            Circle(0 + dWidth * i,Window::Height()/2. - 200 * u3[i], 2).draw(Palette::Blue);
        }
        //Circle(Window::Width()/2 + r * cos(5*t), Window::Height()/2 - r * sin(6*t), 10).draw(Palette::Red);
        font(L"Hello, Siv3D!🐣").drawAt(Window::Center(), Palette::Black);

        for(auto i=1; i<N-1; ++i){
            u3[i] = 2. * u2[i] - u1[i] + lam * (u2[i+1] - 2. * u2[i] + u2[i-1]);
        }
        u3[0] = u3[1];
        u3[N-1] = u3[N-2];
        for(auto i=0; i<N; ++i){
            u1[i] = u2[i];
        }
        for(auto i=0; i<N; ++i){
            u2[i] = u3[i];
        }
    }
}
