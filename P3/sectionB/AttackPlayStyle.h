/* AttackPlayStyle class
 * Concrete class - inherits from PlayStyle
*/
#pragma once
#include <string>
#include <iostream>
#include "PlayStyle.h"

class AttackPlayStyle : public PlayStyle{
    public:
        AttackPlayStyle();
        virtual ~AttackPlayStyle();
        std::string attack();
};