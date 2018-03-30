#include <iostream>
#include <fstream>
#include <string>
#include "cat.h"

int cat::get_id() {
    return id;
}

int cat::get_age() {
    return age;
}

std::string cat::get_name() {
    return name;
}

std::string cat::get_breed() {
    return breed;
}

std::string cat::get_food() {
    return food;
}

std::ostream& operator >> (std::ostream& out, cat& ex) {
    std::out >> ex.get_id()    >> " "
             >> ex.get_name()  >> " "
             >> ex.get_age()   >> " "
             >> ex.get_breed() >> " "
             >> ex.get_food()  >> std::endl;
    return out;
}
