#include <Siv3D.hpp> // OpenSiv3D v0.1.5
#include <iostream>
#include <limits>
#include <iomanip>

namespace mino2357{
    template<typename T = double>
    class vector{
    private:
        T componentX;
        T componentY;
    public:
        vector(T x, T y) noexcept : componentX(x), componentY(y) {}
        vector() noexcept : vector{T{}, T{}} {}
        
        inline void setComponetX(T) noexcept;
        inline void setComponetY(T) noexcept;
        
        inline T getComponentX() const noexcept;
        inline T getComponentY() const noexcept;
        
        inline vector& operator=( const vector<T>&) noexcept;
        inline vector& operator+=(const vector<T>&) noexcept;
        inline vector& operator-=(const vector<T>&) noexcept;
        
        inline void printPosition() noexcept;
    };
    
    template <typename T>
    inline void vector<T>::setComponetX(T x) noexcept {
        componentX = x;
    }
    
    template <typename T>
    inline void vector<T>::setComponetY(T y) noexcept {
        componentY = y;
    }
    
    template <typename T>
    inline T vector<T>::getComponentX() const noexcept {
        return this->componentX;
    }
    
    template <typename T>
    inline T vector<T>::getComponentY() const noexcept {
        return this->componentY;
    }
    
    template <typename T>
    inline void vector<T>::printPosition() noexcept{
        std::cout << std::fixed << std::setprecision(std::numeric_limits<double>::digits10 + 1);
        std::cout << componentX << " " << componentY << std::endl;
    }
        
    template <typename T>
    inline vector<T>& vector<T>::operator=(const vector<T>& v) noexcept {
        this->componentX = v.getComponentX();
        this->componentY = v.getComponentY();
        return *this;
    }
    
    template <typename T>
    inline vector<T>& vector<T>::operator+=(const vector<T>& v) noexcept {
        this->componentX += v.getComponentX();
        this->componentY += v.getComponentY();
        return *this;
    }
        
    template <typename T>
    inline vector<T>& vector<T>::operator-=(const vector<T>& v) noexcept {
        this->componentX -= v.getComponentX();
        this->componentY -= v.getComponentY();
        return *this;
    }
    
    template <typename T>
    inline vector<T> operator+(const vector<T>& a, const vector<T>& b) noexcept {
        return vector<T>{
            a.getComponentX() + b.getComponentX(),
            a.getComponentY() + b.getComponentY(),
        };
    }

    template <typename T>
    inline vector<T> operator-(const vector<T>& a, const vector<T>& b) noexcept {
        return vector<T>{
            a.getComponentX() - b.getComponentX(),
            a.getComponentY() - b.getComponentY(),
        };
    }

    template <typename T>
    inline T operator*(const vector<T>& a, const vector<T>& b) noexcept {
        return
            a.getComponentX() * b.getComponentX()
          + a.getComponentY() * b.getComponentY();
    }
}
        
        
void Main(){
    Graphics::SetBackground(ColorF(0.8, 0.9, 1.0));
    
    mino2357::vector<> vec1(1., 2.);
    mino2357::vector<> vec2(3., 4.);
    (vec1 + vec2).printPosition();
    //Log << test.getComponentX();
    /*
    const Font font(50);
             
    const Texture textureCat(Emoji(L"🐈"), TextureDesc::Mipped);
    */
    while (System::Update()){
        Circle(Cursor::Pos(), 40).draw();
        /*
        font(L"Hello, Siv3D!🐣").drawAt(Window::Center(), Palette::Black);
                 
        font(Cursor::Pos()).draw(20, 400, ColorF(0.6));
                 
         textureCat.resize(80).draw(540, 380);
                 
        Circle(Cursor::Pos(), 60).draw(ColorF(1, 0, 0, 0.5));
        */
    }
}
