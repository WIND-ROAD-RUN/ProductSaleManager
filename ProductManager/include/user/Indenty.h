#ifndef INDENTY_H_
#define INDENTY_H_

#include<string>

class Indenty {
private:
    std::string m_id{ "UNDEFINED" };
    std::string m_name{ "UNDEFINED" };
public:
    Indenty() = default;
    Indenty(const std::string& id, const std::string& name)
        :m_id(id), m_name(name) {}
public:
    void setId(const std::string& id) { m_id = id; }
    void setName(const std::string& name) { m_name = name; }
    std::string getId() const { return m_id; }
    std::string getName() const { return m_name; }
};





#endif // !INDENTY_H_
