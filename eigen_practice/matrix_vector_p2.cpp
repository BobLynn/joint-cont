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

//----矩陣的轉置----

    MatrixXf h (2,3);
    h << 1,2,3,4,5,6;
    cout << "Here is the initial matrix h:\n" << h <<endl;

    h.transposeInPlace();
    cout << "and after being transposed:\n"<< h << endl;

//----矩陣-矩陣以及矩陣-向量乘法----
    Matrix2d mat;
    mat << 1, 2,
           3, 4;
    Vector2d u(-1,1), v(2,0);
    std::cout << "Here is mat*mat:\n" << mat*mat << std::endl;
    std::cout << "Here is mat*u:\n" << mat*u << std::endl;
    std::cout << "Here is u^T*mat:\n" << u.transpose()*mat << std::endl;
    std::cout << "Here is u^T*v:\n" << u.transpose()*v << std::endl;
    std::cout << "Here is u*v^T:\n" << u*v.transpose() << std::endl;
    std::cout << "Let's multiply mat by itself" << std::endl;
    mat = mat*mat;
    std::cout << "Now mat is mat:\n" << mat << std::endl;

//----點積與叉積----

    Vector3d x(1,2,3);
    Vector3d y(0,1,2);
    cout << "Dot product: " << x.dot(y) << endl;
    double dp = x.adjoint()*y; // automatic conversion of the inner product to a scalar
    cout << "Dot product via a matrix product: " << dp << endl;
    cout << "Cross product:\n" << x.cross(y) << endl;

//----基本算數減少操作----

    Eigen::Matrix2d mat;
    mat << 1, 2,
           3, 4;
    cout << "Here is mat.sum():       " << mat.sum()       << endl;
    cout << "Here is mat.prod():      " << mat.prod()      << endl;
    cout << "Here is mat.mean():      " << mat.mean()      << endl;
    cout << "Here is mat.minCoeff():  " << mat.minCoeff()  << endl;
    cout << "Here is mat.maxCoeff():  " << mat.maxCoeff()  << endl;
    cout << "Here is mat.trace():     " << mat.trace()     << endl;

    Matrix3f m = Matrix3f::Random();
    std::ptrdiff_t i, j;
    float minOfM = m.minCoeff(&i,&j);
    cout << "Here is the matrix m:\n" << m << endl;
    cout << "Its minimum coefficient (" << minOfM 
         << ") is at position (" << i << "," << j << ")\n\n";
    RowVector4i v = RowVector4i::Random();
    int maxOfV = v.maxCoeff(&i);
    cout << "Here is the vector v: " << v << endl;
    cout << "Its maximum coefficient (" << maxOfV 
         << ") is at position " << i << endl;
}