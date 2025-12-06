// To compile this code, ensure you have the fmt library installed. you can install it
// apt install libfmt-dev libfmt-doc;  then compile with:
// g++ -std=c++17 -o increment increment.cc -lfmt
#define FMT_HEADER_ONLY
#include <fmt/format.h> // Include the fmt library for formatted output for print().

class Num {
    int value;
public:
    Num(int v) : value(v) {}
    // Prefix increment
    Num& operator++() {
        value += 1;
        return *this;
    }
    // Postfix increment
    Num operator++(int) {
        Num temp = *this; // Make a copy of the current state
        value += 1;       // Increment the current object's value
        return temp;     // Return the copy (state before increment)
    }
    int getValue() const {
        return value;
    }
};

int main() {
    Num n1(5);
    int arr[3] = {1,2,3};
    int i = 0;

    fmt::print("Initial n1 value: {}\n", n1.getValue());

    ++n1; // Prefix increment
    fmt::print("n1 After prefix increment: {}\n", n1.getValue());

    n1++; // Postfix increment
    fmt::print("n1 After postfix increment: {}\n", n1.getValue());

    fmt::print("Array[i] = {}\n", arr[i]); // Current i
    fmt::print("Array[++i] prefix increment {}\n", arr[++i]); // Prefix increment on i
    fmt::print("Array[i] = {}\n", arr[i]); // Current i
    fmt::print("Array[i++] postfix increment {}\n", arr[i++]); // Postfix increment on i
    fmt::print("Array[i] = {}\n", arr[i]); // Current i

    return 0;
}

// Conclusion: The postfix increment operator returns the value before incrementing,
// So it requires making a copy of the current state, which can be less efficient.
// preferred to use prefix increment when possible for better performance.