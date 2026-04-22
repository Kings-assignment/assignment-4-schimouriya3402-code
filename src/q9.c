// Write a C program that uses a structure Point with members x and y, representing coordinates. 
// Write a function that takes two Point structures and returns the distance between them.
#include <stdio.h>
#include <math.h>
struct Point {
    float x;
    float y;
};
float distance(struct Point p1, struct Point p2) {  
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}
int main() {    
    struct Point point1, point2;
    printf("Enter coordinates for Point 1 (x y): ");
    scanf("%f %f", &point1.x, &point1.y);
    printf("Enter coordinates for Point 2 (x y): ");
    scanf("%f %f", &point2.x, &point2.y);
    float dist = distance(point1, point2);
    printf("The distance between the two points is: %.2f\n", dist);
    return 0;
}   