// Last updated: 11/2/2025, 10:29:55 PM
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int>keys(rooms.size()+1,0);
        int n = rooms.size();
        int room = 0;
        int flag = 0;
        queue<int>q;
        q.push(0);
        while(!q.empty())
        {
            int curr_room = q.front();
            keys[curr_room] = 1;
            q.pop();
            for(int i=0;i<rooms[curr_room].size();i++)
            {
                if(keys[rooms[curr_room][i]]==0)
                {
                q.push(rooms[curr_room][i]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(keys[i]==0)
            {
                return false;
            }
        }
        return true;
    }
};