#include <iostream>
#include <vector>

int find_max(const std::vector<int>& numbers) {
    // 打印输入数据
    std::cout << "Input size: " << numbers.size() << std::endl;
    
    if (numbers.empty()) {
        std::cout << "Empty vector!" << std::endl;
        return -1;
    }
    
    int max_num = numbers[0];
    for (int num : numbers) {
        std::cout << "Current number: " << num 
                  << ", Current max: " << max_num << std::endl;
        if (num > max_num) {
            max_num = num;
        }
    }
    
    return max_num;
} 