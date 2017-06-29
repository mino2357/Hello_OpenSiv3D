#include<Siv3D.hpp> // OpenSiv3D v0.1.5

namespace mino2357{
    template<typename T = double>
    class vector{
    private:
        T componentX;
        T componentY;
    public:
        vector(T x, T y) noexcept : componentX(x), componentY(y){}
        vector() noexcept : vector{T{}, T{}} {}
    };
}


void Main()
{
    Graphics::SetBackground(ColorF(0.8, 0.9, 1.0));
    /*
    const Font font(50);
    
    const Texture textureCat(Emoji(L"🐈"), TextureDesc::Mipped);
    */
    while (System::Update())
    {
        Circle(Cursor::Pos(), 40).draw();
        /*
        font(L"Hello, Siv3D!🐣").drawAt(Window::Center(), Palette::Black);
        
        font(Cursor::Pos()).draw(20, 400, ColorF(0.6));
        
        textureCat.resize(80).draw(540, 380);
        
        Circle(Cursor::Pos(), 60).draw(ColorF(1, 0, 0, 0.5));
         */
    }
}
