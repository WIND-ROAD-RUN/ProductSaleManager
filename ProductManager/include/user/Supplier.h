#ifndef SUPPLIER_H_
#define SUPPLIER_H_

#include"Indenty.h"
#include<string>

class Supplier
    :public Indenty {
private:
    std::string m_phoneNumber{ "UNDEFINED" };
    std::string m_address{ "UNDEFINED" };
    bool m_isLongTermSupply{ false };
public:
    Supplier() {}
    ~Supplier() {}
public:
    void setPhoneNumber(const std::string& phoneNumer) { m_phoneNumber = phoneNumer; }
    void setAddress(const std::string& address) { m_address = address; }
    void setLongTermSupply(bool isLongTermSupply) { m_isLongTermSupply = isLongTermSupply; }
    std::string getPhoneNumber() const { return m_phoneNumber; }
    std::string getAddress() const { return m_address; }
    bool getIsLongTermSupply() const { return m_isLongTermSupply; }
    void setIsLongTermSupply(bool isLongTermSupply) { m_isLongTermSupply = isLongTermSupply; }
    Indenty getIndenty() const { return Indenty(getId(), getName()); }

};



#endif // !SUPPLIER_H_
