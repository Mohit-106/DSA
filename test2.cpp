#include <bits/stdc++.h>
using namespace std;

struct StudentRec
{

    int *enrolNo;
    float *CGPA;
    string *branch;

    void arrays()
    {

        this->enrolNo = new int[3];
        this->CGPA = new float[3];
        this->branch = new string[3];
    }

    void setData()
    {
        for (int i = 0; i < 3; i++)
        {

            cin >> enrolNo[i];
            cin >> CGPA[i];
            cin>>branch[i];
        }
    }

    void sort()
    {
        int i, j, temp;
        for (i = 0; i <3; i++)
            for (j = i + 1; j < 3; j++)
                if (CGPA[i] > CGPA[j])
                {
                    float temp = CGPA[i];
                    CGPA[i] = CGPA[j];
                    CGPA[j] = temp;

                    int temp1 = enrolNo[i];
                    enrolNo[i] = enrolNo[j];
                    enrolNo[j] = temp1;

                    string temp2 = branch[i];
                    branch[i]=branch[j];
                    branch[j]=temp2;

                }
    }

    void display(){
        for(int i=0;i<3;i++){
            cout<<enrolNo[i]<<endl<<CGPA[i]<<endl<<branch[i]<<endl;
            cout<<endl;
        }
    }

};

int main()
{

    StudentRec *student = new StudentRec();
    student->arrays();
    student->setData();
    cout<<"Unsorted Data"<<endl;
    student->display();
    student->sort();
    cout<<"Sorted Data"<<endl;
    student->display();
    

    return 0;
}