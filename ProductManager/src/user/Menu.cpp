#include "Menu.h"

LoginResult Menu::loginMenu()
{
    using namespace std;

    string account;
    string password;
    LoginResult result;
    do {
        cout << "�������˻�:";
        cin >> account;
        cout << "����������:";
        cin >> password;
        result = loginCheck(Account(account, password));
    } while(result ==LoginResult::FAILED);
    
    return result;

}

int Menu::get_number()
{
    int op;
    while (scanf("%d", &op) != 1) {
        printf("���������֣�");
        while (getchar() != '\n')
            continue;
    }
    return op;
}

double Menu::get_double()
{
    double op;
    while (scanf("%lf", &op) != 1) {
        printf("���������֣�");
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
        
        printf("            ��ӭ������Ʒ��Ϣ����ϵͳ                      ");
        
        printf("*\n*");
        
        printf("������ϵͳ�ṩ�Ĳ�����                                    ");
        
        printf("*\n*                                                          *\n*");
        
        printf("  1.��ʾ������Ʒ��Ϣ�����빺�ﳵ                          ");
        
        printf("*\n*");
        
        printf("  2.�鿴���ﳵ                                            ");
        
        printf("*\n*");
       
        printf("  3.��������ι������Ʒ�ܶ�                              ");
       
        printf("*\n*");
        printf("                                                          *\n");
        printf("*                                                          ");
        printf("*\n*");
        
        printf("           ע�⣺���������Ž�����һ����ѡ�񣨰���0�˳���");
        
        printf("*\n*");
        printf("***********************************************************\n");
       
        printf("���������ѡ�");
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
    printf("\n�����Ʒ����Խ��й���\n");
    while (1) {
        choice = get_number();
        if (choice==0) {
        printf("\n��ȫ�����빺�ﳵ������Զ��˳��˲˵�������\n");
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
            printf("����ȷ������Ʒ���:");
        }
        else {
            printf("�����빺���������\n");
            int quantity = get_number();
            m_order.push_back(ProductItemOrder(findProductItem,quantity));
            printf("��ӹ��ﳵ�ɹ�\n");
            printf("�����Ҫ���������������Ʒ��ţ��˳��������������0\n");
        }

    }
}

void Menu::showProductInfoTableHead()
{
    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("%-10s|%-10s|%-15s|%-16s|%-16s|%-14s|%-6s|%-6s\n", "��Ʒ���", "��Ʒ��", "��Ʒ����", "��Ӧ��", "��Ӧ�̱��", "��Ӧ���ֻ���", "�Ƿ�Ϊ���ڹ�Ӧ��","��Ӧ�̵�ַ");
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
            printf("%-16s", "��");
        }
        else {
            printf("%-16s", "��");
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
    printf("\n����0�˳���\n");
    while (1) {
        choice = get_number();
        if (choice == 0) {
            printf("\n������Զ��˳��˲˵�������\n");
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
    printf("%-10s|%-10s|%-15s|%-16s|%-16s|%-6s\n", "��Ʒ���", "��Ʒ��", "��Ʒ����", "��Ӧ��", "��Ӧ�̱��", "��������");
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
    printf("���ﳵ�����е���Ʒ�ܶ�Ϊ��%lf\n\n", getTotalMoney());
    printf("\n����0�˳���\n");
    while (1) {
        choice = get_number();

        if (choice == 0) {
            printf("\n������Զ��˳��˲˵�������\n");
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
        printf("              ������root����˵�ѡ��                      ");
        printf("*\n*");
        printf("������ϵͳ�ṩ�Ĳ�����                                    ");
        printf("*\n*                                                          *\n*");
        printf("  1.��ʾ������Ʒ��Ϣ                                      ");
        printf("*\n*");
        printf("  2.����µĲ�Ʒ��Ϣ                                      ");
        printf("*");
        printf("\n*");
        printf("                                                          *\n");
        printf("*                                                          ");
        printf("*\n*");
        printf("           ע�⣺���������Ž�����һ����ѡ�񣨰���0�˳���");
        printf("*\n*");
        printf("***********************************************************\n");

        printf("���������ѡ�");
    }
}

void Menu::show_product_info()
{
    int choice;
    std::string choice_to_string;

    system("cls");
    showProductInfoTableHead();
    showProductInfoTableTail();
    printf("\n����0�˳���\n");
    while (1) {
        choice = get_number();
        if (choice == 0) {
            printf("\n������Զ��˳��˲˵�������\n");
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
    printf("\n����1��Ӳ�Ʒ��Ϣ������0�˳���\n");
    while (1) {
        choice = get_number();
        if (choice == 0) {
            printf("\n������Զ��˳��˲˵�������\n");
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

            cout << "�������Ʒ���֣�" << endl;
            cin >> temp;
            newItem.first.setName(temp);

            cout << "�������ƷID��" << endl;
            id = get_number();
            newItem.first.setId(std::to_string(id));

            cout << "�������Ʒ�۸�" << endl;
            price = get_double();
            newItem.first.setPrice(price);

            cout << "��ѡ���Ʒ���ͣ�" << endl;
            cout << "1: �·�   " << "2: ����Ʒ   " << "3: ҩƷ   " << "4: ����Ʒ   " << endl;
            cout << "5: ���Ӳ�Ʒ   " << "6: Ь��   " << "7: ��ױƷ   " << "8: �ݳ�Ʒ   " << endl;
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
                    printf("\n����ȷ����ѡ��\n");
                }
            }
            cout << "�����빩Ӧ�����֣�" << endl;
            cin >> temp;
            newItem.second.setName(temp);

            cout << "�������Ʒ��Ӧ��ID��" << endl;
            id = get_number();
            newItem.second.setId(std::to_string(id));

            cout << "�����빩Ӧ�̵�ַ��" << endl;
            cin >> temp;
            newItem.second.setAddress(temp);

            cout << "�����빩Ӧ���ֻ��ţ�" << endl;
            cin >> temp;
            newItem.second.setPhoneNumber(temp);

            cout << "�������Ƿ�Ϊ���ڹ�Ӧ�̣�0Ϊ������ֵΪ�ǣ���" << endl;
            id = get_number();
            if (id) {
                newItem.second.setIsLongTermSupply(true);
            }
            else {
                newItem.second.setIsLongTermSupply(false);
            }
            printf("\n��ӳɹ�\n");
            m_productList.push_back(newItem);
            printf("\n����1��Ӳ�Ʒ��Ϣ������0�˳���\n");
        }
        
        else  {
            printf("����ȷ����ѡ��\n");
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
            std::cout << "�˻����������" << std::endl;
            return LoginResult::FAILED;
        }
    }
    else if (account.first == "user") {
        if (account.second == "user") {
            return LoginResult::USER;
        }
        else {
            std::cout << "�˻����������" << std::endl;
            return LoginResult::FAILED;
            
        }
    }
    else {
        std::cout << "�˻����������" << std::endl;
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

                printf("\n��ӭ�ٴ�ʹ�ã�����\n");      //�˳�����
                printf("\n������Զ��˳����򣡣���\n");
                Sleep(1000);
                printf(".");
                Sleep(1000);
                printf(".");
                Sleep(1000);
                printf(".");
                return;
            default:
                printf("����ȷ����ѡ��:");
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

                printf("\n��ӭ�ٴ�ʹ�ã�����\n");      //�˳�����
                printf("\n������Զ��˳����򣡣���\n");
                Sleep(1000);
                printf(".");
                Sleep(1000);
                printf(".");
                Sleep(1000);
                printf(".");
                return;
            default:
                printf("����ȷ����ѡ��:");
                break;
            }
        }
    }

    
}
