#include <iostream>
#include <vector>

std::vector<int> jobSequence(std::vector<int> &jobs,std::vector<int> &profit,std::vector<int> &deadlines,int limit)
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
            deadline = deadlines[i];
        }
    }
    std::vector<int> sequence(deadline,0);
    std::cout << "sequence: " << sequence.size() << std::endl;
    std::vector<int> result;
    // sequencing the jobs on the basis of deadline
    for(int i=0;i<n;i++)
    {
        // Try to place the job in the latest available slot up to its deadline
        for(int j=deadlines[i]-1;j>=0;j--)
        {
            if(sequence[j]==0)
            {
                sequence[j] = jobs[i];
                result.push_back(jobs[i]);
                break;
            }
        }
    }
    return result;
}

int main()
{
    std::vector<int> jobs = {1,2,3,4,5};
    std::vector<int> profit = {20,15,10,5,1};
    std::vector<int> deadlines = {2,2,1,3,3};
    std::vector<int> result = jobSequence(jobs,profit,deadlines,5);
    for(int i=0;i<result.size();i++)
    {
        std::cout << result[i] << " ";
    }
    return 0;
}