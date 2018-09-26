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
    int chk;
    
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
    
      int j = 1;
      while(digit - j > 0 && j < gray.size()+1)
      {
        st.push(digit - j);
        j++;
      }
    
      j = 1;
      
      for(int i = 0; i < gray.size(); i++)
      {
        cout << gray[i] << ' ';
      }
      if(check())
        cout << "<-";
      cout << endl;
    }
        
}