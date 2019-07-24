#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
int main()
{

//--------使用塊操作--------
    Eigen::MatrixXf m(4,4);
    m << 1,2,3,4,
         5,6,7,8,
         9,10,11,12,
         13,14,15,16;
    
    cout << "Block in the middle" << endl;
    cout << m.block<2,2>(1,1) << endl << endl;
    for(int i=1;i<=3;++i)
    {
        cout << "Block of size" << i << "x" << i <<endl;
        cout << m.block(0,0,i,i) << endl << endl;
    }



    Array22f n;
    n << 1,2,
         3,4;
    Array44f a = Array44f::Constant(0.6);
    cout << "Here is the array a:" << endl << a << endl << endl;
    a.block<2,2>(1,1) = n;
    cout << "Here is now a with n copied into its central 2x2 block:" << endl << a << endl << endl;
    a.block(0,0,2,3) = a.block(2,1,2,3);
    cout << "Here is now a with bottom-right 2x3 block copied into top-left 2x2 block:" << endl << a << endl << endl;

//--------行和列--------
    Eigen::MatrixXf o(3,3);
    o << 1,2,3,
         4,5,6,
         7,8,9;
    cout << "Here is the matrix o:" << endl << o << endl;
    cout << "2nd Row: " << o.row(1) << endl << endl;
    o.col(2) += 3 * o.col(0);
    cout << "After adding 3 times the first column into the third column, the matrix o is:\n";
    cout << o << endl << endl;

//--------角落相關--------
     Eigen::Matrix4f p;
     p << 1, 2, 3, 4,
          5, 6, 7, 8,
          9, 10,11,12,
          13,14,15,16;
     cout << "p.leftCols(2) =" << endl << p.leftCols(2) << endl << endl;
     cout << "p.bottomRows<2>() =" << endl << p.bottomRows<2>() << endl << endl;
     p.topLeftCorner(1,3) = p.bottomRightCorner(3,1).transpose();
     cout << "After assignment, p = " << endl << p << endl;


//--------向量的塊操作--------
     Eigen::ArrayXf v(6);
     v << 1, 2, 3, 4, 5, 6;
     cout << "v.head(3) =" << endl << v.head(3) << endl << endl;
     cout << "v.tail<3>() = " << endl << v.tail<3>() << endl << endl;
     v.segment(1,4) *= 2;
     cout << "after 'v.segment(1,4) *= 2', v =" << endl << v << endl;
}