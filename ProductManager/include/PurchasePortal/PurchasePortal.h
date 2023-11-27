#ifndef PURCHASEPORTAL_H_
#define PURCHASEPORTAL_H_

#include"Product.h"
#include"Supplier.h"

#include<string>
#include<pugixml.hpp>
#include<vector>

using ProductItem = std::pair<Product, Supplier>;

class PurchasePortal {
private:
    std::string m_filePath;
    pugi::xml_document m_doc;
public:
    void setFilePath(const std::string& filePath) { m_filePath = filePath; }
    void setNewFile();
    bool iniliazation();
    std::vector<ProductItem> getProductItemList();
    bool saveProductItemList(std::vector<ProductItem> productList);
};

#endif // !PURCHASEPORTAL_H_



