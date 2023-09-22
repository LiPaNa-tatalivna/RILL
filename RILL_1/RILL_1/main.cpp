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

    ~SmartArray() {
        delete[] data;
    }

    SmartArray(const SmartArray&) = delete;
    SmartArray& operator=(const SmartArray&) = delete;

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
};

int main() {
    try {
        SmartArray arr(5);
        
        arr.addElement(1);
        arr.addElement(4);
        arr.addElement(155);
        arr.addElement(14);
        arr.addElement(15);

        std::cout << arr.getElement(4) << std::endl;
        std::cout << arr.getElement(5) << std::endl; // Throws an exception
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}

