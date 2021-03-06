#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector <int> gray(6);

int check()
{
    if(9*gray[5] + 8*gray[4] + 6*gray[3]+ 5*gray[2]+ 4*gray[1]+ gray[0] < 12)
      return 1;
    else
      return 0;
}

int main()
{
    stack <int> st;
    int k = gray.size();
    int digit;
    int m = 1;
    
    while(k >= 1)
    {
    st.push(k);
    --k;
    }
    
    for(int i = 0; i < gray.size(); i++)
    {
      cout << gray[i] << ' ';
    }
    cout << endl;
    
    while(!st.empty())
    {  
      digit = st.top();                   
      st.pop();
    
      if(gray[gray.size()-digit] == 0)
        gray[gray.size()-digit] = 1;
      else
        gray[gray.size()-digit] = 0;
    
      while(digit - m > 0 && m <= gray.size())
      {
        st.push(digit - m);
        m++;
      }
    
      for(int i = 0; i < gray.size(); i++)
      {
        cout << gray[i] << ' ';
      }
      if(check())
        cout << "<-";
      cout << endl;
      m = 1;
    }
}