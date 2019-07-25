#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

int main()
{
//--------The comma initializer--------
    RowVectorXd vec1(3);
    vec1 << 1, 2, 3;
    std::cout << "vec1 = " << vec1 << std::endl;
    RowVectorXd vec2(4);
    vec2 << 1, 4, 9, 16;
    std::cout << "vec2 = " << vec2 << std::endl;
    RowVectorXd joined(7);
    joined << vec1, vec2;
    std::cout << "joined = " << joined << std::endl << endl;

    MatrixXf matA(2, 2);
    matA << 1, 2, 3, 4;
    MatrixXf matB(4, 4);
    matB << matA, matA/10, matA/10, matA;
    std::cout << matB << std::endl << endl;

    Matrix3f m;
    m.row(0) << 1, 2, 3;
    m.block(1,0,2,2) << 4, 5, 7, 8;
    m.col(2).tail(2) << 6, 9;                   
    std::cout << m << endl;


//--------Special matrices and arrays--------
    std::cout << "A fixed-size array:\n";
    Array33f a1 = Array33f::Zero();
    std::cout << a1 << "\n\n";
    std::cout << "A one-dimensional dynamic-size array:\n";
    ArrayXf a2 = ArrayXf::Zero(3);
    std::cout << a2 << "\n\n";
    std::cout << "A two-dimensional dynamic-size array:\n";
    ArrayXXf a3 = ArrayXXf::Zero(3, 4);
    std::cout << a3 << "\n";

    ArrayXXf table(10, 4);
    table.col(0) = ArrayXf::LinSpaced(10, 0, 90);
    table.col(1) = M_PI / 180 * table.col(0);
    table.col(2) = table.col(1).sin();
    table.col(3) = table.col(1).cos();
    std::cout << "  Degrees   Radians      Sine    Cosine\n";
    std::cout << table << std::endl;

    const int size = 6;
    MatrixXd mat1(size, size);
    mat1.topLeftCorner(size/2, size/2)     = MatrixXd::Zero(size/2, size/2);
    mat1.topRightCorner(size/2, size/2)    = MatrixXd::Identity(size/2, size/2);
    mat1.bottomLeftCorner(size/2, size/2)  = MatrixXd::Identity(size/2, size/2);
    mat1.bottomRightCorner(size/2, size/2) = MatrixXd::Zero(size/2, size/2);
    std::cout << mat1 << std::endl << std::endl;
    MatrixXd mat2(size, size);
    mat2.topLeftCorner(size/2, size/2).setZero();
    mat2.topRightCorner(size/2, size/2).setIdentity();
    mat2.bottomLeftCorner(size/2, size/2).setIdentity();
    mat2.bottomRightCorner(size/2, size/2).setZero();
    std::cout << mat2 << std::endl << std::endl;
    MatrixXd mat3(size, size);
    mat3 << MatrixXd::Zero(size/2, size/2), MatrixXd::Identity(size/2, size/2),
    MatrixXd::Identity(size/2, size/2), MatrixXd::Zero(size/2, size/2);
    std::cout << mat3 << std::endl;

//--------Usage as temporary objects--------

    
    MatrixXd n = MatrixXd::Random(3,3);
    n = (n + MatrixXd::Constant(3,3,1.2)) * 50;
    cout << "n =" << endl << n << endl;
    VectorXd v(3);
    v << 1, 2, 3;
    cout << "n * v =" << endl << n * v << endl;

    MatrixXf mat = MatrixXf::Random(2, 3);
    std::cout << mat << std::endl << std::endl;
    mat = (MatrixXf(2,2) << 0, 1, 1, 0).finished() * mat;
    std::cout << mat << std::endl;
}