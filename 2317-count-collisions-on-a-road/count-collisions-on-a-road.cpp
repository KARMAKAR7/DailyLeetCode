class Solution {
public:
    int countCollisions(string directions) {
    int n = directions.size();
    int left = 0, right = n - 1;

   
    while (left < n && directions[left] == 'L') 
        left++;

    // cout << left << " ";
   
    while (right >= 0 && directions[right] == 'R') 
        right--;
    // cout << right << " ";
    int collisions = 0;


    for (int i = left; i <= right; i++) {
        if (directions[i] == 'L' || directions[i] == 'R')
            collisions++;
    }

    return collisions;
    }
};