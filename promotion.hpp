#include "item.hpp"

class promotion {
public:
    virtual double some_buisnes_logic(item* it, int quanity) = 0;
};
class no_promotion : public promotion{
public:
    virtual double some_buisnes_logic(item* it, int quanity){
        return quanity * (it->get_item_price()/1);
    };
};
class promotion_2_for_1_price : public promotion{
public:
    virtual double some_buisnes_logic(item* it, int quanity) {
        return quanity * (it->get_item_price() / 2);
    }
};
class promotion_3_for_1_price : public promotion{
public:
    virtual double some_buisnes_logic(item* it, int quanity) {
        return quanity * (it->get_item_price() /3);
    }
};
class promotion_4_by_20percent : public promotion{
public:
    virtual double some_buisnes_logic(item* it, int quanity) {
        if(quanity < 4) {
            return quanity * it->get_item_price();
        }
        else {
            return quanity * (it->get_item_price()/ 5);
        }
    };
};
