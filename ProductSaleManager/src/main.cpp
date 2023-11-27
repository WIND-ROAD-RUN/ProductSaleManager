#include<iostream>
#include"Product.h"
#include"PurchasePortal.h"


using namespace std;

std::vector<ProductItem> testData() {
    std::vector<ProductItem> result;

    ProductItem aPair;

    Product phone;
    phone.setId("00-01-02");
    phone.setLabel(ProductType::MEDICAL);
    phone.setName("phone1");
    phone.setPrice(8848);
    
    Supplier supply;
    supply.setAddress("Beijing");
    supply.setId("10-02-03");
    supply.setIsLongTermSupply(true);
    supply.setName("HP");
    supply.setPhoneNumber("10086");

    aPair.first = phone;
    aPair.second = supply;

    result.push_back(aPair);





    phone.setId("00-01-03");
    phone.setLabel(ProductType::MEDICAL);
    phone.setName("phone2");
    phone.setPrice(8848);

    supply.setAddress("Beijing");
    supply.setId("10-02-03");
    supply.setIsLongTermSupply(true);
    supply.setName("HP");
    supply.setPhoneNumber("10086");

    aPair.first = phone;
    aPair.second = supply;

    result.push_back(aPair);
    


    return result;
}

int main() {
    PurchasePortal portal;

    portal.setFilePath(R"(G:\project\code_place\vs_code_place\ProductManager\ProductSaleManager\database\ProductData.xml)");
    portal.iniliazation();
    portal.saveProductItemList(testData());

    auto result=portal.getProductItemList();

    return 0;
}