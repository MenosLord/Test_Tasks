#include <iostream>
#include <cmath>

using namespace std;

class Figure {
public:
    virtual void drawAscii()=0;
    virtual double area() = 0;
};

// Класс для отрисовки круга
class Circle : public Figure {
private:
    double radius;
public:
    Circle(double r) : radius{r} {}
    void drawAscii() {
        for (auto y = -radius; y <= radius; ++y) {
            for (auto x = -radius; x <= radius; ++x) {
                double distance = sqrt(x * x + y * y);
                if (distance > radius - 0.5 && distance < radius + 0.5)
                    cout << "* ";
                else
                    cout << "  ";
            }
            cout << endl;
        }
    }
    double area() {
        return M_PI * radius * radius;
    }
};

// Класс для отрисовки квадрата
class Square : public Figure {
private:
    int32_t side;
public:
    Square(int32_t s) : side{s} {}
    
    void drawAscii() {
        for(auto i = 0; i < side; i++) {
            for(auto j = 0; j < side; j++) {
                cout << "*";
            }
            cout << endl;
        }
    }
    
    double area() {
        return side * side;
    }
};

// Класс для отрисовки треугольника
class Triangle : public Figure {
private:
    int32_t base;
    int32_t height;
public:
    Triangle(int32_t h) : height{h} { base = 2 * h + 1; }
    
    void drawAscii() {
        for (auto i = 0; i < height; i++) {
            for (auto j = 0; j < height - i - 1; j++) {
                cout << " ";
            }
            for (auto k = 0; k < 2 * i + 1; k++) {
                cout << "*";
            }
            cout << endl;
        }
    }
    double area() {
        return 0.5 * base * height;
    }
};

// Класс для отрисовки прямоугольника
class Rectangle : public Figure {
private:
    int32_t width;
    int32_t height;
public:
    Rectangle(int32_t w, int32_t h) : width{w}, height{h} {}
    void drawAscii() {
        for (auto i = 0; i < height; i++) {
            for (auto j = 0; j < width; j++) {
                cout << "*";
            }
            cout << endl;
        }
    }
    double area() {
        return width * height;
    }
};


int main() {
    int32_t choice = 0;
    int32_t parametr = 0;
    int32_t width = 0;
    int32_t height = 0;

    // меню
    cout << "Choose your figure: \n";
    cout << "1: Circle\n";
    cout << "2: Square\n";
    cout << "3: Triangle\n";
    cout << "4: Rectangle\n";
    
    cin >> choice; // выбор пользователя
    switch (choice){
        case 1: {
            cout << "Enter radius: \n";
            cin >> parametr;
            Circle circle(parametr);
            circle.drawAscii();
            cout << "Area: " << circle.area() << endl;
            
        } break;
        case 2: {
            cout << "Enter side length: \n";
            cin >> parametr;
            Square square(parametr);
            square.drawAscii();
            cout << "Area: " << square.area() << endl;
            
        } break;
        case 3: {
            cout << "Enter triangle's height: \n";
            cin >> height;
            Triangle triangle(height);
            triangle.drawAscii();
            cout << "Area: " << triangle.area() << endl;
            
        } break;
        case 4: {
            cout << "Enter width and height: \n";
            cin >> width >> height;
            Rectangle rectangle(width, height);
            rectangle.drawAscii();
            cout << "Area: " << rectangle.area() << endl;
            
        } break;
    }

     return 0;
}