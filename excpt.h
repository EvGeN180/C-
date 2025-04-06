#pragma once

#include <exception>
#include <string>

class InvalidNumberException : public std::exception {
private:
    std::string msg;
public:
    InvalidNumberException(){}
    InvalidNumberException(const std::string& msg) : msg(msg) {}

    const char* what() const noexcept override {
        return msg.c_str();
    }
};

class MyStringException : public std::exception {
private:
    std::string msg;
public:
    MyStringException() : msg("String exception") {}
    MyStringException(const std::string& msg) : msg(msg) {}

    const char* what() const noexcept override {
        return msg.c_str();
    }
};
