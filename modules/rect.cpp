// quadragon (aka quadrilateral) in a 2d coordinate

// Option 1:
class Quad {
    int x[4];
    int y[4];
    void setPoint(int index, int x, int y) {
        x[index] = x;
        y[index] = y;
    }
};

// Option 2:
class Point {
    int x, y;
};
class Quad {
    Point corners[4];
    void setPoint(int index, const Point &p) {
        corners[index] = p;
    }
};

// Which one is better?
// To find an answer, we have to investigate cohesion.
// What is used or changes together?
// And how likely is it that it is used together or changed?
