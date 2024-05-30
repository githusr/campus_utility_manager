#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

template <typename T> class DataManager
{
public:
    DataManager();
    void addData(T data);
    void removeData(T data);
    void updateData(T data);
    T getData();
    void setData(T data);

private:
    
};

#endif