/**
 * @file Config.h
 * @brief Configuration file parser
 * @author Afraz Khan (23P-3034), Hassan Masood (23P-3010)
 * @date November 2025
 */

#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <map>

/**
 * @class Config
 * @brief A class to read and manage configuration from file
 * 
 * Reads key=value pairs from a configuration file and provides
 * methods to retrieve values as different data types.
 */
class Config {
private:
    std::map<std::string, std::string> config; ///< Configuration key-value store
    
public:
    /**
     * @brief Default constructor
     */
    Config();
    
    /**
     * @brief Load configuration from file
     * @param filename Path to configuration file
     * @return true if file was loaded successfully, false otherwise
     */
    bool loadFromFile(const std::string& filename);
    
    /**
     * @brief Get configuration value as string
     * @param key Configuration key
     * @return Value as string, empty string if key not found
     */
    std::string get(const std::string& key);
    
    /**
     * @brief Get configuration value as long double
     * @param key Configuration key
     * @return Value as long double, 0.0 if key not found
     */
    long double getDouble(const std::string& key);
    
    /**
     * @brief Get configuration value as long int
     * @param key Configuration key
     * @return Value as long int, 0 if key not found
     */
    long int getInt(const std::string& key);
};

#endif
