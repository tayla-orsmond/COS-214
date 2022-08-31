/* PhysicalAttackPlayStyle class
 * Concrete class - inherits from PlayStyle
*/
#pragma once
#include <string>
#include <iostream>
#include "PlayStyle.h"

class PhysicalAttackPlayStyle : public PlayStyle{
    public:
        PhysicalAttackPlayStyle();
        virtual ~PhysicalAttackPlayStyle();
        std::string attack();
};