#include <iostream>

using namespace std;

class Vehicle
{

private:
    int type; //1- 2 wheerler 2-4 wheeler
    int speed;
    bool head;
    bool tail;
    bool light;
    char beam;


public:
    Vehicle(int t,int s )
    {
        type=t;
        speed=speedCheck(t,s);
        head=tail=false;
        beam='l';
    }
    int speedCheck(int t,int speed)
    {
        if(type==1)
        {
            if(speed>120)
                speed=120;
            if(speed<0)
                speed=0;
        }
        if(type==2)
        {
            if(speed>180)
                speed=180;
            if(speed<0)
                speed=0;
        }
        return speed;

    }
    void breaking(int t)//2 wheeler
    {
        speed=speed-5;
        speed=speedCheck(t,speed);
        cout<<"Break applied . Speed is: "<<speed<<endl;

    }

    void breaking()//4 wheeler
    {
        speed=speed-10;
        speed=speedCheck(2,speed);
        cout<<"Break applied . Speed is: "<<speed<<endl;

    }

    void acceleration(int t)//2 wheeler
    {
        speed=speed+5;
        speed=speedCheck(t,speed);
        cout<<"Acceleration. Speed is: "<<speed<<endl;


    }

    void acceleration()//4 wheeler
    {
        speed=speed+10;
        speed=speedCheck(2,speed);
        cout<<"Acceleration . Speed is: "<<speed<<endl;


    }

    int lightfunc(int type,int ligSt,int ltyp)//2 wheeler
    {
        if (ligSt==1)//on
        {
            if(ltyp==1)
                cout<<"Switching head light ON"<<endl;
            else if(ltyp==2)
                cout<<"Switching tail light ON"<<endl;
             else if(ltyp==3)
                cout<<"Switching both lights ON"<<endl;
            light=true;
        }
        else if(ligSt==2)
        {
            if(ltyp==1)
                cout<<"Switching head light OFF"<<endl;
            else if(ltyp==2)
                cout<<"Switching tail light OFF"<<endl;
             else if(ltyp==3)
                cout<<"Switching both lights OFF"<<endl;
            light=false;
        }
    }

    int lightfunc(int type,int ligSt,int ltyp,char beam)//4 wheeler
    {
        if (ligSt==1)//on
        {
            if(ltyp==1)
                cout<<"Switching head light ON"<<endl;
            else if(ltyp==2)
                cout<<"Switching tail light ON"<<endl;
             else if(ltyp==3)
                cout<<"Switching both lights ON"<<endl;
            light=true;
        }
        else if(ligSt==2)
        {
            if(ltyp==1)
                cout<<"Switching head light OFF"<<endl;
            else if(ltyp==2)
                cout<<"Switching tail light OFF"<<endl;
             else if(ltyp==3)
                cout<<"Switching both lights OFF"<<endl;
            light=false;
        }

        if(beam=='h')
            cout<<"HIGH BEAM"<<endl;
        else if(beam=='l')
            cout<<"LOW BEAM"<<endl;
    }
};
int main()
{
    int ch,ch1,s,lch,l2ch;
    char beam;
    //while(1)
    {
        //cout<<"Press- .1. for two wheeler and .2. for four wheeler"<<endl;
        //cin>>ch; 
        ch=2;
        //cout<<"Enter the speed of the vehicle\n";
        //cin>>s;
        s=40;
        ch1=0;


        if(ch==1)//2 wheeler
        {
            Vehicle two_wheeler(1,s);
            while(ch1!=4)
            {
                cout<<"\n 1. Breaking 2. Acceleration 3. Light 4.Quit\nEnter the function for the two wheeler:\n";
                cin>>ch1;

                if(ch1==1)
                {
                    two_wheeler.breaking(1);
                }
                else if(ch1==2)
                {
                    two_wheeler.acceleration(1);
                }
                else if(ch1==3)
                {
                   cout<<"1: ON  2: OFF  \nChoose light Option: "<<endl;
                   cin>>lch;
                   cout<<"1. Headlight  2. Tail Light  3. Both\n";
                   cin>>l2ch;
                   two_wheeler.lightfunc(1,lch,l2ch);
                }
            }

        }
        else if(ch==2)//4 Wheeler
        {
            Vehicle four_wheeler(2,s);
            //while(ch1!=4)
            if(ch1!=4)
            {
                //cout<<"\n 1. Breaking 2. Acceleration 3. Light 4.Quit\nEnter the function for the four wheeler:\n";
                //cin>>ch1;
                ch1=1;

                if(ch1==1)
                {
                    four_wheeler.breaking();
                }
                else if(ch1==2)
                {
                    four_wheeler.acceleration();
                }
                else if(ch1==3)
                {
                   cout<<"1: ON  2: OFF  \nChoose light Option: "<<endl;
                   cin>>lch;
                   cout<<"Enter beam choice: [h-HIGH l-LOW]"<<endl;
                   cin>>beam;
                   cout<<"1. Headlight  2. Tail Light  3. Both\n";
                   cin>>l2ch;

                    four_wheeler.lightfunc(2,lch,l2ch,beam);
                }
            }


        }
        else
            cout<<"Wrong option"<<endl;
    }

    return 0;
}
