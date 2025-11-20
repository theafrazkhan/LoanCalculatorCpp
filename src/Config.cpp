#include "Config.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

Config::Config() {
}

bool Config::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    
    string line;
    while (getline(file, line)) {
        // skip comments and empty lines
        if (line.empty() || line[0] == '#') {
            continue;
        }
        
        // parse key=value
        size_t pos = line.find('=');
        if (pos != string::npos) {
            string key = line.substr(0, pos);
            string value = line.substr(pos + 1);
            config[key] = value;
        }
    }
    
    file.close();
    return true;
}

string Config::get(const string& key) {
    if (config.find(key) != config.end()) {
        return config[key];
    }
    return "";
}

long double Config::getDouble(const string& key) {
    string value = get(key);
    if (!value.empty()) {
        return stold(value);
    }
    return 0.0L;
}

long int Config::getInt(const string& key) {
    string value = get(key);
    if (!value.empty()) {
        return stol(value);
    }
    return 0;
}
