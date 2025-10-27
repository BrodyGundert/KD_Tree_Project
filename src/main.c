#include <stdio.h>
#include <stdlib.h>
#include "../include/kd_tree.h"

int main(void) {
    // Example usage of KD-tree
    
    // Create a KD-tree for 2D points
    KDTree *tree = kd_tree_create(2);
    if (tree == NULL) {
        fprintf(stderr, "Failed to create KD-tree\n");
        return 1;
    }
    
    // TODO: Add test cases
    printf("KD-Tree created successfully!\n");
    printf("Tree is %s\n", kd_tree_is_empty(tree) ? "empty" : "not empty");
    printf("Tree size: %d\n", kd_tree_size(tree));
    
    kd_tree_destroy(tree);
    printf("KD-Tree destroyed successfully!\n");
    
    return 0;
}
