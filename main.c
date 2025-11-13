/* 
    Resources: 
    to get an idea on how kd-trees work: https://www.geeksforgeeks.org/cpp/kd-trees-in-cpp/ 
*/

#include <stdio.h>
#include <stdlib.h>

#include "point.h"
#include "kd_node.h"
#include "kd_tree.h"

int main(void) {
    
    int dim; 
    int numPoints; 
    
    while(1){
        printf("Enter the dimension of the KD-tree: "); 
        if(scanf("%d", &dim) == 1 && dim >= 0 && dim <= 10){
            break; 
        }
        printf("Invalid dimension. Please try again.\n");
        int c; 
        while((c = getchar()) != '\n' && c != EOF); 
    }
    
    Tree kd = createTree(dim); 
    printf("Success. You have made a %dD KD-Tree\n", kd.dimension); 
    
    while(1){
        printf("Enter the number of points to insert: "); 
        if(scanf("%d", &numPoints) == 1 && numPoints > 0){
            break; 
        }
        printf("Invalid number of points. Please try again.\n"); 
        int c; 
        while((c = getchar()) != '\n' && c!= EOF);
    }
    
    Point **points = (Point**)malloc(sizeof(Point*) * numPoints); 
    if(!points){
        printf("Error. Memory allocation failed.\n"); 
        return 1; 
    }
    
    for(int x = 0; x < numPoints; x++){
        double coords[10]; 
        printf("Enter %d coordinates for point %d (seperated by spaces): ", dim, x+1); 
        for(int y = 0; y < dim; y++){
            while(scanf("%lf", &coords[y]) != 1){
                printf("Invalid input for coordinate %d. Please re-enter: ", y+1); 
                int c; 
                while((c= getchar()) != '\n' && c != EOF); 
            }
        }
        
        points[x] = createPoint(coords, dim); 
        if(!points[x]){
            printf("Error. Faield to create point %d.\n", x+1); 
            for(int z = 0; z < x; z++){
                destroyPoint(points[z]); 
            }
            free(points); 
            return 1; 
        }
        
        if(insertTree(&kd, points[x]) != 0){
            printf("Error. Failed to insert point %d.\n", x+1); 
        }
    }
    
    printf("\nSuccess. Inserted %d points into the KD-Tree.\n", treeSize(&kd)); 
    printf("\n========== KD-Tree Structure ==========\n"); 
    printTree(&kd); 
    
    int search; 
    while(1){
        printf("\nWould you like to search for a point? (1 = Yes, 0 = No): "); 
        if(scanf("%d", &search) == 1 && (search == 0 || search == 1)){
            break; 
        }
        printf("Invalid choice. Please try again.\n"); 
        int c; 
        while((c = getchar()) != '\n' && c != EOF); 
    }
    
    if(search == 1){
        double queryCoords[10]; 
        printf("Enter %d coordinates of the point to search for: ", dim); 
        for(int x = 0; x < dim; x++){
            while(scanf("%lf", &queryCoords[x]) != 1){
                printf("Invalid input for coordinate %d. Please re-enter: ", x+1); 
                int c; 
                while((c = getchar()) != '\n' && c != EOF); 
            }
        }
        
        Point *query = createPoint(queryCoords, dim); 
        Point *found = searchTree(&kd, query); 
        
        if(found){
            printf("Success. Point found in KD-tree: "); 
            printPoint(found); 
        }else{
            printf("Failure. Point not found in KD-tree.\n"); 
        }
        destroyPoint(query);
    }
    
    int neighbor; 
    while(1){
        printf("\nWould you like to find the nearest neighbor of a point? (1 = Yes, 0 = No): "); 
        if(scanf("%d", &neighbor) == 1 && (neighbor == 0 || neighbor == 1)){
            break; 
        }
        printf("Invalid choice. Please try again.\n"); 
        int c; 
        while((c = getchar()) != '\n' && c != EOF); 
    }
    
    if(neighbor == 1){
        double queryCoords[10]; 
        printf("Enter %d coordinates of the query point: ", dim); 
        for(int x = 0; x < dim; x++){
            while(scanf("%lf", &queryCoords[x]) != 1){
                printf("Invalid input for coordinate %d. Please re-enter: ", x+1); 
                int c; 
                while((c = getchar()) != '\n' && c != EOF);
            }
        }
        Point *query = createPoint(queryCoords, dim); 
        Point *nearest = nearestNeighbor(&kd, query); 
        if(nearest){
            printf("Success. Nearest Neighbor: "); 
            printPoint(nearest); 
        }else{
            printf("Failure. No nearest neighbor found.\n"); 
        }
        destroyPoint(query); 
    }
    
    int range; 
    while(1){
        printf("\nWould you like to find all points within a given distance? (1 = Yes, 0 = No): "); 
        if(scanf("%d", &range) == 1 && (range == 0 || range == 1)){
            break; 
        }
        printf("Invalid choice. Please try again.\n"); 
        int c; 
        while((c = getchar()) != '\n' && c != EOF); 
    }
    
    if(range == 1){
        double queryCoords[10];
        double radius; 
        printf("Enter %d coordinates of the query point: ", dim); 
        for(int x = 0; x < dim; x++){
            while(scanf("%lf", &queryCoords[x]) != 1){
                printf("Invalid input for coordinate %d. Please re-enter: ", x+1); 
                int c; 
                while((c = getchar()) != '\n' && c != EOF);
            }
        }
        
        while(1){
            printf("Enter search radius: "); 
            if(scanf("%lf", &radius) == 1 && radius > 0){ break; }
            printf("Invalid radius. Please try again.\n"); 
            int c; 
            while((c = getchar()) != '\n' && c != EOF);
        }
        
        Point *query = createPoint(queryCoords, dim); 
        Point results[10]; 
        int foundCount = rangeSearch(&kd, query, radius, results, 10); 
        printf("\nSuccess. Found %d points within %.2f units of query.\n", foundCount, radius); 
        for(int x = 0; x < foundCount; x++){
            printPoint(&results[x]); 
        }
        destroyPoint(query); 
    }
    
    destroyTree(&kd); 
    printf("KD-Tree destroyed.\n"); 
    free(points); 
    

    return 0;
}