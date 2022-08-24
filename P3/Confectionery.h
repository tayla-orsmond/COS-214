/*
* The Confectionery class
* Abstract class
* Contains the basic functionality to produce chocolate
*/
#pragma once
#include <iostream>
#include <string>

class Confectionery{
    public:
        Confectionery(std::string, std::string, double);
        virtual ~Confectionery();
        virtual std::string getDescription() = 0;
        double getPrice();
        void setPrice(double);
        std::string getManufacturer();
        void setManufacturer(std::string);
        std::string getType();
        void setType(std::string);
        int getId();
        void setId(int);
    private:
        std::string manufacturer;
        std::string type;
        int id;
        double price;
};


