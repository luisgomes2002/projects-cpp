#include <iostream>


template<typename T> class DynamicArray {
private:
	T* array;
	int capacity;
	int size;

	void resize(int newCapacity) {

		if (newCapacity <= 0) throw std::invalid_argument("Capacity must be greater than zero");

		T* newArray = new T[newCapacity];
		
		for (int i = 0; i < size; i++) newArray[i] = array[i];

		delete[] array;
		array = newArray;
		capacity = newCapacity;
	}

public:
	DynamicArray() : array(nullptr), capacity(0), size(0)
	{
		std::cout << "Array created" << std::endl;
	}

	DynamicArray(int capacity) : array(new T[capacity]), capacity(capacity), size(0)
	{
		std::cout << "Array created" << std::endl;
	}

	~DynamicArray()
	{
		delete[] array;
		std::cout << "Destroyed array" << std::endl;
	}

	void Add(const T& element)
	{
		if (size == capacity) {
			resize(capacity > 0 ? capacity * 2 : 1);
		}

		array[size++] = element;
	}

	int Size() { return size; }
};

int main() {
	DynamicArray<int> array(5);

	std::cout << "Size: " << array.Size() << std::endl;
	array.Add(10);
	std::cout << "Size: " << array.Size() << std::endl;

	std::cin.get();
}