#ifndef CAT_H
#define CAT_H

#include <string>
#include <fstream>

enum properties {ID, AGE, NAME, BREED, FOOD};

enum comparing {LESS, EQUAL, MORE};

class cat {
private:
    int id;
    int age;
    std::string name;
    std::string breed;
    std::string food;
public:
    int get_id();
    int get_age();
    std::string get_name();
    std::string get_breed();
    std::string get_food();
    //friend std::ostream& operator << (std::ostream& out, cat& ex);
};

#endif // CAT_H
