//----Matrix and vector arithmetic Part2----
#include <iostream>
#include <Eigen/Dense>



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



//----矩陣的轉置、共軛矩陣、餘因子矩陣----
    MatrixXcf b = MatrixXcf::Random(2,2);
    std::cout << "Here is the matrix b\n" << b << std::endl;
    std::cout << "Here is the matrix b^T\n" << b.transpose() << std::endl;
    std::cout << "Here is the conjugate of b\n" << b.conjugate() << std::endl;
    std::cout << "Here is the matrix b^*\n" << b.adjoint() << std::endl;

    }