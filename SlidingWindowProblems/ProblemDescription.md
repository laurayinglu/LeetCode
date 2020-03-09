## Maximum subarray problem

The key is using DP. First, we may consider to split it into sub problem submax(A[], int i, int j), but it's hard to find a 
solution. Then we can consider using submax(A[], int i) (supposing starting from 0). In this case, the important i=part is checking
if the current subarray sum > 0 or not.
