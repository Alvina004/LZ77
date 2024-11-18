#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Token {
    int position;  
    int length; 
    char nextChar; 
};

string lz77Compress(const string& input, int maxWindowSize, int maxMatchLength) {
    string result;
    int currentPos = 0;
    int inputSize = input.size();

    while (currentPos < inputSize) {
        int matchLength = 0;
        int matchOffset = 0;

        int windowStart = max(0, currentPos - maxWindowSize);
        for (int i = windowStart; i < currentPos; i++) {
            int j = 0;
            while (j < maxMatchLength && currentPos + j < inputSize && input[i + j] == input[currentPos + j]) {
                j++;
            }
            if (j > matchLength) {
                matchLength = j;
                matchOffset = currentPos - i;
            }
        }

        char nextChar = (currentPos + matchLength < inputSize) ? input[currentPos + matchLength] : '\0';

        if (matchLength > 1) {
            result += "[" + to_string(matchOffset) + "|" + to_string(matchLength) + "]";
        } else {
            result += input[currentPos];
        }

        currentPos += max(matchLength, 1);
    }

    return result;
}

int main() {
    int maxWindowSize = 64;   
    int maxMatchLength = 15;  

    string input1 = "The rain in Spain falls mainly in the plain, and the plain in Spain is mainly wet with rain";
    string compressed1= lz77Compress(input1, maxWindowSize, maxMatchLength);
    cout << "Original String: " << input1 << "\n";
    cout << "Compressed String: " << compressed1 << "\n";

    string input2 = "She sells seashells by the seashore. The shells she sells are surely seashells.";
    string compressed2 = lz77Compress(input2, maxWindowSize, maxMatchLength);
    cout << "Original String: " << input2 << "\n";
    cout << "Compressed String: " << compressed2 << "\n";


    return 0;
}
