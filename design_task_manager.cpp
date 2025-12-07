#include<iostream>
#include <set>
using namespace std;

class TaskManager {
public:
    unordered_map<int, pair<int, int>> mp;          // taskId -> {userId, priority}
    set<pair<int, int>> st;              // {priority, taskId}

    TaskManager(vector<vector<int>>& tasks) {
        for (auto it : tasks) {
            st.insert({it[2], it[1]});    // {priority, taskId}
            mp[it[1]] = {it[0], it[2]};   // taskId -> {userId, priority}
        }
    }
    
    void add(int userId, int taskId, int priority) {
        st.insert({priority, taskId});
        mp[taskId] = {userId, priority};
    }
    
    void edit(int taskId, int newPriority) {
        pair<int, int> p = mp[taskId];     // {userId, priority}
        st.erase({p.second, taskId});      // remove old {priority, taskId}
        st.insert({newPriority, taskId});  // insert new {priority, taskId}
        mp[taskId] = {p.first, newPriority};
    }
    
    void rmv(int taskId) {
        pair<int, int> p = mp[taskId];     // {userId, priority}
        st.erase({p.second, taskId});      // remove from set
        mp.erase(taskId);                  // remove from map
    }
    
    int execTop() {
        if (mp.empty()) return -1;
        auto it = st.end();
        it--;                              // highest priority (and highest taskId on tie)
        pair<int, int> p = *it;
        int ans = mp[p.second].first;      // userId
        mp.erase(p.second);                // remove from map
        st.erase(it);                      // remove from set
        return ans;
    }
};

int main() {
    // Initial tasks: [userId, taskId, priority]
    vector<vector<int>> initTasks = {{1, 101, 10}, {2, 102, 20}, {3, 103, 15}};
    TaskManager taskManager(initTasks);

    taskManager.add(4, 104, 5);  // Adds task 104 with priority 5 for User 4
    taskManager.edit(102, 8);    // Updates priority of task 102 to 8

    cout << taskManager.execTop() << endl; // Executes 103, returns 3

    taskManager.rmv(101);        // Removes task 101

    taskManager.add(5, 105, 15); // Adds task 105 with priority 15 for User 5

    cout << taskManager.execTop() << endl; // Executes 105, returns 5

    return 0;
}