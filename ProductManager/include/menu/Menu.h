#ifndef MENU_H_
#define MENU_H_

#pragma warning(disable:4996)

#include"PurchasePortal.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using ProductItemOrder = std::pair<ProductItem, int>;
using Account = std::pair<std::string, std::string>;
enum LoginResult{
    USER,
    ROOT,
    FAILED
};

class Menu {
private:
    PurchasePortal m_purchase;
    std::string m_filePath;

    std::vector<ProductItem> m_productList;
    std::vector<ProductItemOrder> m_order;
private:
    LoginResult loginMenu();
private:
    int get_number();
    double get_double();
    ProductItem findProduct(const std::string &  id);
private:
    void show_menu_first(); 
    void setConsole();
private:
    void purchaseProduct();
    void showProductInfoTableHead();
    void showProductInfoTableTail();

    void displayOrder();
    void showProductOrderTableHead();
    void showProductOrderTableTail();

    void showPurchaseTotal();
    double getTotalMoney();
private:
    void show_root_menu_first();
    void show_product_info();
    void add_new_productItem();
private:
    LoginResult loginCheck(const Account & account);
public:
    void setFilePath(const std::string& filePath) { m_filePath = filePath; }
    void run();

};



#endif // !MENU_H_
