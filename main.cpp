#include <iostream>
#include <vector>
#include <string>

class item {
public:
    item() = default;
    virtual ~item() = default;

    virtual std::string get_item_name() const = 0;
    virtual void set_item_name(const std::string& _item_name)  = 0;

    virtual double get_item_price() const = 0;
    virtual void set_item_price(double _item_price) = 0;

    virtual int get_item_quanity() const = 0;
    virtual void set_item_quanity(int _item_quanity) = 0;

    virtual bool is_valid() = 0;
    virtual bool increase_the_amount_of(int _count) = 0;
    virtual bool reduce_the_amount_of(int _count) = 0;

};

class egg:public item {
private:
    std::string item_name = "";
    double item_value;
    int item_quanity;
public:
    egg():item(){}
    egg(const std::string& _item_name,double _item_value,int _item_quanity):item(){
        item_name = _item_name;
        item_value = _item_value;
        if(_item_quanity >= 0) {
            item_quanity = _item_quanity;
        }
        else {
            std::cout<<"invalid quanity";
            item_quanity = 0;
        }
    }
    virtual std::string get_item_name() const {
        return item_name;
    };
    virtual void set_item_name(const std::string& _item_name) {
        item_name = _item_name;
    }

    virtual double get_item_price() const {
        return  item_value;
    }
    virtual void set_item_price(double _item_price)  {
            item_value = _item_price;
    }

    virtual int get_item_quanity() const {
        return item_quanity;
    };
    virtual void set_item_quanity(int _item_quanity) {
        if(_item_quanity >= 0) {
            item_quanity = _item_quanity;
        }
        else {
            std::cout<<"invalid quanity";
            item_quanity = 0;
        }
    }

    virtual bool is_valid() {
        return item_quanity > 0 ? true : false;
    };
    virtual bool increase_the_amount_of(int _quanity) {
        item_quanity += _quanity;
        return true;
    };
    virtual bool reduce_the_amount_of(int _quanity) {
        if(item_quanity - _quanity < 0 ) {
            std::cout<<"invalid quanity" << std::endl;
            std::cout<<"current product quanity is - " << item_quanity;
            return false;
        }
        else{
            item_quanity -= _quanity;
            return true;
        }
    };
};
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
