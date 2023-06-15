#include <iostream>
#include <string>
#include "supermarket.hpp"
int main() {
    supermarket obj;
    item* it  = new egg("gandzasar",60,1000);
    promotion *prom  = new promotion_2_for_1_price;
    obj.add(it);
    obj.item_price_(it,prom);
    delete prom;
    prom = new promotion_4_by_20percent;
    obj.item_price_(it,9,prom);
    delete it;
    return 0;
}
