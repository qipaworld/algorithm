class Solution {
public:
    int getNum(vector<int>& array,int start_id, int end_id)
    {
        int num = 0;
        int start_num = array[start_id] < array[end_id] ? array[start_id] : array[end_id];
        for (int i = start_id + 1; i < end_id; i++)
        {
            int temp = start_num - array[i];
            num += (temp > 0 ? temp : 0);
        }
        return num;
    }
    
    int* getIndex(vector<int>& array,int start_id, int end_id)
    {
        int height[2] = { array[start_id] < array[end_id] ? array[start_id] : array[end_id],-1 };
        int *index = new int[2];
        if (end_id - start_id < 2)
        {
            return NULL;
        }
        for (int i = start_id; i <= end_id; i++)
        {
            int temp = array[i];
            if (temp >= height[1])
            {
                if (temp >= height[0])
                {
                    height[1] = height[0];
                    index[1] = index[0];
                    height[0] = temp;
                    index[0] = i;
                }
                else if (i != index[0])
                {
                    height[1] = temp;
                    index[1] = i;
                }
            }
        }
        return index;
    }
    
    int compute_left(vector<int>& array, int start_id, int end_id)
    {
        int* index = getIndex(array, start_id, end_id);
    
        if (!index)
        {
            return 0;
        }
        int min_index = 0;
        int max_index = 0;
        if (index[0] < index[1])
        {
            min_index = index[0];
            max_index = index[1];
        }
        else
        {
            min_index = index[1];
            max_index = index[0];
        }
        delete[]index;
        int num_1 = compute_left(array, 0, min_index);
        int num_3 = getNum(array, min_index, max_index);
        return  num_1 + num_3;
    }
    
    
    int compute_right(vector<int>& array, int start_id, int end_id)
    {
    
        int* index = getIndex(array, start_id, end_id);
    
        if (!index)
        {
            return 0;
        }
        int min_index = 0;
        int max_index = 0;
        if (index[0] < index[1])
        {
            min_index = index[0];
            max_index = index[1];
        }
        else
        {
            min_index = index[1];
            max_index = index[0];
        }
        delete[]index;
        int num_2 = compute_right(array, max_index, array.size()-1);
        int num_3 = getNum(array, min_index, max_index);
        return  num_2 + num_3;
    }
    
    int compute(vector<int>& array)
    {
        int* index = getIndex(array,0,array.size() - 1);
    
        if (!index)
        {
            return 0;
        }
        int min_index = 0;
        int max_index = 0;
        if (index[0] < index[1])
        {
            min_index = index[0];
            max_index = index[1];
        }
        else
        {
            min_index = index[1];
            max_index = index[0];
        }
        delete[]index;
        int num_1 = compute_left(array,0, min_index);
        int num_2 = compute_right(array,max_index, array.size() - 1);
        int num_3 = getNum(array,min_index, max_index);
    
        return  num_1 + num_2 + num_3;
    }


    int trap(vector<int>& height) //这里是入口（onStart）
    {
        if(height.size() == 0)
        {
            return 0;
        }
        return compute(height);
    }

};