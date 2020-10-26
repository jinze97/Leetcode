#include <vector>
#include <map>
#include <unordered_map>


template <class T>
std::string get_data_type(const T& data)
{
    if(true == std::is_same<T, char>::value) {
        return "char";
    } else if(true == std::is_floating_point<T>::value) {
        return "float";
    } else if(true == std::is_pointer<T>::value) {
        return "point";
    } else if(true == std::is_same<T, std::string>::value) {
        return "string";
    } else if(true == std::is_integral<T>::value) {
        return "int";
    } else {
        return "unknow";
    }
}


template <class T>
char get_full_char(const T & data)
{
    std::string flag = get_data_type(data);
    char cFull;
    if("char" == flag) {
        cFull = '\'';
    } else if("string" == flag) {
        cFull = '"';
    } else {
        cFull = ' ';
    }
    return cFull;
}


template <class T>
void print_data(const T & data, const char & chr = ' ')
{
    if(' ' == chr) {
        std::cout << data;
        return;
    }
    std::cout << chr << data << chr;
}


template <class T>
void print(const std::vector<T>& vdata)
{

    std::cout << '[';
    if(!vdata.size()) {
        std::cout  << ']' << std::endl;
        return;
    };

    char cFull = get_full_char(vdata[0]);
    for(int i = 0; i < vdata.size(); ++i) {
        if(0 == i) {
            print_data(vdata.at(i), cFull);
        } else {
            std::cout << ", ";
            print_data(vdata.at(i), cFull);
        }
    }
    std::cout  << ']' << std::endl;
}


template <class T, class U>
void print(const std::unordered_map<T, U>& mData)
{
    std::cout << '{';
    if(!mData.size()) {
        std::cout << '}' <<std::endl;
        return;
    };

    int idx = 0;
    auto pIndex = mData.begin();
    char cKeyFull = get_full_char(pIndex->first);
    char cValueFull = get_full_char(pIndex->second);
    for(auto elem: mData) {
        if(++idx == 1) {
            print_data(elem.first, cKeyFull);
            std::cout << ':';
            print_data(elem.second, cValueFull);
        } else {
            std::cout << ", ";
            print_data(elem.first, cKeyFull);
            std::cout << ':';
            print_data(elem.second, cValueFull);
        }
    }
    std::cout << '}' << std::endl;
}



