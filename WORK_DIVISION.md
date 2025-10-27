# Work Division Guide

## Assignment A: Core Structures & Utilities
**Files to implement:**
- `src/point.c` - Already implemented
- `src/kd_node.c` - Already implemented  
- `src/kd_tree.c` - Basic tree structure already done
- Add helper functions in `kd_node.c` if needed
- Test the basic structure works

**Focus areas:**
- Ensure point and node structures are correct
- Verify memory management (malloc/free)
- Test basic tree creation and destruction
- Add any utility functions needed by others

---

## Assignment B: Insertion Operations
**Files to implement:**
- Complete `kd_tree_insert()` in `src/kd_tree.c`

**Implementation details:**
- Recursive insertion algorithm
- Determine which side (left/right) based on splitting axis
- Handle duplicate points (your choice: skip, replace, or allow)
- Update tree size counter
- Test with various point configurations

**Recommended test cases:**
- Insert single point
- Insert multiple points with different coordinates
- Insert points in various orders
- Handle edge cases (NULL pointers, etc.)

---

## Assignment C: Search & Delete Operations
**Files to implement:**
- Complete `kd_tree_search()` in `src/kd_tree.c`
- Complete `kd_tree_delete()` in `src/kd_tree.c`
- Complete `kd_tree_nearest_neighbor()` in `src/kd_tree.c`
- Complete `kd_tree_range_search()` in `src/kd_tree.c`

**Implementation details:**
- Recursive search algorithm
- Delete operation (find and remove node, handle rebalancing)
- Nearest neighbor using branch-and-bound algorithm
- Range search (find all points within radius)
- Test all operations thoroughly

**Recommended test cases:**
- Search for existing and non-existing points
- Delete leaves, nodes with one child, nodes with two children
- Nearest neighbor queries from various points
- Range searches with different radii

---

## Integration Phase
Once each person completes their part:

1. **Merge code** 
2. **Integration test**
3. **Add main.c tests** - Create test cases
4. **Performance testing** - Test with large datasets
5. **Code review** - Review each other's code
6. **Documentation** - Add comments to your functions por favor

---

## Testing Strategy
Create test files in the `tests/` directory:
- `test_basic.c` - Basic functionality tests
- `test_insert.c` - Insertion tests
- `test_search.c` - Search tests
- `test_delete.c` - Deletion tests
- `test_performance.c` - Performance benchmarks

---

- Push your changes frequently to GitHub
- Write clear commit messages
- Please test your code before pushing, we just watched what happened at AWS
- Use TODO comments for incomplete parts that others might be able to help out on
