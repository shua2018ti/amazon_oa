// Example program
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <math.h>  
#include <vector>
using namespace std;

struct Point { 
    double x;
    double y; 
    Point(double a, double b) {
        x = a;
        y = b;
    }
};

double getDistance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
typedef bool (*comp)(Point, Point);
Point global_origin = Point(0,0);
bool compare(Point a, Point b)
{
   return (getDistance(a, global_origin) < getDistance(b, global_origin));
}

vector<Point> Solution(vector<Point> &array, Point origin, int k) {
    global_origin = Point(origin.x, origin.y);
    priority_queue<Point, std::vector<Point>, comp> pq(compare);
    vector<Point> res;
    for (int i = 0; i < array.size(); i++) {
        Point p = array[i];
        pq.push(p);
        // Only keep the nearest k points to the origin
        if (pq.size() > k)
            pq.pop();
    }
    int index = 0;
    while (!pq.empty()){
        Point p = pq.top();
        res.push_back(p);
        pq.pop();
    }
    return res;
}



int main()
{
   Point p1 = Point(4.5, 6.0);
   Point p2 = Point(4.0, 7.0);
   Point p3 = Point(4.0, 4.0);
   Point p4 = Point(2.0, 5.0);
   Point p5 = Point(1.0, 1.0);
   vector<Point> array = {p1, p2, p3, p4, p5};
   int k = 2;
   Point origin = Point(0.0, 0.0);
   vector<Point> ans = Solution(array, origin, k);
   for (int i = 0; i < ans.size(); i++) {
       cout << i << ": " << ans[i].x << "," << ans[i].y << endl;
   }
   //cout << getDistance(p1, p2) << endl;
}


