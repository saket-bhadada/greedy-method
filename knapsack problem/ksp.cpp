#include <iostream>
#include <math.h>
#include <vector>
#include <array>

std::array<int, 5> profitbyweight(int (&p)[5], int (&w)[5])
{
    std::array<int, 5> pw;
    for (int i = 0; i < 5; i++)
    {
        pw[i] = p[i] / w[i];
    }
    return pw;
}

std::array<int, 5> sort(int (&q)[5], int (&p)[5], int (&w)[5], double pw[5])
{
    int n = sizeof(pw) / sizeof(pw[0]);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (pw[j] > pw[j + 1])
            {
                std::swap(pw[j], pw[j + 1]);
                std::swap(w[j], w[j + 1]);
                std::swap(q[j], q[j + 1]);
                std::swap(p[j], p[j + 1]);
            }
        }
    }
}

int main()
{
    int q[5];
    int p[5];
    int w[5];
    int cpacity = 15;
    double pw[5];

    profitbyweight(p, w);
    sort(q, p, w, pw);
}
