#include <iostream>
#include <stdexcept>

class SmartArray {
private:
    int* data;
    int size_pamyt;
    int size_zapolnen;

public:
    SmartArray(int size_pamyt) : size_pamyt(size_pamyt), size_zapolnen(0) {
        data = new int[size_pamyt];
    }

    ~SmartArray() {
        delete[] data;
    }

    void addElement(int element) {
        if (size_pamyt <= size_zapolnen) {
            size_pamyt *= 2;
            int* newData = new int[size_pamyt];
            for (int i = 0; i < size_zapolnen; i++) {
                newData[i] = data[i];
            }
            newData[size_zapolnen] = element;

            delete[] data;
            data = newData;
        }
        else {
            data[size_zapolnen] = element;
        }
        size_zapolnen++;
    }

    int getElement(int index) {
        if (index >= 0 && index < size_zapolnen) {
            return data[index];
        }
        else {
            throw std::out_of_range("Invalid index!");
        }
    }

    SmartArray& operator=(const SmartArray& other) {
        if (this != &other) {
            delete[] data;
            size_pamyt = other.size_pamyt;
            size_zapolnen = other.size_zapolnen;
            data = new int[size_pamyt];
            for (int i = 0; i < size_zapolnen; i++){
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

    return 0;
}
