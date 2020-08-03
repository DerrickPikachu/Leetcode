/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*>& employees, int id) {
        int ans=0,i,index=0;
        while(id != employees[index]->id)
            index++;
        if (employees[index]->subordinates.empty())    return employees[index]
            ->importance;
        //check the end
        for (i=0;i<employees[index]->subordinates.size();i++)
            ans += getImportance(employees,employees[index]->subordinates[i]);
        ans += employees[index]->importance;
        return ans;
    }
};
