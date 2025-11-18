#include <iostream>
using namespace std;

template <typename T>
class GenericArray
{
private:
    T *data;
    int length;

public:
    GenericArray() {
        data = NULL;
        length = 0;
    }

    ~GenericArray() {
        delete [] data;
    }

    void addElement(T value) {
        int newLength = length + 1;
        T *newData = new T[newLength];

        for (int i = 0; i < length; i++) {
            newData[i] = data[i];
        }

        newData[length] = value;

        delete [] data;

        data = newData;
        length = newLength;
    }

    int size() {
        return length;
    }

    T at(int index) {
        bool valid = (index >= 0 && index < length);

        if (valid) {
            return data[index];
        } else {
            cout << "Index out of bounds.\n";
            T defaultValue = T();
            return defaultValue;
        }
    }

    T sum() {
        T total = 0;

        for (int i = 0; i < length; i++) {
            total = total + data[i];
        }

        return total;
    }

    T max() {
        if (length == 0) {
            cout << "max() called on empty array.\n";
            T def = T();
            return def;
        }

        T currentMax = data[0];

        for (int i = 1; i < length; i++) {
            if (data[i] > currentMax) {
                currentMax = data[i];
            }
        }

        return currentMax;
    }

    T min() {
        if (length == 0) {
            cout << "min() called on empty array.\n";
            T def = T();
            return def;
        }

        T currentMin = data[0];

        for (int i = 1; i < length; i++) {
            if (data[i] < currentMin) {
                currentMin = data[i];
            }
        }

        return currentMin;
    }

    T* slice(int begin, int end) {
        bool validBegin = (begin >= 1);
        bool validEnd = (end <= length);
        bool correctOrder = (begin <= end);

        if (!validBegin || !validEnd || !correctOrder) {
            cout << "Invalid slice bounds.\n";
            return NULL;
        }

        int sliceSize = end - begin + 1;
        T *result = new T[sliceSize];

        int startIndex = begin - 1;
        int index = 0;

        for (int i = startIndex; i <= startIndex + (sliceSize - 1); i++) {
            result[index] = data[i];
            index++;
        }

        return result;
    }
};

int main() {
    GenericArray<int> int_array;

    int_array.addElement(0);
    int_array.addElement(2);
    int_array.addElement(4);
    int_array.addElement(6);
    int_array.addElement(8);
    int_array.addElement(10);
    int_array.addElement(12);
    int_array.addElement(14);
    int_array.addElement(16);
    int_array.addElement(18);

    cout << "size of array is " << int_array.size() << endl;
    cout << "sum of the array is " << int_array.sum() << endl;

    cout << "maximum and minimum of array is "
         << int_array.max() << "\t" << int_array.min() << endl;

    int *sliced_array = int_array.slice(2, 4);

    if (sliced_array != NULL) {
        int sliceSize = 4 - 2 + 1;

        cout << "sliced array (positions 2 to 4): ";

        for (int i = 0; i < sliceSize; i++) {
            cout << sliced_array[i] << " ";
        }

        cout << endl;

        delete [] sliced_array;
    }

    return 0;
}