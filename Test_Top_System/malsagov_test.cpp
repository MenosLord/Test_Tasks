#include <iostream>
#include <cmath>

using namespace std;

class Figure {
public:
    virtual void drawAscii()=0;
    virtual double area() = 0;
    virtual ~Figure(){}
};

// Класс для отрисовки круга
class Circle : public Figure {
private:
    double radius;
public:
    Circle(double r) : radius{r} {}
    void drawAscii() {
        for (int y = -radius; y <= radius; ++y) {
            for (int x = -radius; x <= radius; ++x) {
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
    double side;
public:
    Square(double s) : side{s} {}
    void drawAscii() {
        for(int i = 0; i < side; i++) {
            for(int j = 0; j < side; j++) {
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
    double base;
    double height;
public:
    Triangle(double b, double h) : base{b}, height{h} {}
    void drawAscii() {
        for (int i = 0; i < height; i++) {
        for (int j = 0; j < height - i - 1; j++) {
            cout << " ";
        }
        for (int k = 0; k < 2 * i + 1; k++) {
            if (k < base) {
                cout << "*";
            }
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
    double width;
    double height;
public:
    Rectangle(double w, double h) : width{w}, height{h} {}
    void drawAscii() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
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
    int choice = 0;
    int parametr = 0;
    int base = 0;
    int width = 0;
    int height = 0;
    Figure* figures;

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
            figures = new Circle(parametr);
            figures->drawAscii();
            cout << "Area: " << figures->area() << endl;
            
        } break;
        case 2: {
            cout << "Enter side length: \n";
            cin >> parametr;
            figures = new Square(parametr);
            figures->drawAscii();
            cout << "Area: " << figures->area() << endl;
            
        } break;
        case 3: {
            cout << "Enter base length and height: \n";
            cin >> base >> height;
            figures = new Triangle(base, height);
            figures->drawAscii();
            cout << "Area: " << figures->area() << endl;
            
        } break;
        case 4: {
            cout << "Enter width and height: \n";
            cin >> width >> height;
            figures = new Rectangle(width, height);
            figures->drawAscii();
            cout << "Area: " << figures->area() << endl;
            
        } break;
    }

    //очистка памяти
    delete figures;
 
    return 0;
}