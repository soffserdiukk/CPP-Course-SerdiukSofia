#include "Int24.h"

void Int24::checkRange(long long val) const {
    if (val < MIN_VAL || val > MAX_VAL) {
        throw OverflowException();
    }
}

Int24::Int24(long long v) {
    checkRange(v);
    value = static_cast<int>(v);
}

Int24 Int24::operator+(const Int24& other) const {
    long long res = static_cast<long long>(value) + other.value;
    return Int24(res);
}

Int24 Int24::operator-(const Int24& other) const {
    long long res = static_cast<long long>(value) - other.value;
    return Int24(res);
}

Int24 Int24::operator*(const Int24& other) const {
    long long res = static_cast<long long>(value) * other.value;
    return Int24(res);
}

Int24 Int24::operator/(const Int24& other) const {
    if (other.value == 0) throw DivisionByZeroException();
    long long res = static_cast<long long>(value) / other.value;
    return Int24(res);
}

std::ostream& operator<<(std::ostream& os, const Int24& obj) {
    os << obj.value;
    return os;
}

std::istream& operator>>(std::istream& is, Int24& obj) {
    long long v;
    if (!(is >> v)) return is;
    obj.checkRange(v);
    obj.value = static_cast<int>(v);
    return is;
}