#include <iostream>
#include <stdexcept>

class SmartArray {
private:
    int* data;
    int size_pamyt;
    int size_zapolnen;
public:
    SmartArray(int size_pamyt) : size_pamyt(size_pamyt) {
        data = new int[size_pamyt];
        size_zapolnen = 0;
    }

    SmartArray(const SmartArray& arr) : size_pamyt(arr.size_pamyt), size_zapolnen(arr.size_zapolnen) {
        data = new int[size_pamyt];
        for (int i = 0; i < size_zapolnen; i++) {
            data[i] = arr.data[i];
        }
    }
    ~SmartArray() {
        delete[] data;
    }

//    SmartArray(const SmartArray&) = delete;
//    SmartArray& operator=(const SmartArray&) = delete;

    void addElement(int element) {
        if (size_zapolnen == size_pamyt) {
            size_pamyt *= 2;
            int* newData = new int[size_pamyt];
            for (int i = 0; i < size_zapolnen; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size_zapolnen] = element;
        size_zapolnen++;
    }

    int getElement(int index) {
        if (index < 0 || index >= size_zapolnen) {
            throw std::out_of_range("Invalid index!");
        }
        return data[index];
    }
    
    SmartArray& operator=(const SmartArray& other) {
        if (this != &other) {
            delete[] data;
            size_pamyt = other.size_pamyt;
            size_zapolnen = other.size_zapolnen;
            data = new int[size_pamyt];
            for (int i = 0; i < size_zapolnen; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
};

int main() {
    SmartArray arr(5);
    arr.addElement(1);
    arr.addElement(4);
    arr.addElement(155);

    SmartArray new_array(2);
    new_array.addElement(44);
    new_array.addElement(34);

    arr = new_array;
    SmartArray arr1(3);
    SmartArray arr2(arr1);

    return 0;
}
