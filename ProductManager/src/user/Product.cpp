#include "Product.h"
#include<algorithm>

std::string getLableName(ProductType label)
{
    std::string result;

    switch (label) {
    case ProductType::UNDEFINED: {
        result = std::string("δ����");
        break;
    }
    case ProductType::CLOTHE: {
        result = std::string("�·�");
        break;
    }
    case ProductType::DAILYNECESSITIES: {
        result = std::string("����Ʒ");
        break;
    }
    case ProductType::MEDICAL: {
        result = std::string("ҩƷ");
        break;
    }
    case ProductType::HOUELEAPP: {
        result = std::string("�ҵ�");
        break;
    }
    case ProductType::ELEPRODUCT: {
        result = std::string("���Ӳ�Ʒ");
        break;
    }
    case ProductType::SHOE: {
        result = std::string("Ь");
        break;
    }
    case ProductType::COSMETICS: {
        result = std::string("��ױƷ");
        break;
    }
    case ProductType::LUXURYGOODS: {
        result = std::string("�ݳ�Ʒ");
        break;
    }
    }

    return std::move(result);
}

ProductType getProductEnum(std::string type)
{

    if (type == std::string("δ����")) {
        return ProductType::UNDEFINED;
    }
    else if (type == std::string("�·�")) {
        return ProductType::CLOTHE;
    }
    else if (type == std::string("����Ʒ")) {
        return ProductType::DAILYNECESSITIES;
    }
    else if (type == std::string("ҩƷ")) {
        return ProductType::MEDICAL;
    }
    else if (type == std::string("�ҵ�")) {
        return ProductType::HOUELEAPP;
    }
    else if (type == std::string("���Ӳ�Ʒ")) {
        return ProductType::ELEPRODUCT;
    }
    else if (type == std::string("Ь")) {
        return ProductType::SHOE;
    }
    else if (type == std::string("��ױƷ")) {
        return ProductType::COSMETICS;
    }
    else if (type == std::string("�ݳ�Ʒ")) {
        return ProductType::LUXURYGOODS;
    }

}


std::string Product::getLabelString() const
{
    return getLableName(m_label);
}


