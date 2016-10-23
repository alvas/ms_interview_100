#include <cassert>
#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> multiply_slow(vector<vector<int>>& A, vector<vector<int>>& B) {
        //vector<vector<int>> C;
        //int rowA = A.size(), rowB = B.size();

        //if (rowA == 0 || rowB == 0) {
            //return C;
        //}

        // resize is not a good idea, pre-allocate the whole array is much better
        //int colA = A[0].size(), colB = B[0].size();
        //C.resize(rowA);

        //for (int i = 0; i < rowA; ++i) {
            //C[i].resize(colB);

            //for (int j = 0; j < colB; ++j) {
                //for (int k = 0; k < colA; ++k) {
                    // check 0 to avoid multiplication would improve it.
                    //C[i][j] += A[i][k] * B[k][j];
                //}
            //}
        //}

        //return C;


        // But this algorithm is still much slower than the one below.
        int rowA = A.size(), rowB = B.size();

        if (rowA == 0 || rowB == 0) {
            return vector<vector<int>>();
        }

        int colA = A[0].size(), colB = B[0].size();
        vector<vector<int>> C(rowA, vector<int>(colB, 0));

        for (int i = 0; i < rowA; ++i) {
            for (int j = 0; j < colB; ++j) {
                for (int k = 0; k < colA; ++k) {
                    if (A[i][k] != 0 && B[k][j] != 0) {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }

        return C;
    }

    // The order or calculation is important.
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int rowA = A.size(), rowB = B.size();

        if (rowA == 0 || rowB == 0) {
            return vector<vector<int>>();
        }

        int colA = A[0].size(), colB = B[0].size();
        vector<vector<int>> C(rowA, vector<int>(colB, 0));

        for (int i = 0; i < rowA; ++i) {
            for (int j = 0; j < rowB; ++j) {
                if (A[i][j]) {
                    for (int k = 0; k < colB; ++k) {
                        C[i][k] += A[i][j] * B[j][k];
                    }
                }
            }
        }

        return C;
    }

    typedef pair<pair<int,int>,int> pos_val; 

    vector<vector<int>> multiply_with_map(vector<vector<int>>& A, vector<vector<int>>& B) {
        if(A.empty()||A[0].empty()||B[0].empty()) return vector<vector<int>>();
        vector<pos_val> map_A,map_B; //store nonzero values of A and B
        int n=A.size(), m=B[0].size(),mid=B.size();
        vector<vector<int>> C(n,vector<int>(m,0));
        for(int i=0;i<n;++i){
            for(int j=0;j<mid;++j){
                if(A[i][j]!=0){
                    pos_val tmp(pair<int,int>(i,j),A[i][j]);
                    map_A.push_back(tmp);}
                }
          }
         for(int i=0;i<mid;++i){
            for(int j=0;j<m;++j){
                if(B[i][j]!=0){
                    pos_val tmp(pair<int,int>(i,j),B[i][j]);
                    map_B.push_back(tmp);}
                }
          }
        for(int i=0;i<map_A.size();++i){
            for(int j=0;j<map_B.size();++j){
                if(map_A[i].first.second==map_B[j].first.first)
                   C[map_A[i].first.first][map_B[j].first.second]+=map_A[i].second*map_B[j].second;
            }
        }
        
        return C;
    }
};

int main() {
    Solution sln;
    vector<vector<int>> A = {
        {1, 0, 0},
        {-1, 0, 3}
    };

    vector<vector<int>> B = {
        {7, 0, 0},
        {0, 0, 0},
        {0, 0, 1}
    };

    vector<vector<int>> C = sln.multiply(A, B);
    print2DVector<int>(C);
    return 0;
}
