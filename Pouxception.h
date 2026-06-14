#ifndef POUXCEPTION_H
#define POUXCEPTION_H
#include <exception>
#include <string>
using namespace std;

class Pouxception : public exception {
    private:
        string pousception_message;
    public:
        Pouxception(string message): pousception_message(message) {};
        const char* what() const noexcept override {
            return pousception_message.c_str();
        }
};

#endif // POUXCEPTION_H