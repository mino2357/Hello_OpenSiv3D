/*
 * 1次元波動方程式を解く
 * 境界条件：Dirichlet zero
 *
 * by みーくん
 *
 */

#include <Siv3D.hpp> // OpenSiv3D v0.1.5
#include <iostream>
#include <limits>
#include <iomanip>
#include <cmath>
#include <vector>

//今は使わない
//#include "myvector.hpp"

constexpr int64 N = 1024;
constexpr double L = 3.1415;

void Main(){
    Graphics::SetTargetFrameRateHz(120);
    Graphics::SetBackground(ColorF(0.8, 0.9, 1.0));
    
    std::vector<double> u1(N);
    std::vector<double> u2(N);
    std::vector<double> u3(N);

    for(auto i=0; i<N; ++i){
        u1[i] = std::exp( - 40 * std::pow(L / (N - 1) * i - L/3, 2));
        u2[i] = std::exp( - 40 * std::pow(L / (N - 1) * i - L/3, 2));
    }

    double width  = Window::Width();
    double dWidth = width / (N - 1);

    const Font font(50);
    
    double dx = L / (N - 1);
    double dt = dx;
    double lam = (dt * dt)/(dx * dx);

    while(System::Update()){
        ClearPrint();
        
        for(auto i=0; i<N; ++i){
            Circle(0 + dWidth * i, Window::Height()/2. - 200 * u3[i], 1).draw(Palette::Green);
        }
        
        font(L"Hello, Siv3D!🐣").drawAt(Window::Width()/2 + 100, 40, Palette::Black);

        for(auto i=1; i<N-1; ++i){
            u3[i] = 2. * u2[i] - u1[i] + lam * (u2[i+1] - 2. * u2[i] + u2[i-1]);
        }
        for(auto i=0; i<N; ++i){
            u1[i] = u2[i];
            u2[i] = u3[i];
        }
    }
}
