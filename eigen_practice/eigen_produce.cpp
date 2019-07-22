#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
using namespace std;
int main()
{
  //--------矩陣與向量--------
  MatrixXd m(2,2);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  std::cout << "Here is the matrix m:\n" << m << std::endl;
  VectorXd v(2);
  v(0) = 4;
  v(1) = v(0) - 1;
  std::cout << "Here is the vector v:\n" << v << std::endl;
  cout << endl;

  //--------向量的大小設定--------
  Vector2d a (5.0,6.0);
  Vector3d b (5.0,6.0,7.0);
  Vector4d c (5.0,6.0,7.0,8.0);
  std::cout<< "Here is a group of vector a,b,c:\n" << a << "\n\n" 
           << b << "\n\n" << c << "\n\n" << std::endl;
  cout << endl;

  //--------矩陣與向量的大小顯示--------
  MatrixXd n(2,5);
  n.resize(4,3);
  std::cout << "The matrix n is of size "
            << n.rows() << "x" << n.cols() << std::endl;
  std::cout << "It has " << n.size() << " coefficients" << std::endl;
  VectorXd d(2);
  d.resize(5);
  std::cout << "The vector v is of size " << d.size() << std::endl;
  std::cout << "As a matrix, v is of size "
            << d.rows() << "x" << d.cols() << std::endl;
  cout << endl;




  //--------矩陣的基本運算（加減運算）--------
  Matrix2d e;
  e << 1, 2,
       3, 4;
  MatrixXd f(2,2);
  f << 2, 3,
       1, 4;
  std::cout << "e + f =\n" << e + f << std::endl;
  std::cout << "e - f =\n" << e - f << std::endl;
  std::cout << "Doing e += f;" << std::endl;
  e += f;
  std::cout << "Now e =\n" << e << std::endl;
  Vector3d x(1,2,3);
  Vector3d w(1,0,0);
  std::cout << "-x + w - x =\n" << -x + w - x << std::endl;
  cout << std::endl; 
}