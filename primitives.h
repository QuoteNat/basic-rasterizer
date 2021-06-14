#ifndef PRIMITIVES_H
#define PRIMITIVES_H

/**
 * @brief Represents a color using RGB, with values ranging from 0 to 255.
 */
struct color {
    int r;
    int g;
    int b;
};

/**
 * @brief The Point struct represents a pixel on the screen using the x,y grid.
 */
struct point {
    int x;
    int y;
};

#endif // PRIMITIVES_H
