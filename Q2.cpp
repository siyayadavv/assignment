#include <iostream>
#include <climits>
using namespace std;

// Function to reverse the array 
void reversearray(int myArr[], int totalSize) {
    int startpt = 0;
    int endpt = totalSize - 1;
    while (startpt < endpt) {
        int swaptemp = myArr[startpt];
        myArr[startpt] = myArr[endpt];
        myArr[endpt] = swaptemp;
        
        startpt++;
        endpt--;
    }
}

void showarray(int myArr[], int Size) {
    for (int i = 0; i < Size; i++) {
        cout << myArr[i];
        if (i < Size - 1) {
            cout << ", "; 
        }
    }
    cout << endl;
}

void findbiggestandsmallest(int myArr[], int Size) {
    if (Size < 2) {
        cout << "Array needs at least 2 numbers" << endl;
        return;
    }
    
    int biggest = myArr[0], smallest = myArr[0];
    int secondBiggest = INT_MIN, secondSmallest = INT_MAX;

    for (int i = 1; i < Size; i++) {
        if (myArr[i] > biggest) {
            secondBiggest = biggest;
            biggest = myArr[i];
        } else if (myArr[i] > secondBiggest && myArr[i] != biggest) {
            secondBiggest = myArr[i];
        }
        
        if (myArr[i] < smallest) {
            secondSmallest = smallest;
            smallest = myArr[i];
        } else if (myArr[i] < secondSmallest && myArr[i] != smallest) {
            secondSmallest = myArr[i];
        }
    }

    if (secondBiggest == INT_MIN) {
        cout << "Second Biggest element does not exist." << endl;
    } else {
        cout << "Second Biggest element is: " << secondBiggest << endl;
    }

    if (secondSmallest == INT_MAX) {
        cout << "Second Smallest element does not exist." << endl;
    } else {
        cout << "Second Smallest element is: " << secondSmallest << endl;
    }
}

int main() {
    int arraySize;

    cout << "Enter the size of the array: ";
    cin >> arraySize;

    if (arraySize <= 0) {
        cout << "Please enter a valid size (greater than 0)" << endl;
        return 1; 
    }

    int* myArray = new int[arraySize];

    cout << "Enter " << arraySize << " numbers:" << endl;
    for (int i = 0; i < arraySize; i++) {
        cout << "Number " << i + 1 << ": ";
        cin >> myArray[i];
    }

    cout << "\nOriginal Array: ";
    showarray(myArray, arraySize);

    reversearray(myArray, arraySize);
    cout << "Reversed Array: ";
    showarray(myArray, arraySize);

    findbiggestandsmallest(myArray, arraySize);

    delete[] myArray;

    return 0;
}