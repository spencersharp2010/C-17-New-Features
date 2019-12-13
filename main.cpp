#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

constexpr long int fib(int n)
{
    return (n <= 1)? n : fib(n-1) + fib(n-2);
}

class Rectangle
{
    int _width, _height;
public:
    constexpr Rectangle (int w, int h) : _width(w), _height(h) {}
    constexpr double getArea() const {return _width * _height; }
};


template<class T>
double m2_to_ft2(T input)
{
    if constexpr(std::is_same_v<T, Rectangle>)
    {
        return input.getArea() / 10.76;
    }
    else
    {
        return input / 10.76;
    }
}

int main() {

    // capture *this in lambda ------------------------------
    struct MyObj {
        int value {123};
        auto getValueCopy() {
            return [*this] { return value; };
        }
        auto getValueRef() {
            return [this] { return value; };
        }
    };

    MyObj mo;
    auto valueCopy = mo.getValueCopy();
    auto valueRef = mo.getValueRef();
    mo.value = 321;
    std::cout << "valueCopy(): " << valueCopy() << std::endl; // 123
    std::cout << "valueRef(): " << valueRef() << std::endl; // 321

    // constexpr ------------------------------------------
    const long int result = fib(30);
    std::cout << "fibonacci sum of 30 is: " << result << std::endl;

    // constexpr if  ------------------------------------------
    constexpr Rectangle rectA(10,20);
    std::cout << "area of rectangle A: " << rectA.getArea() << std:: endl;
    const Rectangle rectB(5,5);
    std::cout << "area of rectangle B: " << rectB.getArea() << std::endl;

    std::cout << "convert rectB to m2: " << m2_to_ft2(rectB) << std::endl;
    std::cout << "convert arbitrary area to m2: " << m2_to_ft2(5.) << std::endl;

    // constexpr in lamddas
    constexpr std::array < int, 6 > arr {1 , 4 , -7, 10, -20, 5};
    constexpr int abs_max = *std::max_element(
            arr.begin(),
            arr.end(),
            []( int a, int b ) { return a < b; }
    );

    std::cout << "max element of array (found at compile time!): " << abs_max;

    return 0;
}