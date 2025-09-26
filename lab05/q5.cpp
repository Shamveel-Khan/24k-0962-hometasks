#include <iostream>
using namespace std;

int sumDigits(int num) {
    if (num == 0) {
        return 0;
    }
    return (num % 10) + sumDigits(num / 10);
}

int nestedSum(int num) {
    int sum = sumDigits(num);
    if (sum / 10 == 0) {
        return sum;
    }
    return nestedSum(sum);
}

int main() {
    cout << "Enter your number: ";
    int num;
    cin >> num;
    int result = nestedSum(num);
    cout << "The final single-digit sum is: " << result << endl;
    return 0;
}
