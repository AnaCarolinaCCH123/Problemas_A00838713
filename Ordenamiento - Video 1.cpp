#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] < a[j + 1]) {  
                std::swap(a[j], a[j + 1]);
            }
        }
    }
}

std::string checkRemove(int n, int f, int k, std::vector<int>& a) {
    int favorite = a[f - 1];
    bubbleSort(a);
    
    int countGreater = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > favorite) {
            countGreater++;
        } else {
            break;
        }
    }

    if (countGreater >=k ) {
        return "NO";  
    } else if (countGreater < k && countGreater + std::count(a.begin() + countGreater, a.end(), favorite) <= k) {
        return "YES";  
    } else {
        return "MAYBE";  
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, f, k;
        std::cin >> n >> f >> k;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        std::cout << checkRemove(n, f, k, a) << std::endl;
    }
    return 0;
}
