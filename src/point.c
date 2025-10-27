#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/point.h"

Point *point_create(double *coords, int dim) {
    if (coords == NULL || dim <= 0 || dim > MAX_DIMENSIONS) {
        return NULL;
    }
    
    Point *p = (Point *)malloc(sizeof(Point));
    if (p == NULL) {
        return NULL;
    }
    
    p->dimensions = dim;
    p->data = NULL;
    
    for (int i = 0; i < dim; i++) {
        p->coordinates[i] = coords[i];
    }
    
    return p;
}

void point_destroy(Point *p) {
    if (p != NULL) {
        free(p);
    }
}

double point_distance_squared(Point *p1, Point *p2) {
    if (p1 == NULL || p2 == NULL || p1->dimensions != p2->dimensions) {
        return -1.0;
    }
    
    double sum = 0.0;
    for (int i = 0; i < p1->dimensions; i++) {
        double diff = p1->coordinates[i] - p2->coordinates[i];
        sum += diff * diff;
    }
    
    return sum;
}

void point_print(Point *p) {
    if (p == NULL) {
        printf("NULL");
        return;
    }
    
    printf("(");
    for (int i = 0; i < p->dimensions; i++) {
        printf("%.2f", p->coordinates[i]);
        if (i < p->dimensions - 1) {
            printf(", ");
        }
    }
    printf(")");
}
