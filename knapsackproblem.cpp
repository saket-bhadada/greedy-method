#include <iostream>
#include <array>

int main()
{
    int noobject = 7;
    int bag_capacity = 15;
    int object[7] = {1, 2, 3, 4, 5, 6, 7};
    int profit[7] = {10, 5, 15, 7, 6, 18, 3};
    int weight[7] = {2, 3, 5, 7, 1, 4, 1};
    float profitbyweight[7];
    // selecting objects on the basis of profit by weight
    for (int i = 0; i < noobject; i++)
    {
        profitbyweight[i] = profit[i] / weight[i];
    }
    // applying greedy method for selcting objects for maximum profit
    float x[7] = {0};
    // sorting profitbyweight
    for (int i = 0; i < noobject; i++)
    {
        for (int j = i + 1; j < noobject; j++)
        {
            if (profitbyweight[i] < profitbyweight[j])
            {
                std::swap(profitbyweight[i], profitbyweight[j]);
                std::swap(profit[i], profit[j]);
                std::swap(weight[i], weight[j]);
                std::swap(object[i], object[j]);
            }
        }
    }
    float totalprofit = 0;
    int reamainingcapacity = bag_capacity;
    for (int i = 0; i < noobject; i++)
    {
        if (weight[i] <= reamainingcapacity)
        {
            x[i] = 1;
            totalprofit += profit[i];
            reamainingcapacity -= weight[i];
        }
        else
        {
            x[i] = (float)reamainingcapacity / weight[i];
            totalprofit += profit[i] * x[i];
            reamainingcapacity -= weight[i];
            break;
        }
    }
    std::cout << "objects to pick:\n";
    for (int i = 0; i < noobject; i++)
    {
        if (x[i] != 0)
        {
            std::cout << object[i] << " number of this object fraction:" << x[i] << "\n";
        }
    }
    std::cout << "total profit : " << totalprofit;
    return 0;
}