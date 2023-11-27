#include "PurchasePortal.h"

void PurchasePortal::setNewFile()
{
    m_doc.load_file(m_filePath.c_str());
    m_doc.append_child("ProductItemList");
    m_doc.save_file(m_filePath.c_str());
}

bool PurchasePortal::iniliazation()
{
    auto result=m_doc.load_file(m_filePath.c_str());
    if (result) {
        return true;
    }
    return false;
}

std::vector<ProductItem> PurchasePortal::getProductItemList()
{
    std::vector<ProductItem> result;
    auto ProductItemListNode = m_doc.child("ProductItemList");

    for (const auto & productItem: ProductItemListNode.children()) {
        ProductItem temp;
        temp.first.setName(productItem.attribute("Name").as_string());
        temp.first.setId(productItem.child("Id").text().as_string());
        temp.first.setPrice(productItem.child("Price").text().as_double());
        temp.first.setLabel(getProductEnum(productItem.child("Label").text().as_string()));

        temp.second.setAddress(productItem.child("Supplier").child("Address").text().as_string());
        temp.second.setId(productItem.child("Supplier").child("Id").text().as_string());
        temp.second.setIsLongTermSupply(productItem.child("Supplier").child("IsLongTermSupply").text().as_bool());
        temp.second.setName(productItem.child("Supplier").child("Name").text().as_string());
        temp.second.setPhoneNumber(productItem.child("Supplier").child("PhoneNumber").text().as_string());

        result.push_back(temp);
    }


    return result;
}

bool PurchasePortal::saveProductItemList(std::vector<ProductItem> productList)
{
    auto ProductItemListNode = m_doc.child("ProductItemList");
    ProductItemListNode.remove_children();

    for (const auto & ProductItem: productList) {
        auto ProductItemNode=ProductItemListNode.append_child("Product");
        ProductItemNode.append_attribute("Name").set_value(ProductItem.first.getName().c_str());

        auto ProductIdNode = ProductItemNode.append_child("Id");
        ProductIdNode.text().set(ProductItem.first.getId().c_str());

        auto ProductPriceNode = ProductItemNode.append_child("Price");
        ProductPriceNode.text().set(ProductItem.first.getPrice());

        auto ProductLabelNode = ProductItemNode.append_child("Label");
        ProductLabelNode.text().set(ProductItem.first.getLabelString().c_str());
        



        auto SupplierNode = ProductItemNode.append_child("Supplier");
        
        auto SupplierNameNode = SupplierNode.append_child("Name");
        SupplierNameNode.text().set(ProductItem.second.getName().c_str());

        auto SupplierIdNode = SupplierNode.append_child("Id");
        SupplierIdNode.text().set(ProductItem.second.getId().c_str());

        auto SupplierAddressNode = SupplierNode.append_child("Address");
        SupplierAddressNode.text().set(ProductItem.second.getAddress().c_str());

        auto SupplierPhoneNumberNode = SupplierNode.append_child("PhoneNumber");
        SupplierPhoneNumberNode.text().set(ProductItem.second.getPhoneNumber().c_str());
        
        auto SupplierIsLongTermSupplyNode = SupplierNode.append_child("IsLongTermSupply");
        SupplierIsLongTermSupplyNode.text().set(ProductItem.second.getIsLongTermSupply());

    }

    auto result=m_doc.save_file(m_filePath.c_str());

    if (result) {
        return true;
    }
    return false;
}
