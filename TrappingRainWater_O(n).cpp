
class Solution {
public:
    
    int front_wall = 0;
    int back_wall = 0;
    int front_index = 0;
    int back_index = 0;
    int water = 0;
    int index = 0;
    int wall = 0;
    int increment = 0;
    
    void update()
    {
        if (front_wall < back_wall)
        {
            index = front_index;
            wall = front_wall;
            increment = 1;
        }
        else
        {
            index = back_index;
            wall = back_wall;
            increment = -1;
        }
    }
    int getWater(vector<int> array)
    {
        front_wall = array.front();
        back_wall = array.back();
        front_index = 0;
        back_index = array.size() - 1;
        water = 0;
        index = 0;
        wall = 0;
        increment = 0;
        update();
        while (true)
        {
            index += increment;
            if (index == front_index || index == back_index)
            {
                break;
            }
            int temp_wall = array[index];
            if (wall >= temp_wall)
            {
                water += (wall - temp_wall);
            }
            else 
            {
                wall = temp_wall;
                if (increment<0)
                {
                    back_wall = wall;
                    back_index = index;
                }
                else 
                {
                    front_index = index;
                    front_wall = wall;
                }
                update();
            }
        }
        return water;
    }

    int trap(vector<int>& height) //这里是入口（onStart）
    {
        if(height.size() < 2)
        {
            return 0;
        }
        return getWater(height);
    }

};