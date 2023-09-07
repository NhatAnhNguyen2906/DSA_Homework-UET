#include <iostream>
#include <cmath>

class Point {
public:
    double x, y;
    
    Point(double _x, double _y) : x(_x), y(_y) {}
};

class Line {
public:
    Point p1, p2;
    
    Line(Point _p1, Point _p2) : p1(_p1), p2(_p2) {}
    
    // Function to check if two lines intersect and calculate the intersection point
    bool findIntersection(const Line& other, Point& intersection) const {
        double x1 = p1.x, y1 = p1.y, x2 = p2.x, y2 = p2.y;
        double x3 = other.p1.x, y3 = other.p1.y, x4 = other.p2.x, y4 = other.p2.y;

        double denominator = ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));

        // Check if the lines are parallel (denominator is zero)
        if (std::abs(denominator) < 1e-6) {
            return false;
        }

        double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denominator;
        double u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / denominator;

        // Check if the intersection point lies within the line segments
        if (t >= 0.0 && t <= 1.0 && u >= 0.0 && u <= 1.0) {
            intersection.x = x1 + t * (x2 - x1);
            intersection.y = y1 + t * (y2 - y1);
            return true;
        }

        return false;
    }
};

int main() {
    // Read input points A, B, C, and D
    double ax, ay, bx, by, cx, cy, dx, dy;
    std::cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

    // Create Point objects for A, B, C, and D
    Point A(ax, ay);
    Point B(bx, by);
    Point C(cx, cy);
    Point D(dx, dy);

    // Create Line objects for AB and CD
    Line AB(A, B);
    Line CD(C, D);

    Point intersection;

    // Check if the lines intersect and calculate the intersection point
    if (AB.findIntersection(CD, intersection)) {
        std::cout << intersection.x << " " << intersection.y << std::endl;
    } else {
        // Check if the lines are collinear
        if ((A.x - B.x) * (C.y - D.y) == (A.y - B.y) * (C.x - D.x)) {
            std::cout << "MANY" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
