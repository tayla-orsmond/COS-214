/* RunPlayStyle class
 * Concrete class - inherits from PlayStyle
*/
#pragma once
#include <string>
#include <iostream>
#include "PlayStyle.h"

class RunPlayStyle : public PlayStyle{
    public:
        RunPlayStyle();
        virtual ~RunPlayStyle();
        std::string attack();
};