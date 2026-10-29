#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // Initialize an n x n matrix with zeros
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        // Define the initial boundaries
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        
        int num = 1; // Start filling with number 1
        
        while (top <= bottom && left <= right) {
            // 1. Move from Left to Right across the top row
            for (int i = left; i <= right; ++i) {
                matrix[top][i] = num++;
            }
            top++; // Move the top boundary down
            
            // 2. Move from Top to Bottom down the rightmost column
            for (int i = top; i <= bottom; ++i) {
                matrix[i][right] = num++;
            }
            right--; // Move the right boundary left
            
            // 3. Move from Right to Left across the bottom row
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    matrix[bottom][i] = num++;
                }
                bottom--; // Move the bottom boundary up
            }
            
            // 4. Move from Bottom to Top up the leftmost column
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    matrix[i][left] = num++;
                }
                left++; // Move the left boundary right
            }
        }
        
        return matrix;
    }
};
