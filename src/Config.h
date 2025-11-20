#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <map>

class Config {
private:
    std::map<std::string, std::string> config;
    
public:
    Config();
    bool loadFromFile(const std::string& filename);
    std::string get(const std::string& key);
    long double getDouble(const std::string& key);
    long int getInt(const std::string& key);
};

#endif
