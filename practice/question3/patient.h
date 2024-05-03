#ifndef PATIENT
#define PATIENT
#include<iostream>
#include<cstring>
class patient{
    private:
        int pNo {0};
        char *pName=nullptr;
        float temp[3]{0,0,0};

    public:
        patient() = default;
        patient(int,char*, int []);
        patient(patient &) = default;
        void setTemp();
        float calulateAvgtemp();
        void display(); 
        bool operator==(const patient &p) const{
          return(strcmp(this->pName,p.pName)==0);
        }
        bool operator<(patient &);

        friend std::ostream &operator<<(std::ostream &os, const patient &rhs);
        
};
#endif
