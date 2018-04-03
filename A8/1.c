// A C++ program to find convex hull of a set of points. Refer
// https://www.geeksforgeeks.org/orientation-3-ordered-points/
// for explanation of orientation()
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct point{
    int x, y;
}point;

typedef struct node{
    point data;
    struct node* next;
}node;

void push(node** head, point p){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = p;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        newNode->next = *head;
        *head = newNode;
    }
}

point pop(node** head){
    point ans = (*head)->data;
    node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
    return ans;
}
// A globle point needed for  sorting points with reference
// to  the first point Used in compare function of qsort()
point p0;

// A utility function to find next to top in a stack
point nextToTop(node** head)
{
    point p = pop(head);
    point res = (*head)->data;
    push(head,p);
    return res;
}

// A utility function to swap two points

// A utility function to return square of distance
// between p1 and p2
int distSq(point p1, point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(point p, point q, point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

// A function used by library function qsort() to sort an array of
// points with respect to the first point
int compare(const void *vp1, const void *vp2)
{
   point *p1 = (point*)vp1;
   point *p2 = (point*)vp2;

   // Find orientation
   int o = orientation(p0, *p1, *p2);
   if (o == 0) return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;

   return (o == 2)? -1: 1;
}

// Prints convex hull of a set of n points.
void convexHull(point points[], int n)
{
   // Find the bottommost point
   int ymin = points[0].y, min = 0;
   for (int i = 1; i < n; i++)
   {
     int y = points[i].y;

     // Pick the bottom-most or chose the left
     // most point in case of tie
     if ((y < ymin) || (ymin == y &&
         points[i].x < points[min].x))
        ymin = points[i].y, min = i;
   }

   // Place the bottom-most point at first position
   //swap(points[0], points[min]);
   point temp = points[0];
   points[0] = points[min];
   points[min] = temp;

   // Sort n-1 points with respect to the first point.
   // A point p1 comes before p2 in sorted ouput if p2
   // has larger polar angle (in counterclockwise
   // direction) than p1
   p0 = points[0];
   qsort(&points[1], n-1, sizeof(point), compare);

   // If two or more points make same angle with p0,
   // Remove all but the one that is farthest from p0
   // Remember that, in above sorting, our criteria was
   // to keep the farthest point at the end when more than
   // one points have same angle.
   int m = 1; // Initialize size of modified array
   for (int i=1; i<n; i++)
   {
       // Keep removing i while angle of i and i+1 is same
       // with respect to p0
       while (i < n-1 && orientation(p0, points[i],
                                    points[i+1]) == 0)
          i++;


       points[m] = points[i];
       m++;  // Update size of modified array
   }

   // If modified array of points has less than 3 points,
   // convex hull is not possible
   if (m < 3) return;

   // Create an empty stack and push first three points
   // to it.
   node* head;
   push(&head,points[0]);
   push(&head,points[1]);
   push(&head,points[2]);

   // Process remaining n-3 points
   for (int i = 3; i < m; i++)
   {
      // Keep removing top while the angle formed by
      // points next-to-top, top, and points[i] makes
      // a non-left turn
      while (orientation(nextToTop(&head), head->data, points[i]) != 2)
        pop(&head);
      push(&head,points[i]);
   }

   // Now stack has the output points, print contents of stack
   while (head != NULL)
   {
       point p = head->data;
       printf("(%d,%d)\n",p.x,p.y);
       pop(&head);
   }
}

// Driver program to test above functions
int main()
{
    int n;
    scanf("%d",&n);
    point points[n];
    for(int i=0;i<n;i++){
        scanf("%d %d",&points[i].x,&points[i].y);
    }
    convexHull(points, n);
    return 0;
}
