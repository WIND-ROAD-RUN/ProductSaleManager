#include "Menu.h"

LoginResult Menu::loginMenu()
{
    using namespace std;

    string account;
    string password;
    LoginResult result;
    do {
        cout << "请输入账户:";
        cin >> account;
        cout << "请输入密码:";
        cin >> password;
        result = loginCheck(Account(account, password));
    } while(result ==LoginResult::FAILED);
    
    return result;

}

int Menu::get_number()
{
    int op;
    while (scanf("%d", &op) != 1) {
        printf("请输入数字：");
        while (getchar() != '\n')
            continue;
    }
    return op;
}

double Menu::get_double()
{
    double op;
    while (scanf("%lf", &op) != 1) {
        printf("请输入数字：");
        while (getchar() != '\n')
            continue;
    }
    return op;
}

ProductItem Menu::findProduct(const std::string& id)
{
    auto result = std::find_if(m_productList.begin(),m_productList.end(),
        [id](ProductItem & item) {
            return id == item.first.getId();
        });
    if(result==m_productList.end()){
        ProductItem resultPro;
        resultPro.first.setId("0");
        return resultPro;
    }
    return *result;
}

void Menu::show_menu_first()
{
    {
        
        printf("************************************************************\n");
        printf("*");
        
        printf("            欢迎进入商品信息管理系统                      ");
        
        printf("*\n*");
        
        printf("以下是系统提供的操作：                                    ");
        
        printf("*\n*                                                          *\n*");
        
        printf("  1.显示所有商品信息并加入购物车                          ");
        
        printf("*\n*");
        
        printf("  2.查看购物车                                            ");
        
        printf("*\n*");
       
        printf("  3.计算出本次购买的商品总额                              ");
       
        printf("*\n*");
        printf("                                                          *\n");
        printf("*                                                          ");
        printf("*\n*");
        
        printf("           注意：输入相关序号进入下一操作选择（按下0退出）");
        
        printf("*\n*");
        printf("***********************************************************\n");
       
        printf("请输入你的选项：");
    }
}


void Menu::setConsole()
{
    system("color f0");
}

void Menu::purchaseProduct()
{
    int choice;
    std::string choice_to_string;

    system("cls");
    showProductInfoTableHead();
    showProductInfoTableTail();
    printf("\n输入产品编号以进行购买：\n");
    while (1) {
        choice = get_number();
        if (choice==0) {
        printf("\n已全部加入购物车三秒后自动退出此菜单！！！\n");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            return;
        }
        choice_to_string = std::to_string(choice);
        
        auto findProductItem =findProduct(choice_to_string);
        if (findProductItem.first.getId()=="0") {
            printf("请正确输入商品编号:");
        }
        else {
            printf("请输入购买的数量：\n");
            int quantity = get_number();
            m_order.push_back(ProductItemOrder(findProductItem,quantity));
            printf("添加购物车成功\n");
            printf("如果想要继续购买请输入产品编号，退出购买界面请输入0\n");
        }

    }
}

void Menu::showProductInfoTableHead()
{
    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("%-10s|%-10s|%-15s|%-16s|%-16s|%-14s|%-6s|%-6s\n", "商品编号", "商品名", "商品单价", "供应商", "供应商编号", "供应商手机号", "是否为长期供应商","供应商地址");
    printf("-------------------------------------------------------------------------------------------------------------\n");
}

void Menu::showProductInfoTableTail()
{
    for (const auto & productItem:m_productList) {
        printf("%-10s", productItem.first.getId().c_str());
        printf("%-12s", productItem.first.getName().c_str());
        printf("%-15.2lf", productItem.first.getPrice());
        printf("%-18s", productItem.second.getName().c_str());
        printf("%-16s", productItem.second.getId().c_str());
        printf("%-16s", productItem.second.getPhoneNumber().c_str());

        if (productItem.second.getIsLongTermSupply()) {
            printf("%-16s", "是");
        }
        else {
            printf("%-16s", "否");
        }
        printf("%-6s\n", productItem.second.getAddress().c_str());
    }

}

void Menu::displayOrder()
{
    int choice;
    std::string choice_to_string;

    system("cls");
    showProductOrderTableHead();
    showProductOrderTableTail();
    printf("\n输入0退出：\n");
    while (1) {
        choice = get_number();
        if (choice == 0) {
            printf("\n三秒后自动退出此菜单！！！\n");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            return;
        }
    }
}

void Menu::showProductOrderTableHead()
{
    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("%-10s|%-10s|%-15s|%-16s|%-16s|%-6s\n", "商品编号", "商品名", "商品单价", "供应商", "供应商编号", "购买数量");
    printf("-------------------------------------------------------------------------------------------------------------\n");
}

void Menu::showProductOrderTableTail()
{
    for (const auto& productItem : m_order) {
        printf("%-10s", productItem.first.first.getId().c_str());
        printf("%-12s", productItem.first.first.getName().c_str());
        printf("%-15.2lf", productItem.first.first.getPrice());
        printf("%-18s", productItem.first.second.getName().c_str());
        printf("%-16s", productItem.first.second.getId().c_str());
        printf("%-6d\n", productItem.second);
    }
}

void Menu::showPurchaseTotal()
{
    int choice;
    std::string choice_to_string;

    system("cls");
    printf("购物车内所有的商品总额为：%lf\n\n", getTotalMoney());
    printf("\n输入0退出：\n");
    while (1) {
        choice = get_number();

        if (choice == 0) {
            printf("\n三秒后自动退出此菜单！！！\n");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            return;
        }
    }
}

double Menu::getTotalMoney()
{
    double result=0;
    for (const auto & item:m_order) {
        double temp = 0;
        temp = item.second * item.first.first.getPrice();
        result += temp;
    }
    return result;
}

void Menu::show_root_menu_first()
{
    {

        printf("************************************************************\n");
        printf("*");
        printf("              以下是root管理菜单选项                      ");
        printf("*\n*");
        printf("以下是系统提供的操作：                                    ");
        printf("*\n*                                                          *\n*");
        printf("  1.显示所有商品信息                                      ");
        printf("*\n*");
        printf("  2.添加新的产品信息                                      ");
        printf("*");
        printf("\n*");
        printf("                                                          *\n");
        printf("*                                                          ");
        printf("*\n*");
        printf("           注意：输入相关序号进入下一操作选择（按下0退出）");
        printf("*\n*");
        printf("***********************************************************\n");

        printf("请输入你的选项：");
    }
}

void Menu::show_product_info()
{
    int choice;
    std::string choice_to_string;

    system("cls");
    showProductInfoTableHead();
    showProductInfoTableTail();
    printf("\n按下0退出：\n");
    while (1) {
        choice = get_number();
        if (choice == 0) {
            printf("\n三秒后自动退出此菜单！！！\n");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            return;
        }
    }
}

void Menu::add_new_productItem()
{
    using namespace std;

    int choice;
    std::string choice_to_string;

    system("cls");
    showProductInfoTableHead();
    showProductInfoTableTail();
    printf("\n按下1添加产品信息，按下0退出：\n");
    while (1) {
        choice = get_number();
        if (choice == 0) {
            printf("\n三秒后自动退出此菜单！！！\n");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            return;
        }
        else if(choice==1){
            ProductItem newItem;
            std::string temp;
            int id;
            double price;

            cout << "请输入产品名字：" << endl;
            cin >> temp;
            newItem.first.setName(temp);

            cout << "请输入产品ID：" << endl;
            id = get_number();
            newItem.first.setId(std::to_string(id));

            cout << "请输入产品价格：" << endl;
            price = get_double();
            newItem.first.setPrice(price);

            cout << "请选择产品类型：" << endl;
            cout << "1: 衣服   " << "2: 日用品   " << "3: 药品   " << "4: 家用品   " << endl;
            cout << "5: 电子产品   " << "6: 鞋类   " << "7: 化妆品   " << "8: 奢侈品   " << endl;
            int label ;
            while (1) {
                label = get_number();
                if (label==1) {
                    newItem.first.setLabel(ProductType::CLOTHE);
                    break;
                }
                else if (label == 2) {
                    newItem.first.setLabel(ProductType::DAILYNECESSITIES);
                    break;
                }
                else if (label == 3) {
                    newItem.first.setLabel(ProductType::MEDICAL);
                    break;
                }
                else if (label == 4) {
                    newItem.first.setLabel(ProductType::HOUELEAPP);
                    break;
                }
                else if (label == 5) {
                    newItem.first.setLabel(ProductType::ELEPRODUCT);
                    break;
                }
                else if (label == 6) {
                    newItem.first.setLabel(ProductType::SHOE);
                    break;
                }
                else if (label == 7) {
                    newItem.first.setLabel(ProductType::COSMETICS);
                    break;
                }
                else if (label == 8) {
                    newItem.first.setLabel(ProductType::LUXURYGOODS);
                    break;
                }
                else {
                    printf("\n请正确输入选项\n");
                }
            }
            cout << "请输入供应商名字：" << endl;
            cin >> temp;
            newItem.second.setName(temp);

            cout << "请输入产品供应商ID：" << endl;
            id = get_number();
            newItem.second.setId(std::to_string(id));

            cout << "请输入供应商地址：" << endl;
            cin >> temp;
            newItem.second.setAddress(temp);

            cout << "请输入供应商手机号：" << endl;
            cin >> temp;
            newItem.second.setPhoneNumber(temp);

            cout << "请输入是否为长期供应商（0为否其他值为是）：" << endl;
            id = get_number();
            if (id) {
                newItem.second.setIsLongTermSupply(true);
            }
            else {
                newItem.second.setIsLongTermSupply(false);
            }
            printf("\n添加成功\n");
            m_productList.push_back(newItem);
            printf("\n按下1添加产品信息，按下0退出：\n");
        }
        
        else  {
            printf("请正确输入选项\n");
        }
    }
}

LoginResult Menu::loginCheck(const Account& account)
{
    if (account.first=="root") {
        if (account.second=="root") {
            return LoginResult::ROOT;
        }
        else {
            std::cout << "账户或密码错误" << std::endl;
            return LoginResult::FAILED;
        }
    }
    else if (account.first == "user") {
        if (account.second == "user") {
            return LoginResult::USER;
        }
        else {
            std::cout << "账户或密码错误" << std::endl;
            return LoginResult::FAILED;
            
        }
    }
    else {
        std::cout << "账户或密码错误" << std::endl;
        return LoginResult::FAILED;
    }
}

void Menu::run()
{
    m_purchase.setFilePath(m_filePath);
    m_purchase.iniliazation();
    m_productList = m_purchase.getProductItemList();

    setConsole();

    auto result = loginMenu();
    if (result==LoginResult::USER) {
        int choice;
        system("cls");
        show_menu_first();
        while (1) {
            choice = get_number();
            switch (choice) {
            case 1:
                purchaseProduct();
                system("cls");
                show_menu_first();
                break;
            case 2:
                displayOrder();
                system("cls");
                show_menu_first();
                break;
            case 3:
                showPurchaseTotal();
                system("cls");
                show_menu_first();
                break;
            case 0:

                m_purchase.saveProductItemList(m_productList);

                printf("\n欢迎再次使用！！！\n");      //退出程序
                printf("\n三秒后自动退出程序！！！\n");
                Sleep(1000);
                printf(".");
                Sleep(1000);
                printf(".");
                Sleep(1000);
                printf(".");
                return;
            default:
                printf("请正确输入选项:");
                break;
            }
        }
    }
    else {
        int choice;
        system("cls");
        show_root_menu_first();
        while (1) {
            choice = get_number();
            switch (choice) {
            case 1:
                show_product_info();
                system("cls");
                show_root_menu_first();
                break;
            case 2:
                add_new_productItem();
                system("cls");
                show_root_menu_first();
                break;
            case 0:

                m_purchase.saveProductItemList(m_productList);

                printf("\n欢迎再次使用！！！\n");      //退出程序
                printf("\n三秒后自动退出程序！！！\n");
                Sleep(1000);
                printf(".");
                Sleep(1000);
                printf(".");
                Sleep(1000);
                printf(".");
                return;
            default:
                printf("请正确输入选项:");
                break;
            }
        }
    }

    
}
