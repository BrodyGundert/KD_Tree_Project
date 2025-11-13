


#ifndef POINT_H
#define POINT_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define MAX_DIMENSIONS 16

// structure representing a point in k-dimensional space 
typedef struct{
    double coordinates[MAX_DIMENSIONS]; 
    int dimensions; 
    void *data; 
} Point; 

// creates a new point with specified coordinates 
Point *createPoint(double *coords, int dim){
    if(dim <= 0 || dim > MAX_DIMENSIONS || coords == NULL){
        printf("Error. Invalid dimensions or NULL coordinates.\n"); 
        return NULL; 
    }
    Point *p = (Point *)malloc(sizeof(Point)); 
    if(!p){
        printf("Error. Memory allocation failed.\n"); 
        return NULL; 
    }
    
    p->dimensions = dim; 
    p->data = NULL; 
    
    for(int x = 0; x < dim; x++){
        p->coordinates[x] = coords[x]; 
    }
    return p; 
}

// free a point 
void destroyPoint(Point *p) {
    free(p);
}

//calculates squared Euclidean distance between two points
double distanceSquared(Point *p1, Point *p2) {
    if (!p1 || !p2 || (p1->dimensions !=p2->dimensions) || (p1->dimensions <= 0)) {
        //undefined float/double
        return NAN;
    }
    
    double dd = 0.0;
    for (int i= 0; i < p1->dimensions; i++) {
        double d = p1->coordinates[i] - p2->coordinates[i];
        dd += d * d;
    }
    
    return dd;
}

//prints a point, its main purpose is for debugging 
void printPoint(Point *p){
    if(!p){
        printf("NULL\n"); 
        return; 
    }
    
    printf("Point (%dD): [", p->dimensions); 
    for(int x = 0; x < p->dimensions; x++){
        if(x){
            printf(", "); 
        }
        printf("%g", p->coordinates[x]);
    }
    printf("]\n"); 
} 

#endif