#include "promotion.hpp"
#include <vector>
class supermarket {
private:
    std::vector<item*> vec;
    double some_busines_logic(item* _item,int quanity ,promotion* prom) {
        double price_after_prom = prom->some_buisnes_logic(_item,quanity);
        return price_after_prom;
    }
public:
    supermarket() = default;
    supermarket(std::vector<item*> _vec) {
        for(int i = 0; i < _vec.size(); ++i) {
            vec.push_back(_vec[i]);
        }
    }
    void add(item* _it) {
        vec.push_back(_it);
    }
    void item_price_ (item* _item,promotion* _prom) {
        std::cout<<"price after promotion - "<<some_busines_logic(_item,1,_prom) << std::endl;
    }
    void item_price_ (item* _item, int quanity, promotion* _prom) {
        std::cout<<"price after promotion - "<<some_busines_logic(_item,quanity,_prom) << std::endl;
    }
};