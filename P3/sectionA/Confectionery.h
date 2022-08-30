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
        Confectionery(std::string, std::string, double);//manufacturer, type, price
        virtual ~Confectionery();
        virtual std::string getDescription() = 0;//prints manufacturer, type, price, id
        //overwritten in derived classes
        //getters and setters
        double getPrice();
        void setPrice(double);
        std::string getManufacturer();
        void setManufacturer(std::string);
        std::string getType();
        void setType(std::string);
        int getId();
        void setId(int);
        int getCount();//getter for global count
    private:
        std::string manufacturer;
        std::string type;
        int id;
        double price;
        static int counter;//global counter
};


