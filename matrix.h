#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <ostream>
#include <iomanip>
#include <cassert>
#endif  <MATRIX_H>
#include "matrix.H"


class matrix
{
public:
    matrix() ;
    //friend istream& operator>>( istream& is, matrix& m );       //for input

    //friend ostream& operator<< (ostream& os, matrix& m );       //for output

    void operator+ ( matrix m1, matrix m2 );              //for adding two matrices if the same dimensions

    void operator- ( matrix m1, matrix m2 );              //for subtracting two matrices if the same dimensions

    void operator* ( matrix m1, matrix m2 );              //for multiplying two matrices if #col of max1 equal #rows of max2

    void operator+ ( matrix m1, int n );                //for adding a scalar to the matrix

    void operator- ( matrix m1, int n );                //for subtracting a scalar from the matrix

    void operator* ( matrix m1, int n );                //for multiplying a scalar by the matrix

    void operator+= ( matrix& m1, matrix m2 );
    //maax& operator-= ( maax m1 , maax m2 );
    void operator+= ( matrix& m1, int n );
    //void operator++ (maax& m1);

    virtual ~matrix();


protected:
    int row, col ;
    int* num ;

private:


};
istream& operator>>( istream& is, matrix& m );       //for input

ostream& operator<< (ostream& os, matrix& m );       //for output

matrix::operator+ ( matrix m1, matrix m2 )
    {
        assert ( m1.row == m2.row && m1.col == m2.col );

        matrix* ptrmx = new matrix ;
        ptrmx->row =m1.row;
        ptrmx->col =m1.col;
        ptrmx->num =new int [m1.row*m1.col];     //num = the pointer

        for( int i=0 ; i<m1.row*m1.col ; i++ )
        {
            ptrmx->num[i] = m1.num[i] + m2.num[i] ;
        }
        return *ptrmx ;

    }


//for subtract two matrices

    matrix::operator- ( matrix m1, matrix m2 )
    {
        assert ( m1.row == m2.row && m1.col == m2.col );

        matrix* ptrmx = new matrix ;
        ptrmx->row =m1.row;
        ptrmx->col =m1.col;
        ptrmx->num =new int [m1.row*m1.col];     //num = the pointer

        for( int i=0 ; i<m1.row*m1.col ; i++ )
        {
            ptrmx->num[i] = m1.num[i] - m2.num[i] ;
        }
        return *ptrmx ;

    }


    /*matrix& operator* ( matrix m1 , matrix m2 )
    {   assert (m1.row == m2 .col);
        //prod[i+j] = prod[i+j] + A[i] * B[j]
        maax* ptrmx = new matrix ;
        ptrmx->row =m1.row;
        ptrmx->col =m2.col;
        ptrmx->num =new int [m1.col*m2.row];     //num = the pointer

        for( int i=0 ; i<m1.row ; i++ )
           {
             for(int j=0 ; j<m2.col ; j++)
               {
                 for(int k=0 ; k<m1.col;k++)
                  {
                     ptrmx->num[i] += m1.num[k]* m2.num[k];
                  }
               }
            ptrmx->num[i] = m1.num[i] + m1[i] * m2[k] ;
           }
        return *ptrmx ;
    }*/

//for add a scalar to a matrix

    matrix::operator+ (matrix m, int n )
    {
        cout<<"______________________________________________"<<endl;
        maax*ptrmx = new maax ;
        ptrmx->row = m.row ;
        ptrmx->col = m.col ;
        ptrmx->num = new int [m.row*m.col] ;
        for (int i=0 ; i<m.row*m.col ; i++)
        {
            ptrmx->num[i] = m.num[i];
        }
        for (int i=0 ; i<m.row*m.col ; i++)
        {
            ptrmx->num[i]=ptrmx->num[i]+n ;
        }
        return *ptrmx;

    }

//for subtract a scalar from a matrix

    int matrix:: operator- (matrix m, int n )
    {
        cout<<"/////////////////////////////////"<<endl;
        matrix*ptrmx = new matrix ;
        ptrmx->row = m.row ;
        ptrmx->col = m.col ;
        ptrmx->num = new int [m.row*m.col] ;
        for (int i=0 ; i<m.row*m.col ; i++)
        {
            ptrmx->num[i] = m.num[i];
        }
        for (int i=0 ; i<m.row*m.col ; i++)
        {
            ptrmx->num[i]=ptrmx->num[i]-n ;
        }
        return *ptrmx;

    }

//for multiply a scalar by a matrix

    matrix:: operator* (matrix m, int n )
    {
        cout<<"/////////////////////////////////"<<endl;
        matrix*ptrmx = new matrix ;
        ptrmx->row = m.row ;
        ptrmx->col = m.col ;
        ptrmx->num = new int [m.row*m.col] ;
        for (int i=0 ; i<m.row*m.col ; i++)
        {
            ptrmx->num[i] = m.num[i];
        }
        for (int i=0 ; i<m.row*m.col ; i++)
        {
            ptrmx->num[i]=ptrmx->num[i]*n ;
        }
        return *ptrmx;

    }
//_________________________________________________________________-
    matrix:: operator+= ( matrix& m1, matrix m2 )
    {

        matrix* ptrmx = new matrix ;
        ptrmx->row =m1.row;
        ptrmx->col =m1.col;
        ptrmx->num =new int [m1.row*m1.col];     //num = the pointer

        for( int i=0 ; i<m1.row*m1.col ; i++ )
        {
            ptrmx->num[i] = m1.num[i] + m2.num[i] ;
        }
        return *ptrmx ;

    }

    matrix:: operator+= (matrix& m, int n )
    {
        cout<<"______________________________________________"<<endl;
        matrix*ptrmx = new matrix ;
        ptrmx->row = m.row ;
        ptrmx->col = m.col ;
        ptrmx->num = new int [m.row*m.col] ;

        for (int i=0 ; i<m.row*m.col ; i++)
        {
            m.num[i]=m.num[i]+n ;
        }
        for (int i=0 ; i<m.row*m.col ; i++)
        {
            ptrmx->num[i] = m.num[i];
        }
        return *ptrmx;

    }

    /*void operator++ (matrix& m1)
    {
        cout<<"______________________________________________"<<endl;
        matrix*ptrmx = new matrix ;
        ptrmx->row = m.row ;
        ptrmx->col = m.col ;
        ptrmx->num = new int [m.row*m.col] ;

        for (int i=0 ; i<m.row*m.col ; i++)
        {
           m.num[i]=m.num[i]+1 ;
        }
        for (int i=0 ; i<m.row*m.col ; i++)
        {
            ptrmx->num[i] = m.num[i];
        }
        return *ptrmx;

    }*/
ostream& operator<< (ostream& os , matrix m )
{
    cout<<"The matrix of the result is: "<<endl;
    for (int i=0 ; i<m.row ; i++)
    {   cout<<endl;
        for (int k=0 ; k<m.col ; k++)

            {cout<<setw(5)<<m.num[i*m.col+k]<<" ";}

    }
    return os ;
}

istream& operator >>( istream& is , matrix m )
{   //cout<<endl<<"________________________________________"<<endl<<endl<<endl;
    cout<<"enter the number of rows and columns:  "<<endl;
    cin>> m.row >> m.col ;
    cout<<"=========================================="<<endl;
    m.num = new int [m.row * m.col];
    for (int i=0 ; i<m.row ; i++)
    {
        cout<<"enter the data of row __"<<i+1<<" : "<<endl;
        for (int k=0 ; k<m.col ; k++)
        {
            cin>>m.num[i * m.col + k];
        }
    }
    cout<<endl<<endl<<"________________________________________"<<endl<<endl;
}




matrix::~matrix()
{
    //dtor
}

