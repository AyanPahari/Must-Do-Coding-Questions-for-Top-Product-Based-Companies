class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        int n = tasks.size();
        vector<int> res; //to store the order of the process
        for (int i = 0; i < n; i++)
        {
            tasks[i].push_back(i); //each vector of the form <arrival time,burst time,id>
        }
        sort(tasks.begin(), tasks.end()); //sort the vector on the basics of arrival time

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> ready_queue; //min heap that contains pairs of <burst time,id>

        int ind = 0;        //index of the current process
        long long time = 0; //store the time instance

        while (ind < n || !ready_queue.empty())
        {
            if (ready_queue.empty())
            {
                time = max(time, (long long)tasks[ind][0]); //it will take care of the waiting time. lets say time=12 and the next arrival time
                //of the process is 13, so time will be changed to 13 accordingly.
            }
            while (ind < n && tasks[ind][0] <= time) //either the index crosses n or arrival time of process>time, we will break out
            {
                ready_queue.push({tasks[ind][1], tasks[ind][2]}); //pushing the burst time ,id into the ready queue
                ind++;
            }
            pair<int, int> currTask = ready_queue.top(); //it contains the pair whose burst time is minimum
            ready_queue.pop();
            time += currTask.first;         //adding the burst time
            res.push_back(currTask.second); //storing the id into res
        }
        return res;
    }
    //time:O(nlogn)
    //space:O(n)
};