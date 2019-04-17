#include <iostream>
#include <string>
#include <list>
#include <fstream>

using namespace std;
class parameters
{
    public:
    parameters(int nh, int nw, int np): h(nh), w(nw), p(np) {};
    int h,w,p;
};
bool threeRooms(int h, int w, int p)
{
    if((h < 2 && w < 2) || h < 1 || w < 1)
        return false;
    
    int room1A, room2A, room3A;
    int room1B, room2B, room3B;
    int room1C, room2C, room3C;
    int room1D, room2D, room3D;
    
    
    for(int i = 1 ; i < w ; i++)
    {
        for(int j = 1; j < h ; j++)
        {
            room1A = 2*i     + 2*h;
            room1B = 2*(w-i) + 2*h;
            room1C = 2*w     + 2*j;
            room1D = 2*w     + 2*(h-j);
            
            room2A = 2*(w-i)  + 2*j;
            room2B = 2*i      + 2*j;
            room2C = 2*i      + 2*(h-j);
            room2D = 2*i      + 2*j;
            
            room3A = 2*(w-i) + 2*(h-j);
            room3B = 2*i     + 2*(h-j);
            room3C = 2*(w-i) + 2*(h-j);
            room3D = 2*(w-i) + 2*j;
                
            if(room1A + room2A + room3A == p)
                return true;
            if(room1B + room2B + room3B == p)
                return true;
            if(room1C + room2C + room3C == p)
                return true;
            if(room1D + room2D + room3D == p)
                return true;
            
        }
    }
    
    int roomX, roomY, roomZ;
    for(int i = 1 ; i < w ; i++)
    {
        for(int j = 1 ; j < w ; j++)
        {
            if(j != i)
            {
                roomX = 2*h + 2*i;
                roomY = 2*h + 2*j;
                roomZ = 2*h + 2*(w-i-j);
                
                if(roomX + roomY + roomZ == p)
                    return true;
            }
        }
    }
    
    for(int i = 1 ; i < h ; i++)
    {
        for(int j = 1 ; j < h ; j++)
        {
            if(j != i)
            {
                roomX = 2*w + 2*i;
                roomY = 2*w + 2*j;
                roomZ = 2*w + 2*(h-i-j);
                
                if(roomX + roomY + roomZ == p)
                    return true;
            }
        }
    }
    
    return false;
    
}

int main ()
{
    ofstream testCases;
    testCases.open("testCases.txt");
    int h=0,w=0,p=0;
    list<parameters> inputs;
    
    for(int a = 0 ; a <= 10 ; a++)
        for(int b = 0 ; b <= 10 ; b++)
            for(int c = 0 ; c <= 100 ; c++)
                inputs.push_back(parameters(a,b,c));
    
    testCases << "###COMENCING TESTS###" << endl;
    
    for(parameters input : inputs)
    {
        h = input.h;
        w = input.w;
        p = input.p;
        
        if(threeRooms(h,w,p))
        {
            testCases << "Testing " << h << " " << w << " " << p;
            testCases << ": threeRooms(h,w,p) returns = " << (threeRooms(h,w,p) ? ("Yes") : ("No")) << endl;
        }
            
    }
    
    testCases << "###END OF TESTS###" << endl;
    
    testCases.close();
    return 0;
}
