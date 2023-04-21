#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100 // maximum number of points

// structure to represent a 2D point
typedef struct {
    int x;
    int y;
} Point;

// function to compare two points by their polar angle with respect to a reference point
int compare_points(const void* a, const void* b) {
    Point* p1 = (Point*) a;
    Point* p2 = (Point*) b;
    // compute the cross product between the vectors p1p0 and p2p0
    int cross_product = (p1->x - p0.x) * (p2->y - p0.y) - (p1->y - p0.y) * (p2->x - p0.x);
    if (cross_product == 0) {
        // if the points are collinear, choose the one that is farther from p0
        int dist1 = (p1->x - p0.x) * (p1->x - p0.x) + (p1->y - p0.y) * (p1->y - p0.y);
        int dist2 = (p2->x - p0.x) * (p2->x - p0.x) + (p2->y - p0.y) * (p2->y - p0.y);
        return (dist1 < dist2) ? 1 : -1;
    }
    return (cross_product > 0) ? -1 : 1; // sort in counterclockwise order
}

// function to compute the convex hull of a set of points
void convex_hull(Point* points, int n, Point* hull, int* hull_size) {
    // find the point with the minimum y-coordinate (break ties by minimum x-coordinate)
    int min_y = points[0].y;
    int min_x = points[0].x;
    int min_idx = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < min_y || (points[i].y == min_y && points[i].x < min_x)) {
            min_y = points[i].y;
            min_x = points[i].x;
            min_idx = i;
        }
    }
    // set the reference point to the point with the minimum y-coordinate
    p0 = points[min_idx];
    // sort the other points by their polar angle with respect to the reference point
    qsort(points, n, sizeof(Point), compare_points);
    // initialize the stack with the first two points
    int stack[MAX_POINTS];
    int top = 1;
    stack[0] = 0;
    stack[1] = 1;
    // loop over the remaining points and add them to the hull or remove them from the hull
    for (int i = 2; i < n; i++) {
        while (top > 0 && ((points[stack[top]].x - p0.x) * (points[i].y - p0.y) - 
                           (points[stack[top]].y - p0.y) * (points[i].x - p0.x)) < 0) {
            // remove the top point from the stack
            top--;
        }
        // add the current point to the stack
        top++;
        stack[top]
