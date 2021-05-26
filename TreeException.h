#pragma once
#include <exception>
#include <iostream>
#include "pch.h"

class TreeException : public std::exception {
    private:
        std::string error;
    public:
        TreeException(std::string error) : error(error) {}
        const char* what() { return error.c_str();}

};