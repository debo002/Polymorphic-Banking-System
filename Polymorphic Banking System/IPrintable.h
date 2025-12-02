#pragma once
#include <iostream>

// Interface for printable objects
// Enables uniform printing via operator<< for any derived class
class IPrintable {
public:
    virtual ~IPrintable() = default;
    // Pure virtual function - derived classes must implement
    virtual void print(std::ostream& os) const = 0;
};

// Non-member operator<< enables std::cout << obj syntax
// Uses dynamic dispatch to call the appropriate derived class print()
inline std::ostream& operator<<(std::ostream& os, const IPrintable& obj) {
    obj.print(os);
    return os;
}