/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: hw 9.5

Implement a class Rectangle. Provide a constructor to construct a
 rectangle with a given width and height, member functions get_perimeter
  and get_area that compute the perimeter and area, and a member function 
  void resize(double factor) that resizes the rectangle by multiplying
   the width and height by the given factor.

*/

#include <iostream>
using namespace std;

class Rectangle {
private:
    double height;
    double width;

public:
    Rectangle(double input_h, double input_w) {
        height = input_h;
        width = input_w;

    }
    Rectangle() {
        height = 0;
        width = 0;
    }
    double get_perimeter() {
        double per = (2*height) + (2*width);
        return per;
    }
    double get_area() {
        double area = height * width;
        return area;
    }
    void resize(double factor) {
        height = factor*height;
        width = factor*width;
    }


};