/* The olayStyle class
 * Abstract class
*/
#pragma once
#include <string>
#include <iostream>

class PlayStyle{
    public:
        PlayStyle(std::string);//style
        virtual ~PlayStyle();
        virtual std::string attack() = 0;
        std::string getStyle();//returns strategy name
    private:
        std::string style;//strategy name
};