#include <iostream>
#include <algorithm> // Needed for std::swap

// 1. Pass arrays and size 'n' directly.
// We pass 'pw' as an argument so we can modify it in place.
void profitbyweight(double p[], double w[], double pw[], int n)
{
    for (int i = 0; i < n; i++)
    {
        pw[i] = p[i] / w[i];
    }
}

// 2. Sort function must swap ALL arrays to keep indices aligned.
// Changed logic to Descending Order (Best items first).
void sort(double q[], double p[], double w[], double pw[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // Use '<' for Descending order (Highest Ratio First)
            if (pw[j] < pw[j + 1])
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
    double q[7] = {1, 2, 3, 4, 5, 6, 7};

    double p[7] = {10, 5, 15, 7, 6, 18, 3};
    double w[7] = {2, 3, 5, 7, 1, 4, 1};

    double pw[7];
    double capacity = 15;
    int n = 7;

    profitbyweight(p, w, pw, n);

    sort(q, p, w, pw, n);

    std::cout << "Solving knapsack problem using greedy method" << std::endl;

    double totalProfit = 0;
    double currentWeight = 0;

    for (int i = 0; i < n; i++)
    {
        if (currentWeight >= capacity)
            break;

        if (currentWeight + w[i] <= capacity)
        {
            currentWeight += w[i];
            totalProfit += p[i];
            std::cout << "Added Item " << q[i] << " (Full)" << std::endl;
        }
        else
        {
            double remaining = capacity - currentWeight;
            totalProfit += p[i] * (remaining / w[i]);
            std::cout << "Added Item " << q[i] << " (Fraction: " << remaining << "/" << w[i] << ")" << std::endl;
            currentWeight = capacity;
            break;
        }
    }

    std::cout << "Total Profit: " << totalProfit << std::endl;

    return 0;
}