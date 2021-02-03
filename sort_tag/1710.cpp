// https://leetcode.com/problems/maximum-units-on-a-truck/

// sort by the second column
bool sortcol( const vector<int>& v1, const vector<int>& v2 ) { 
        return v1[1] < v2[1]; 
}

class Solution {
public:

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        //sort the box by number of units per box
        
        sort(boxTypes.begin(), boxTypes.end(), sortcol);

        int num = truckSize;
        int units = 0;
        int row = boxTypes.size() - 1;
        
        while (num >= 0 && row >= 0) {
            if (num <= boxTypes[row][0]) {
                units += num*boxTypes[row][1];
                break;
            }
            else {
                units += boxTypes[row][0]*boxTypes[row][1];
                num -= boxTypes[row--][0];
            }
        
        }
        
        return units;

    }
};