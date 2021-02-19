// https://leetcode.com/problems/can-place-flowers/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0)
            return true;
        
        if (flowerbed.size() == 1) {
            if (flowerbed[0] == 0 && n == 1)
                return true;
            else
                return false;
        }
            
        int flower = 0;
        // [1,0,0,0,1] 0 1 0, 1 0 1
        // [0,1,0,0,1]
        // [0,1,0,1,1,0,0]
        for (int i = 0; i < flowerbed.size(); i++) {
            
            if (i == 0) {
                if(flowerbed[i] == 0 && flowerbed[i+1] == 0) {
                    flowerbed[i] = 1;
                    flower++;
                }
            }
            else if (i == flowerbed.size()-1){
                if(flowerbed[i] == 0 && flowerbed[i-1] == 0) {
                        flowerbed[i] = 1;
                        flower++;
                    }
            }
            else {
                if (flowerbed[i] == 0 && flowerbed[i+1] == 0 && flowerbed[i-1] == 0) {
                    flowerbed[i] = 1;
                    flower++;
                }
            }
        
        }
        
        // print 
        // for (int i = 0; i < flowerbed.size(); i++)
        //     cout << flowerbed[i] << " ";
        
        if (flower < n)
            return false;
        
        return true;
    }
};

// [1,0,1,0,0,1]

// another solution:
/*
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);
        for(int i = 1; i < flowerbed.size()-1; ++i)
        {
            if(flowerbed[i-1] + flowerbed[i] + flowerbed[i+1] == 0)
            {
                --n;
                ++i;
            }
                
        }
        return n <=0;
    }
};
*/