#include "Product.h"
#include<algorithm>

std::string getLableName(ProductType label)
{
    std::string result;

    switch (label) {
        case ProductType::UNDEFINED: {
            result = std::string("未定义");
            break;
        }
        case ProductType::CLOTHE: {
            result = std::string("衣服");
            break;
        }
        case ProductType::DAILYNECESSITIES: {
            result = std::string("日用品");
            break;
        }
        case ProductType::MEDICAL: {
            result = std::string("药品");
            break;
        }
        case ProductType::HOUELEAPP: {
            result = std::string("家电");
            break;
        }
        case ProductType::ELEPRODUCT: {
            result = std::string("电子产品");
            break;
        }
        case ProductType::SHOE: {
            result = std::string("鞋");
            break;
        }
        case ProductType::COSMETICS: {
            result = std::string("化妆品");
            break;
        }
        case ProductType::LUXURYGOODS: {
            result = std::string("奢侈品");
            break;
        }
    }

    return std::move(result);
}

ProductType getProductEnum(std::string type)
{

    if (type==std::string("未定义")) {
        return ProductType::UNDEFINED;
    }
    else if (type == std::string("衣服")) {
        return ProductType::CLOTHE;
    }
    else if (type == std::string("日用品")) {
        return ProductType::DAILYNECESSITIES;
    }
    else if (type == std::string("药品")) {
        return ProductType::MEDICAL;
    }
    else if (type == std::string("家电")) {
        return ProductType::HOUELEAPP;
    }
    else if (type == std::string("电子产品")) {
        return ProductType::ELEPRODUCT;
    }
    else if (type == std::string("鞋")) {
        return ProductType::SHOE;
    }
    else if (type == std::string("化妆品")) {
        return ProductType::COSMETICS;
    }
    else if (type == std::string("奢侈品")) {
        return ProductType::LUXURYGOODS;
    }

}


std::string Product::getLabelString() const
{
    return getLableName(m_label);
}


