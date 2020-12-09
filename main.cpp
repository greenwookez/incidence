#include <iostream>
#include <vector>
#include <math.h>
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

  void readCoords() {
    cin >> x >> y >> z;
  }

  void printCoords() {
    cout << x << "; " << y << "; " << z;
  }

  Point() {
    x = 0.0;
    y = 0.0;
    z = 0.0;
  }

  Point(float _x, float _y, float _z) {
    x =_x;
    y = _y;
    z = _z;
  }


};

const float gc_minX = -51.0;
const float gc_maxX = 51.0;

const float gc_minY = -88.33;
const float gc_maxY = 0.0;

const float gc_minZ = 0.0;
const float gc_maxZ = 120.0;

vector <Point> gv_vertexes;

float calculatePointToLineRelation(Point l_pnt, Point A, Point B) {
  // Точка l_pnt - точка для которой считается положение относительно прямой
  // Прямая задается двумя точками A и B
  // В данной подпрограмме вычисляется некое значение d такое, что:
  // если d = 0, то точка находится на прямой
  // если d < 0, то точка находится слева от прямой
  // если d > 0, то тчока находится справа от прямой
  return (l_pnt.getX() - A.getX()) * (B.getY() - A.getY()) - (l_pnt.getY() - A.getY())*(B.getX() - A.getX());
};

float checkPointToLineRelation(Point pnt, Point A, Point B) {
  // Если площадь треугольника, образованного тремя точками, равна 0, то это не треугольник, и точка лежит на прямой
  const float a = sqrt(pow((B.getX() - pnt.getX()), 2) + pow((B.getY() - pnt.getY()), 2) + pow((B.getZ() - pnt.getZ()), 2));
  const float b = sqrt(pow((A.getX() - pnt.getX()), 2) + pow((A.getY() - pnt.getY()), 2) + pow((A.getZ() - pnt.getZ()), 2));
  const float c = sqrt(pow((B.getX() - A.getX()), 2) + pow((B.getY() - A.getY()), 2) + pow((B.getZ() - A.getZ()), 2));
  const float p = (a+b+c) * 0.5;

  const float res = p*(p-a)*(p-b)*(p-c);

  if (abs(res) < 0.001) {
    return 0;
  } else {
    return -1;
  }
};

float solvePlaneEquation(Point l_pnt, Point A, Point B, Point C) {
  // Точка l_pnt - точка, относительно которой считается уравнение плоскости
  // Сама плоскость образуетя тремя точками A, B, C
  return (l_pnt.getX() - A.getX())*((B.getY() - A.getY())*(C.getZ() - A.getZ()) - (C.getY() - A.getY())*(B.getZ() - A.getZ())) - (l_pnt.getY() - A.getY())*((B.getX() - A.getX())*(C.getZ() - A.getZ()) - (B.getZ() - A.getZ())*(C.getX() - A.getX())) + (l_pnt.getZ() - A.getZ())*((B.getX() - A.getX())*(C.getY() - A.getY()) - (C.getX() - A.getX())*(B.getY() - A.getY()));
};

float checkPlaneIncidence(Point pnt) {
  // Проверка принадлежности к одной из граней
  // Возвращает 0, если точка pnt принадлежит какой-то из граней
  // Вовзращает -1, если точка pnt не приналделиж ни к одно из граней
  Point lo_pntA;
  Point lo_pntB;
  Point lo_pntC;
  float tmp;

  lo_pntA = gv_vertexes[0];
  lo_pntB = gv_vertexes[1];
  lo_pntC = gv_vertexes[2];
  tmp = solvePlaneEquation(pnt, lo_pntA, lo_pntB, lo_pntC);
  if (tmp == 0) {
    return 0;
  };

  lo_pntA = gv_vertexes[3];
  lo_pntB = gv_vertexes[4];
  lo_pntC = gv_vertexes[5];
  tmp = solvePlaneEquation(pnt, lo_pntA, lo_pntB, lo_pntC);
  if (tmp == 0) {
    return 0;
  };

  lo_pntA = gv_vertexes[0];
  lo_pntB = gv_vertexes[1];
  lo_pntC = gv_vertexes[4];
  tmp = solvePlaneEquation(pnt, lo_pntA, lo_pntB, lo_pntC);
  if (tmp == 0) {
    return 0;
  };

  lo_pntA = gv_vertexes[0];
  lo_pntB = gv_vertexes[2];
  lo_pntC = gv_vertexes[5];
  tmp = solvePlaneEquation(pnt, lo_pntA, lo_pntB, lo_pntC);
  if (tmp == 0) {
    return 0;
  };

  lo_pntA = gv_vertexes[1];
  lo_pntB = gv_vertexes[2];
  lo_pntC = gv_vertexes[5];
  tmp = solvePlaneEquation(pnt, lo_pntA, lo_pntB, lo_pntC);
  if (tmp == 0) {
    return 0;
  };

  return -1;
};

int checkIncidence(Point pnt) {
  // В данной подпрограмме поределяется инцидентность точке исходному геометрическому объекту

  // Проверка на принадлежность к интервалу допустимых значений координат
  if ((pnt.getX() > gc_maxX || pnt.getX() < gc_minX) || (pnt.getY() > gc_maxY || pnt.getY() < gc_minY) || (pnt.getZ() > gc_maxZ || pnt.getZ() < gc_minZ)) {
    cout << "Interval: Point is outside the object." << endl;
    return -1;
  }

  // Проверка на совпадение с одной из вершин
  for (int i = 0; i < gv_vertexes.size(); i++) {
    if (pnt.getX() == gv_vertexes[i].getX() && pnt.getY() == gv_vertexes[i].getY() && pnt.getZ() == gv_vertexes[i].getZ()) {
      cout << "Point is one of the object's vertexes." << endl;
      return 0;
    }
  }

  // Проверка на положение относительно прямых, лежащих в плоскости основания ГО
  if (calculatePointToLineRelation(pnt, gv_vertexes[0], gv_vertexes[1]) > 0 || calculatePointToLineRelation(pnt, gv_vertexes[0], gv_vertexes[2]) < 0 || calculatePointToLineRelation(pnt, gv_vertexes[1], gv_vertexes[2]) > 0) {
    cout << "Line: Point is outside the object." << endl;
    return -1;
  };

  // Проверка на принадлежность граням и ребрам
  if (checkPlaneIncidence(pnt) == 0) {
    if (
      checkPointToLineRelation(pnt, gv_vertexes[0], gv_vertexes[1]) == 0 ||
      checkPointToLineRelation(pnt, gv_vertexes[0], gv_vertexes[2]) == 0 ||
      checkPointToLineRelation(pnt, gv_vertexes[1], gv_vertexes[2]) == 0 ||
      checkPointToLineRelation(pnt, gv_vertexes[3], gv_vertexes[4]) == 0 ||
      checkPointToLineRelation(pnt, gv_vertexes[3], gv_vertexes[5]) == 0 ||
      checkPointToLineRelation(pnt, gv_vertexes[4], gv_vertexes[5]) == 0 ||
      checkPointToLineRelation(pnt, gv_vertexes[0], gv_vertexes[3]) == 0 ||
      checkPointToLineRelation(pnt, gv_vertexes[1], gv_vertexes[4]) == 0 ||
      checkPointToLineRelation(pnt, gv_vertexes[2], gv_vertexes[5]) == 0
    ) {
      cout << "Point is on the edge of the object." << endl;
      return 0;
    }

    cout << "Point is on the surface of the object." << endl;
    return 0;
  }

  // Если точка прошла все проверки успешно, то она лежит внутри ГО
  cout << "Point is inside the object." << endl;
  return 1;
};

int main(int argc, char* argv[]) {
  // Локальные переменные для считывания значений координат точки из терминала
  float lv_pntX, lv_pntY, lv_pntZ;

  // Заполнение вектора вершин геометрического объекта
  gv_vertexes.push_back(Point(0.0, -88.33, 120.0));
  gv_vertexes.push_back(Point(51.0, 0.0, 120.0));
  gv_vertexes.push_back(Point(-51.0, 0.0, 120.0));
  gv_vertexes.push_back(Point(0, -88.33, 0.0));
  gv_vertexes.push_back(Point(51.0, 0.0, 0.0));
  gv_vertexes.push_back(Point(-51.0, 0.0, 0.0));

  // Преобразование входных строковых данных в вещественные значнения
  for (int i = 1; i < argc; i++) {
    switch (i) {
      case 1:
        lv_pntX = stof(argv[i]);
      case 2:
        lv_pntY = stof(argv[i]);
      case 3:
        lv_pntZ = stof(argv[i]);
    }
  }

  // Объявление точки, для которой будет проверяться инцидентность
  Point A(lv_pntX, lv_pntY, lv_pntZ);

  // Вывод введенных координат
  cout << "Input point is ("; A.printCoords(); cout << ")." << endl;

  // Вызов подрограммы проверки инцидентности и вывод результатов
  int res = checkIncidence(A);

  // float res = checkPointToLineRelation(A, gv_vertexes[1], gv_vertexes[2]);
  cout << "Result is " << res << "." << endl;
  return res;
}
