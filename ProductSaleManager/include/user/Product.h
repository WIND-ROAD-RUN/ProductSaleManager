#ifndef PROJECT_H_
#define PROJECT_H_

#include"Indenty.h"
#include<vector>

enum ProductType {
    UNDEFINED,
    CLOTHE,
    DAILYNECESSITIES,
    MEDICAL,
    HOUELEAPP,
    ELEPRODUCT,
    SHOE,
    COSMETICS,
    LUXURYGOODS,
};

std::string getLableName(ProductType label);
ProductType getProductEnum(std::string type);

class Product
    :public Indenty {
private:
    ProductType m_label{ ProductType::UNDEFINED };
    double m_price{0};
public:
    Product() {}
    ~Product() {}
public:
    void setPrice(double price) { m_price = price; }
    Indenty getIndenty() const{ return Indenty(getId(), getName()); }
    double getPrice() const { return m_price; }
public:
    ProductType getLabelEnum()const { return m_label; }
    std::string getLabelString()const;
    void setLabel(ProductType label) { m_label = label; }

};

#endif // !PROJECT_H_
