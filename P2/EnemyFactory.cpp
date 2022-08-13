#include <ctime>
#include <random>
#include "EnemyFactory.h"
using namespace std;
//Tayla Orsmond u21467456
EnemyFactory::EnemyFactory() {};
EnemyFactory::~EnemyFactory() {};
string EnemyFactory::getName(){
    const int SIZE = 8;
    string names[SIZE]  = {"Keelan", "Francois", "Thomas", "Ross", "Dhairya", "Tayla", "Final Pam", "Fernando"};
    return names[rand() % SIZE];
}
int EnemyFactory::generate(int mean, int stddev){//generate N~(mean, stddev)
    random_device randy;
    mt19937 gen(randy()); 
    normal_distribution<float> dist(mean, stddev); 
    int num = dist(gen);
    return num;
}