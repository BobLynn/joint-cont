//----Matrix and vector arithmetic Part2----
#include <iostream>
#include <Eigen/Dense>
using namespace std;

//----矩陣、向量的乘除（乘以小於一的數）----
using namespace Eigen;

int main ()
{
    Matrix2d a;
    a << 1, 2,
         3, 4;

    Vector3d v(1,2,3);
    std::cout << "a * 2.5 =\n" << a * 2.5 << std::endl;
    std::cout << "0.1 * v =\n" << 0.1 * v << std::endl;
    std::cout << "Doing v *= 2;" << std::endl;
    v *=2;
    std::cout << "Now v = \n" << v << std::endl;
    std::cout << std::endl;


//----矩陣的轉置、共軛矩陣、餘因子矩陣----
    MatrixXcf b = MatrixXcf::Random(2,2);
    std::cout << "Here is the matrix b\n" << b << std::endl;
    std::cout << "Here is the matrix b^T\n" << b.transpose() << std::endl;
    std::cout << "Here is the conjugate of b\n" << b.conjugate() << std::endl;
    std::cout << "Here is the matrix b^*\n" << b.adjoint() << std::endl;
    std::cout << std::endl;
//----矩陣的自身計算評估----

    Eigen::Matrix2d mat;
    mat << 1, 2,
           3, 4;
    std::cout << "Here is mat.sum():       " << mat.sum()       << std::endl;
    std::cout << "Here is mat.prod():      " << mat.prod()      << std::endl;
    std::cout << "Here is mat.mean():      " << mat.mean()      << std::endl;
    std::cout << "Here is mat.minCoeff():  " << mat.minCoeff()  << std::endl;
    std::cout << "Here is mat.maxCoeff():  " << mat.maxCoeff()  << std::endl;
    std::cout << "Here is mat.trace():     " << mat.trace()     << std::endl;

//----換位和結合----

    MatrixXcf g = MatrixXcf::Random(2,2);
    cout << "Here is the matrix g\n" << g << endl;
    cout << "Here is the matrix g^T\n" << g.transpose() << endl;
    cout << "Here is the conjugate of g\n" << g.conjugate() << endl;
    cout << "Here is the matrix g^*\n" << g.adjoint() << endl;

    }