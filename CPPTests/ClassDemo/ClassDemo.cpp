// ClassDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


void printDataSize()
{
  char dataChar;
  short dataShort;
  int dataInt;
  long dataLong;
  long long dataLongLond;

  int size = sizeof(dataChar);
  std::cout << "Size of char ";
  std::cout << size;
  std::cout << "\n";
  size = sizeof(dataShort);
  std::cout << "Size of short ";
  std::cout << size;
  std::cout << "\n";
  size = sizeof(dataInt);
  std::cout << "Size of int ";
  std::cout << size;
  std::cout << "\n";
  size = sizeof(dataLong);
  std::cout << "Size of long ";
  std::cout << size;
  std::cout << "\n";
  size = sizeof(dataLongLond);
  std::cout << "Size of long long ";
  std::cout << size;
  std::cout << "\n";
}

struct tPoint
{
  int x = 0;
  int y = 0;
};

class cPoint
{
public:
  cPoint()
    : m_x(0)
    , m_y(0)
  {
  }
  cPoint(const int x, const int y);
  int getX() const
  {
    return m_x;
  }
  void setX(const int value)
  {
    m_x = value;
  }
  int getY() const
  {
    return m_y;
  }
  void setY(const int value)
  {
    m_y = value;
  }
  const tPoint getPoint()
  {
    return tPoint({ m_x, m_y });
  }
  void addX(const int value)
  {
    m_x += value;
  }
  void addY(const int value)
  {
    m_y += value;
  }
  void Add(cPoint& otherPoint)
  {
    m_x += otherPoint.m_x;
    m_y += otherPoint.m_y;
  }
  void operator += (cPoint& otherPoint)
  {
    m_x += otherPoint.m_x;
    m_y += otherPoint.m_y;
  }
protected:
private:
  int m_x;
  int m_y;
};

cPoint::cPoint(const int x, const int y)
{
  m_x = x;
  m_y = y;
}

void printPoint(cPoint &value)
{
  std::cout << "x = " << value.getX() << "\n";
  std::cout << "y = " << value.getY() << "\n";

}

void addX1(tPoint& point, const int value)
{
  point.x += value;
}

int main()
{
  //printDataSize();

  /*tPoint point;
  point.x = 10;
  point.y = 11;

  std::cout << "x = " << point.x << "\n";
  std::cout << "y = " << point.y << "\n";
  std::cout << 'p';*/

  tPoint point1;
  addX1(point1, 10);

  int x1 = 10;
  int y1 = 20;
  cPoint point(x1, y1);

  printPoint(point);
  //point.setX(20);
  //printPoint(point);
  //point.addX(15);
  cPoint point2(70, -100);
  //point.Add(point2);
  point += point2;
  printPoint(point);

  x1 = point.getX() + point2.getX();
  point.setX(x1);

  y1 = point.getY() + point2.getY();
  point.setY(y1);

  int size = sizeof(point);
  std::cout << "size = " << size << "\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
