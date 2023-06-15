#include <string>
#include <iostream>
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

class egg: public item {
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
