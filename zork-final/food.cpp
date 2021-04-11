#include "food.h"

Food::Food(QString name, int healthBoost) : Item(name, false, true), Edible(), consumed(false), healthBoost(healthBoost)
{

}
int Food::eat() {
    if(!consumed) {
        consumed = true;
        return healthBoost;
    }
    return 0;
}
