#include <iostream>
#include <string>
#include <cassert>

using namespace std;


class Animal {
public:
    virtual string speak() const = 0;
};

class Cat : public Animal {
public: 
    virtual string speak() const;
};

class Dog : public Animal {
public: 
    virtual string speak() const;
};

string Cat::speak() const {
	return "Meow!";
}

string Dog::speak() const 
{
	return "Woof!";
}

template <class T>
class Array {
public:
	Array();
	Array(int size);
        ~Array();
        T & operator[](int i) const;
        int size() const;
        void fill(T k);
        int * begin() {
                return data;
        }
        int * end(){
                return data + len;
        }


private:
        int len;
        T * data;
};
template <class T>
Array<T>::Array() {
	len = 0;
	data = NULL;
}

template <class T>

Array<T>::Array(int size) {
        len = size;
        data = new T[len];
}
template <class T>
Array<T>::~Array() {
        delete[] data;
	len = 0;
	data = NULL;
}
template <class T>
T & Array<T>::operator[](int i) const {
        return data[i];
}
template <class T>
int Array<T>::size() const {
        return len;
}
template <class T>
void Array<T>::fill(T k) {
        for(int i = 0; i < len; i++)
                data[i] = k;
}


void test1(){ //tests constructor and speak function
	Array<Animal *> a(5);
	a[2] = new Cat;
	a[3] = new Dog;
	assert(a[2]->speak() == "Meow!");
	assert(a[3]->speak() == "Woof!");
	a.~Array();
}
void test2(){ //tests fill function and size function
	Array<Animal *> a(5);
	a.fill(new Cat());
	for(int i = 0; i<5; i++)
		assert(a[i]->speak() == "Meow!");
	assert(a.size() == 5);
	a.~Array();
	assert(a.size() == 0);
}
int main()
{
	test1();
	test2();
	
	
	cout << "All Tests Passed" << endl; 
}
