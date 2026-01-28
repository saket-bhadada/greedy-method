#include <iostream>
#include <vector>
#include <queue>

int main()
{
    std::vector<int> A = {3, 8, 12, 20};
    std::vector<int> B = {5, 9, 11, 16};
    std::vector<int> C;
    while (A.size() > 0 && B.size() > 0)
    {
        if (A[0] < B[0])
        {
            C.push_back(A[0]);
            A.erase(A.begin());
        }
        else
        {
            C.push_back(B[0]);
            B.erase(B.begin());
        }
    }
    while (A.size() > 0)
    {
        C.push_back(A[0]);
        A.erase(A.begin());
    }
    while (B.size() > 0)
    {
        C.push_back(B[0]);
        B.erase(B.begin());
    }

    for (size_t i = 0; i < C.size(); i++)
    {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}