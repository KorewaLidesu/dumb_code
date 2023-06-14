#ifndef LI_ARRAYLIST_H
#define LI_ARRAYLIST_H

template<class T>
class ArrayList {
    public:
        // Constructors
        ArrayList();
        ArrayList(int);
        ArrayList(const ArrayList<T> &);
        ArrayList(const ArrayList<T> &, int);
        ~ArrayList();

        // Methods
        void add(const T &);
        void add(const T &, int);
        const T * remove(int);
        void removeAll();
        void removeAll(int);
        T * get(int) const;
        const T * getArray() const;

        // Getter
        int getSize() const;
        int getCapacity() const;
        
    private:
        // The array that is the basis for this ArrayList.
        T * array;
        // The current number of elements in this ArrayList.
        int size;
        // The current capacity of the array that is backing this.
        int capacity;

        // Methods
        void reallocate(); 
        void reallocate(int);
};

template<class T>
ArrayList<T>::ArrayList() : array(new T[20]), capacity(20), size(0)
{
    // Create ArrayList with default capacity (20)
}

template<class T>
ArrayList<T>::ArrayList(int capacity) : array(new T[capacity]), capacity(capacity), size(0)
{
    // Create ArrayList with custom size
}

template<class T>
ArrayList<T>::ArrayList(const ArrayList<T> & list)
    : array(new T[list.size * 2]), capacity(list.size * 2), size(list.size)
{
    // Create new ArrayList from exist one
    for (int i = 0; i < list.getSize(); i++) {
        array[i] = *list.get(i);
    }
}

template<class T>
ArrayList<T>::ArrayList(const ArrayList<T> & list, int capacity) {
    // Create ArrayList from exist one, with custom capacity that isn't less than exist one
    if (capacity >= list.getSize())
    {
        array = new T[capacity];
        this -> capacity = capacity;
    }
    else
    {
        array = new T[list.getSize() * 2];
        this -> capacity = list.getSize() * 2;
    }

    size = list.getSize;

    for (int i = 0; i < size; i++) {
        array[i] = list.get(i);
    }
}

template<class T>
ArrayList<T>::~ArrayList() {
    delete[] array;
}

template<class T>        
void ArrayList<T>::reallocate() {
    capacity *= 2;
    T * temp = new T[capacity];

    for (int i = 0; i < size; i++) {
        temp[i] = array[i];
    }

    delete [] array;

    array = temp;
}

template<class T>
void ArrayList<T>::reallocate(int newSize) {
    capacity = newSize;
    T * temp = new T[newSize];

    for (int i = 0; i < size; i++) {
        temp[i] = array[i];

        delete [] array;

        array = temp;
    }
}

template<class T>
void ArrayList<T>::add(const T & element) {
    if ((size - 1) == capacity) {
        reallocate();
    }
    array[size] = element;
    size++;
}

template<class T>
void ArrayList<T>::add(const T & element, int index) {
    if (index >= 0 && index <= size) {
        //Reallocate if necessary.
        if (index >= capacity || size == capacity) {
            int multiplicand = (index >= capacity) ? index : size;
            reallocate(multiplicand * 2);
        }

        //Shift elements to the right.
        for (int i = size; i > index; i--) {
            array[i] = array[i - 1];
        }

        array[index] = element;
        size++;
    }
}

template<class T>
const T * ArrayList<T>::remove(int index) {
    T * removed = NULL;

    if (index < size && index >= 0) {
        for (int i = index; i < size; i++) {
            array[i] = array[i + 1];
        }
        removed = array + index;
        size--;
    }

    return removed;
}

template<class T>
void ArrayList<T>::removeAll() {
    delete[] array;
    array = new T[capacity];
    size = 0;
}

template<class T>
void ArrayList<T>::removeAll(int newCapacity) {
    delete [] array;
    array = new T[newCapacity];
    capacity = newCapacity;
    size = 0;
}

// Gets the element stored at the passed in index.
template<class T>
T * ArrayList<T>::get(int index) const {
    return (index >= 0 && index < size) ? (array + index) : NULL;
}

// Get a duplicate Array with same access pointers
template<class T>
const T * ArrayList<T>::getArray() const {
    T * newArray = new T[size];
    for (int i = 0 ; i < size ; i++)
        newArray[i] = array[i];
    return newArray;
}

// Gets the size of this ArrayList.
template<class T>
int ArrayList<T>::getSize() const {
    return size;
}

// Gets the capacity of this ArrayList.
template<class T>
int ArrayList<T>::getCapacity() const {
    return capacity;
}

#endif