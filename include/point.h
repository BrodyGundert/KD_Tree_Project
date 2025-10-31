#ifndef POINT_H
#define POINT_H

#include <stdio.h>
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
        p->coordiantes[x] = coords[i]; 
    }
    return p; 
}

// free a point 
void destroyPoint(Point *p); 

//calculates squared Euclidean distance between two points
double distanceSquared(Point *p1, Point *p2); 

//prints a point, its main purpose is for debugging 
void printPoint(Point *p){
    if(!p){
        printf("NULL\n"); 
        return; 
    }
    
    printf("Point (%dD): [", p->dimensions); 
    for(int x = 0; x < p->dimensions; x++){
        if(x < p->dimensions[x]){
            printf(", "); 
        }
    }
    printf("]\n"); 
} 

#endif
