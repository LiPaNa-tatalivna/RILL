
#include <iostream>

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

    void addElement(int element) {
        size_zapolnen++;
        if (size_pamyt < size_zapolnen){
            size_pamyt *= 2;
            int* newData = new int[size_pamyt];
            for (int i = 0; i < size_zapolnen - 1; i++) {
                newData[i] = data[i];
            }
            newData[size_zapolnen] = element;
    
            delete[] data;
            data = newData;
        }else{
            data[size_zapolnen] = element;
        }
    }

    int getElement(int index) {
        if (index < 0 || index > size_pamyt) {
            std::cout << "Invalid index!" << std::endl;
            return -1; // or throw an exception
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

        std::cout << arr.getElement(5) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}
