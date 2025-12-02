#pragma once
#include <iostream>

class IPrintable {
public:
    virtual ~IPrintable() = default;
    virtual void print(std::ostream& os) const = 0;
};

// non-member operator<< delegates to the printable interface
inline std::ostream& operator<<(std::ostream& os, const IPrintable& obj) {
    obj.print(os);   // dynamic dispatch -> derived print()
    return os;
}
