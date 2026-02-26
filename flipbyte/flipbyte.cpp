#include <iostream>
#include <string>


using namespace std;


const string ERROR_COUNT = "Неверное количество входных данных";
const string ERROR_SYMBOLS = "Присутствуют посторонние символы";
const string ERROR_RANGE = "Число должно быть в диапазоне от 0 до 255";


unsigned char flipbyte(unsigned char n) {
    unsigned char result = 0;
    for (int i = 0; i < 8; i++) {
        result <<= 1;
        result |= (n & 1);
        n >>= 1;
    }
    return result;
}

bool isValid(int argc, char* argv[], int& outNumber) {
    if (argc != 2) {
        cerr << ERROR_COUNT << endl;
        return false;
    }

    string s = argv[1];
    if (s.empty() || s.find_first_not_of("0123456789") != string::npos) {
        cerr << ERROR_SYMBOLS << endl;
        return false;
    }

    long temp = stol(s);
    if (temp < 0 || temp > 255) {
        cerr << ERROR_RANGE << endl;
        return false;
    }

    outNumber = (int)temp;
    return true;
}

int main(int argc, char* argv[]) {
    int number;
    if (!isValid(argc, argv, number)) {
        return 1;
    }

    unsigned char input = static_cast<unsigned char>(number);
    unsigned char output = flipbyte(input);

    cout << static_cast<int>(output) << endl;

    return 0;
}