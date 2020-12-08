#include <iostream>
#include <vector>
using namespace std;

class Point {
  float x;
  float y;
  float z;
public:
  float getX() {
    return x;
  }

  float getY() {
    return y;
  }

  float getZ() {
    return z;
  }

  Point(float _x, float _y, float _z) {
    x =_x;
    y = _y;
    z = _z;
  }

  void readCoords() {
    cin >> x >> y >> z;
  }

  void printCoords() {
    cout << x << "; " << y << "; " << z << endl;
  }
};

class Plane {
  Point a;
  Point b;
  Point c;
public:
  Plane(Point _a, Point _b, Point _c) {
    a =_a;
    b = _b;
    c = _c;
  }
};

const float gc_maxX = 15.0;
const float gc_minX = 0.0;
const float gc_maxY = 15.0;
const float gc_minY = 0.0;
const float gc_maxZ = 15.0;
const float gc_minZ = 0.0;

vector <Point> gv_vertexes;


int checkIncidence(Point l_pnt) {
  // Проверка на принадлежность к интервалу допустимых значений координат
  if (
    l_pnt.getX() > gc_maxX || l_pnt.getX() < gc_minX &&
    l_pnt.getY() > gc_maxY || l_pnt.getY() < gc_minY &&
    l_pnt.getZ() > gc_maxZ || l_pnt.getZ() < gc_minZ
  ) {
    cout << "Point is outside of the object." << endl;
    return -1;
  }
  // Проверка на совпадение с одной из вершин
  for (int i = 0; i < ga_vertexes)
  if (l_pnt.getX()) {
    cout << "Point is outside of the object." << endl;
    return -1;
  }
  // Проверка принадлежности к ожной из плоскостей
  // Проверка на то, что проекция точки находится внутри плоскости основания
  return 0;
};

int main() {
  gv_vertexes.push_back(Point(0.0, -88.33, 120.0));
  gv_vertexes.push_back(Point(51.0, 0.0, 120.0));
  gv_vertexes.push_back(Point(-51.0, 0.0, 120.0));
  gv_vertexes.push_back(Point(0, -88.33, 0.0));
  gv_vertexes.push_back(Point(51.0, 0.0, 0.0));
  gv_vertexes.push_back(Point(-51.0, 0.0, 0.0));

  Point A;
  A.readCoords();

  return checkIncidence(A);
}
