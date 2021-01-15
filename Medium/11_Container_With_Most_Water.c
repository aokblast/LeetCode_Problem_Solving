// Method 1(23.32, 97.15)

int maxArea(int* height, int heightSize) {
    int max = 0;
    for (int i=0; i < heightSize; i++) {
        for (int j=i+1; j < heightSize; j++) {
            int area = (j-i)*(height[i] > height[j] ? height[j] : height[i] );
            if (area > max ) {
                max = area;
            }
        }
    }
    
    return max;
}

// Method 2(97.65, 34.06)

int maxArea(int* height, int heightSize) {
    int max = 0;
    for (int i=0, j = heightSize - 1; i < j;) {
        int area = (j-i)*(height[i] < height[j] ? height[i++] : height[j--]);
        max = max > area? max : area;
    }
    
    return max;
}

// Method 3(97.65, 73.66)

int maxArea(int* height, int heightSize) {
    int max = 0,*i = height, *j = height + heightSize - 1;
    while (i < j) {
        int minh = (*i > *j ? *j : *i);
        int area = (j - i) * minh;
        if (area > max) max = area;
        while(*i <= minh && i < j) i++;
        while(*j <= minh && i < j) j--;
    }
    return max;
}