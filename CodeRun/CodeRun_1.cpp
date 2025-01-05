#include <iostream>
#include <vector>
#include <algorithm> 

int main()
{
    const int len = 3;
    std::vector<int> arr(len);
    for (int i = 0; i < arr.size(); ++i)
    {
        std::cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    std::cout << arr[1] << std::endl;

    return 0;
}