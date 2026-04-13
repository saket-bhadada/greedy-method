#include <iostream>
#include <vector>

std::vector<int> profit(std::vector<int> jobs,std::vector<int> profit,std::vector<int> deadlines,int limit)
{
    // sorting on the basis of max profit
    int n = profit.size();
    for(int i=0;i<n-1;i++) 
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(profit[j]<profit[j+1])
            {
                std::swap(profit[j],profit[j+1]);
                std::swap(jobs[j],jobs[j+1]);
                std::swap(deadlines[j],deadlines[j+1]);
            }
        }
    }
    // finding deadline
    int deadline=0;
    for(int i=0;i<deadlines.size();i++)
    {
        if(deadline<deadlines[i])
        {
            deadline = deadlines[i]
        }
    }
    std::vector<int> sequence;
    // sequencing the jobs on the basis of deadline
    for(int i=0;i<n;i++)
    {
        if(sequence[i]!=0)
        {
            for(int j=i;j>0;j--)
            {
                if(sequence[j]==0)
                {
                    sequence.push_back()
                }
            }
        }
    }
}