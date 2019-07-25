#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main()
{
//--------reductions---------
    Eigen::Matrix2d mat;
    mat << 1, 2,
           3, 4;
    cout << "Here is mat.sum():       " << mat.sum()       << endl;
    cout << "Here is mat.prod():      " << mat.prod()      << endl;
    cout << "Here is mat.mean():      " << mat.mean()      << endl;
    cout << "Here is mat.minCoeff():  " << mat.minCoeff()  << endl;
    cout << "Here is mat.maxCoeff():  " << mat.maxCoeff()  << endl;
    cout << "Here is mat.trace():     " << mat.trace()     << endl;

//--------Norm computations--------
    VectorXf v(2);
    MatrixXf m(2,2), n(2,2);
  
    v << -1,
          2;
  
    m << 1,-2,
        -3,4;

    cout << "v.squaredNorm() = " << v.squaredNorm() << endl;
    cout << "v.norm() = " << v.norm() << endl;
    cout << "v.lpNorm<1>() = " << v.lpNorm<1>() << endl;
    cout << "v.lpNorm<Infinity>() = " << v.lpNorm<Infinity>() << endl;
    cout << endl;
    cout << "m.squaredNorm() = " << m.squaredNorm() << endl;
    cout << "m.norm() = " << m.norm() << endl;
    cout << "m.lpNorm<1>() = " << m.lpNorm<1>() << endl;
    cout << "m.lpNorm<Infinity>() = " << m.lpNorm<Infinity>() << endl;

    MatrixXf m(2,2);
    m << 1,-2,
         -3,4;
    cout << "1-norm(m)     = " << m.cwiseAbs().colwise().sum().maxCoeff()
         << " == "             << m.colwise().lpNorm<1>().maxCoeff() << endl;
    cout << "infty-norm(m) = " << m.cwiseAbs().rowwise().sum().maxCoeff()
         << " == "             << m.rowwise().lpNorm<1>().maxCoeff() << endl;

//--------Boolean reductions--------

    ArrayXXf a(2,2);
  
    a << 1,2,
         3,4;
    cout << "(a > 0).all()   = " << (a > 0).all() << endl;
    cout << "(a > 0).any()   = " << (a > 0).any() << endl;
    cout << "(a > 0).count() = " << (a > 0).count() << endl;
    cout << endl;
    cout << "(a > 2).all()   = " << (a > 2).all() << endl;
    cout << "(a > 2).any()   = " << (a > 2).any() << endl;
    cout << "(a > 2).count() = " << (a > 2).count() << endl;

//--------User defined reductions--------

    //--------(Visitors)--------
    Eigen::MatrixXf m(2,2);
  
    m << 1, 2,
         3, 4;
    //get location of maximum
    MatrixXf::Index maxRow, maxCol;
    float max = m.maxCoeff(&maxRow, &maxCol);
    //get location of minimum
    MatrixXf::Index minRow, minCol;
    float min = m.minCoeff(&minRow, &minCol);
    cout << "Max: " << max <<  ", at: " <<
    maxRow << "," << maxCol << endl;
    cout << "Min: " << min << ", at: " <<
    minRow << "," << minCol << endl;

    //--------(Partial reductions)--------
    Eigen::MatrixXf mat(2,4);
    mat << 1, 2, 6, 9,
           3, 1, 7, 2;
  
    std::cout << "Column's maximum: " << std::endl
              << mat.colwise().maxCoeff() << std::endl;

    Eigen::MatrixXf mat(2,4);
    mat << 1, 2, 6, 9,
           3, 1, 7, 2;
  
    std::cout << "Row's maximum: " << std::endl
              << mat.rowwise().maxCoeff() << std::endl;


//--------Combining partial reductions with other operations

    MatrixXf mat(2,4);
    mat << 1, 2, 6, 9,
           3, 1, 7, 2;
  
    MatrixXf::Index   maxIndex;
    float maxNorm = mat.colwise().sum().maxCoeff(&maxIndex);
  
    std::cout << "Maximum sum at position " << maxIndex << std::endl;
    std::cout << "The corresponding vector is: " << std::endl;
    std::cout << mat.col( maxIndex ) << std::endl;
    std::cout << "And its sum is is: " << maxNorm << std::endl;

    
    //--------Broadcasting--------
    Eigen::MatrixXf mat(2,4);
    Eigen::VectorXf v(2);
  
    mat << 1, 2, 6, 9,
           3, 1, 7, 2;
         
    v << 0,
         1;
       
    //add v to each column of m
    mat.colwise() += v;
  
    std::cout << "Broadcasting result: " << std::endl;
    std::cout << mat << std::endl;

     
     

    
    Eigen::MatrixXf mat(2,4);
    Eigen::VectorXf v(4);
  
    mat << 1, 2, 6, 9,
           3, 1, 7, 2;
         
    v << 0,1,2,3;
       
    //add v to each row of m
    mat.rowwise() += v.transpose();
  
    std::cout << "Broadcasting result: " << std::endl;
    std::cout << mat << std::endl;


//--------Combining broadcasting with other operations---------
    Eigen::MatrixXf m(2,4);
    Eigen::VectorXf v(2);
  
    m << 1, 23, 6, 9,
         3, 11, 7, 2;
       
    v << 2,
         3;
    MatrixXf::Index index;
    // find nearest neighbour
    (m.colwise() - v).colwise().squaredNorm().minCoeff(&index);
    cout << "Nearest neighbour is column " << index << ":" << endl;
    cout << m.col(index) << endl;
}