/* The olayStyle class
 * Abstract class
*/
#pragma once
#include <string>
#include <iostream>

class PlayStyle{
    public:
        PlayStyle();
        virtual ~PlayStyle();
        virtual std::string attack() = 0;
};