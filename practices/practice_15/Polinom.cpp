#include "Polinom.h"

Polinom::Polinom(int size) : N(size) {
    coeffs = (N > 0) ? new double[N] : nullptr;
}

Polinom::Polinom(const Polinom& other) : N(other.N) {
    coeffs = new double[N];
    for (int i = 0; i < N; ++i) coeffs[i] = other.coeffs[i];
}

Polinom::~Polinom() {
    delete[] coeffs;
}

Polinom& Polinom::operator=(const Polinom& other) {
    if (this != &other) {
        delete[] coeffs;
        N = other.N;
        coeffs = new double[N];
        for (int i = 0; i < N; ++i) coeffs[i] = other.coeffs[i];
    }
    return *this;
}

void Polinom::setCoeff(int index, double value) {
    if (index >= 0 && index < N) coeffs[index] = value;
}

void Polinom::fillManual() {
    for (int i = 0; i < N; ++i) {
        std::cout << "Коефіцієнт біля x^" << i << ": ";
        std::cin >> coeffs[i];
    }
}

void Polinom::output() const {
    for (int i = 0; i < N; ++i) {
        std::cout << coeffs[i] << (i == 0 ? "" : "*x^" + std::to_string(i));
        if (i < N - 1) std::cout << " + ";
    }
    std::cout << std::endl;
}

void saveToBinary(const Polinom& p, const std::string& filename) {
    std::ofstream out(filename, std::ios::binary);
    if (!out) return;
    out.write(reinterpret_cast<const char*>(&p.N), sizeof(int));
    out.write(reinterpret_cast<const char*>(p.coeffs), sizeof(double) * p.N);
    out.close();
}

void loadFromBinary(Polinom& p, const std::string& filename) {
    std::ifstream in(filename, std::ios::binary);
    if (!in) return;
    int newN;
    in.read(reinterpret_cast<char*>(&newN), sizeof(int));
    delete[] p.coeffs;
    p.N = newN;
    p.coeffs = new double[p.N];
    in.read(reinterpret_cast<char*>(p.coeffs), sizeof(double) * p.N);
    in.close();
}