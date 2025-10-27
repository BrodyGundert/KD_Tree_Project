#ifndef POINT_H
#define POINT_H

#define MAX_DIMENSIONS 16

/**
 * Structure representing a point in k-dimensional space
 */
typedef struct {
    double coordinates[MAX_DIMENSIONS];
    int dimensions;
    void *data;  // Optional: store additional data with the point
} Point;

/**
 * Create a new point with specified coordinates
 * @param coords Array of coordinates
 * @param dim Number of dimensions
 * @return Pointer to new Point, or NULL on failure
 */
Point *point_create(double *coords, int dim);

/**
 * Free a point
 * @param p Point to free
 */
void point_destroy(Point *p);

/**
 * Calculate squared Euclidean distance between two points
 * @param p1 First point
 * @param p2 Second point
 * @return Squared distance
 */
double point_distance_squared(Point *p1, Point *p2);

/**
 * Print a point (for debugging)
 * @param p Point to print
 */
void point_print(Point *p);

#endif // POINT_H
