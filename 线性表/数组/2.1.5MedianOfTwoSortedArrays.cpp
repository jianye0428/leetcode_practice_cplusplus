#include <iostream>
#include <cmath>
#include<vector>
#include<string>
#include<bits/stdc++.h>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>

using namespace std;

class Solution{
public:
    double findMedianSortedArrays(const vector<int>& A, const vector<int>& B){
        const int m = A.size();
        const int n = B.size();

        int total = m+n;
        if(total & 0x1){
            return find_kth(A.begin(), m, B.begin(), n, total / 2 + 1);
        }else{
            return ((find_kth(A.begin(),m, B.begin(), n, total / 2))+(A.begin(), m, B.begin(), n, total / 2 + 1))/2.0;
        }
    }
private:
    static int find_kth(std::vector<int>::const_iterator A, int m, std::vector<int>::const_iterator B, int n, int k){
        //always assume that m is equal or smaller than n
        if(m>n) return find_kth(B, n, A, m, k);
        if(m == 0) return *(B+k-1);
        if(k==1) return min(*A,*B);

        //divide k into two parts
        int ia = min(k/2, m), ib = k-ia;
        if(*(A+ia-1)<*(B+ib-1)){
            return find_kth(A+ia, m-ia, B, n,k-ia);
        }else if(*(A+ia-1)>*(B+ib-1)){
            return  find_kth(A, m, B+ib, n-ib, k-ib);
        }else{
            return A[ia-1];
        }
    }


};

int main()
{
    vector<int> A = {1,2,4,6,10};
    vector<int> B = {2,3,6,9,11};

    Solution sol;
    int a;
    a = sol.findMedianSortedArrays(A,B);
    cout << a << endl;
    return 0;
}
