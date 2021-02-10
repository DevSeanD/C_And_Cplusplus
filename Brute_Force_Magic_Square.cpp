/*
Sean Dever
Magic Square
*/


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <stack>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

// Function to find the permutations
vector<int> permutations(int a[], int n)
{
        std::vector<int> perms;
        // Sort the given array
        sort(a, a + n);

        // Find all possible permutations
        do {
                for (int i = 0; i < n; i++)
                {
                        perms.push_back(a[i]);
                }
        } while (next_permutation(a, a + n));

        return perms;
}

long factorial(int n)
{
        int product = 1;
        for(int i=1; i<=n; i++)
        {
                product *= i;
        }

        return product;
}

class square
{
  int **s;
  int size;
  int magicalnumber;

  public:
    square(int, int*);
    square(const square &);
    ~square();
    
    void showme();
    //void rotatec();  //clockwise 90, redundant, counterclockwise 270
    
    //void rotatecc0(); //no rotation
    void rotatecc90(); //counterclockwise 90
    void rotatecc180(); //counterclockwise 90
    void rotatecc270(); //counterclockwise 90
    void reflectdf();  //mirror, flip, D, diagonal forward!
    void reflectdf2();  //mirror, flip, D easier way!
    void reflectdb2();

    void reflectdb();
    void reflecth();
    void reflectv();
    
    bool ismagical();
    bool issymmetric(square &);

    bool issame(square &);
};

/*void square::rotatecc0()
{
}
*/

bool square::issymmetric(square & os)
{
  //try all 8 transformations of os including itself
  //if any of the 8 transformations
  // os itself
  if(issame(os))
    return true;

  //rotation cc 90 degree
  square ns=os;
  ns.rotatecc90();
  if (issame(ns)) 
    return true;
  
  //rotation cc 180
  ns.rotatecc90();
  if(issame(ns))
   return true;
  //rotation cc 270
  ns.rotatecc90();
  if(issame(ns))
    return true;

  // forward diagnal 
  square ndfs=os;
  ndfs.reflectdf2();
  cout<<issame(ndfs);

  // backward diagnal

  //horizontal reflection

  //vertical reflection

  //if none of the 8 transformations match this square
  return false;

}

bool square::issame(square & os)
{
  if (size!=os.size)
  {
    return false;
  }

  for(int row=0; row<size; row++)
    for(int col=0; col<size; col++)
    {
        if (s[row][col]!=os.s[row][col]) return false;
    }
  return true;
}



void square::reflectdb2()
{
  for (int row = 0; row < size; row++)
{
    for (int col = 0; col < row; col++)
    {
        int temp = s[row][col];
        s[row][col] = s[size - 1 - col][size - 1 - row];
        s[size - 1 - col][size - 1 - row] = temp;
    } 
}
}


void square::reflectdf2()
{
  for (int row = 0; row < size; row++)
{
    for (int col = 0; col < row; col++)
    {
        int temp = s[row][col];

        s[row][col] = s[col][row];
        s[col][row] = temp;
    } 
}
}
//this implementation is unncessarily complex!!
void square::reflectdf()
{

    // for diagonal which start from at  
    // first row of matrix 
    int row = 0; 
  
    // traverse all top right diagonal 
    for (int j = 0; j < size; j++) { 
  
        // here we use stack for reversing 
        // the element of diagonal 
        stack<int> st; 
        int i = row, k = j; 
        while (i < size && k >= 0)  
            st.push(s[i++][k--]); 
          
        // push all element back to matrix  
        // in reverse order 
        i = row, k = j; 
        while (i < size && k >= 0) { 
            s[i++][k--] = st.top(); 
            st.pop(); 
        } 
    } 
  
    // do the same process for all the 
    // diagonal which start from last 
    // column 
    int column = size - 1; 
    for (int j = 1; j < size; j++) { 
  
        // here we use stack for reversing  
        // the elements of diagonal 
        stack<int> st; 
        int i = j, k = column; 
        while (i < size && k >= 0)  
            st.push(s[i++][k--]); 
          
        // push all element back to matrix  
        // in reverse order 
        i = j; 
        k = column; 
        while (i < size && k >= 0) { 
            s[i++][k--] = st.top(); 
            st.pop(); 
        } 
    } 
} 
  

void square::reflectv()
{
  rotatecc90();
  reflectdf2();
  
  //using the operations defined the the cayley table http://facstaff.cbu.edu/wschrein/media/M402%20Notes/M402C1.pdf
  //the above page is good, but be careful it has mistakes!!!  
}
void square::reflectdb()
{
  rotatecc90();
  rotatecc90();
  reflectdf2();
}

void square::reflecth()
{
  rotatecc90();
  rotatecc90();
  rotatecc90();
  reflectdf2();

}

bool square::ismagical()
{
  bool flag=true;

  int sum=0;
  for(int index=0; index<size; index++) // Handles forwards diagonal
  {
      sum+=s[index][size-index-1];
  }
  if (sum!=magicalnumber) 
    flag = false;
  
  sum = 0;
  for(int index=0; index<size; index++) // Handles backwards diagonal
  {
      sum += s[size-index-1][index];
  }
  if (sum != magicalnumber)
    flag = false;
  
  sum = 0;
  for(int row=0; row<=(size-1); row++)// Handles rows
  {
    for(int col=0;col<=(size-1); col++)
    {
      sum += s[row][col];
      if(col == (size-1))
      {
        if(sum != magicalnumber)
          flag = false;
          sum = 0;
      }
    }
  }

  for(int col=0; col<=(size-1); col++)// Handles Cols
  {
    for(int row=0; row<=(size-1); row++)
    {
      sum += s[row][col];
      if(row == (size-1))
      {
        if(sum != magicalnumber)
          flag = false;
          sum = 0;
      }
    }
  }

  return flag;
}

square::square(const square &rh) 
{
  cout<<"in copy constructor"<<endl;
  magicalnumber=rh.magicalnumber;
  size=rh.size;
  
  s=new int* [size];

  for(int row=0; row<this->size;row++)
    {
      s[row]=new int[this->size];

      for(int col=0; col<this->size;col++)
        s[row][col]= rh.s[row][col];
    }

}

void square::rotatecc180()
{
  rotatecc90();
  rotatecc90();
  
}
void square::rotatecc270()
{
  rotatecc90();
  rotatecc90();
  rotatecc90();
}

void square::rotatecc90()
{ 
    // Consider all squares one by one 
    for (int x = 0; x < size / 2; x++) { 
        // Consider elements in group 
        // of 4 in current square 
        for (int y = x; y < size - x - 1; y++) { 
            // Store current cell in 
            // temp variable 
            int temp = s[x][y]; 
  
            // Move values from right to top 
            s[x][y] = s[y][size - 1 - x]; 
  
            // Move values from bottom to right 
            s[y][size - 1 - x] 
                = s[size- 1 - x][size - 1 - y]; 
  
            // Move values from left to bottom 
            s[size - 1 - x][size - 1 - y] 
                = s[size - 1 - y][x]; 
  
            // Assign temp to left 
            s[size - 1 - y][x] = temp; 
        } 
    } 
} 
/*
void square::rotatec()
{
 
    // Traverse each cycle
    for (int i = 0; i < size / 2; i++) {
        for (int j = i; j < size - i - 1; j++) {
 
            // Swap elements of each cycle
            // in clockwise direction
            int temp = s[i][j];

            s[i][j] = s[size - 1 - j][i];
            s[size - 1 - j][i] = s[size - 1 - i][size - 1 - j];
            s[size - 1 - i][size - 1 - j] = s[j][size - 1 - i];
            s[j][size - 1 - i] = temp;
        }
    }
}
*/

square::~square()
{
  for(int row=0; row<this->size;row++)
    {
      delete s[row];
      }
  delete [] s;
}

square::square(int size, int *l)
{
  this->size=size;
  
  s=new int*[this->size];
  for(int row=0; row<this->size;row++)
    {
      s[row]=new int[this->size];

      for(int col=0; col<this->size;col++)
        s[row][col]=l[row*this->size+col];
    }

    magicalnumber=(this->size*this->size+1)*this->size/2;
    cout<<magicalnumber<<endl;
}

void square::showme()
{
  cout<<endl;
  for(int row=0; row<this->size;row++)
    {
      for(int col=0; col<this->size;col++)
        cout<<s[row][col]<<"\t";
      cout<<endl;
    }
}

class ms
{
  public:
    void static validatelist(string);
    bool static isunique(square);
};

bool ms::isunique(square s)
{
  bool flag=true;
  //your work!!!

  return flag;

}

void ms::validatelist(string filename)
{
  
  ifstream file(filename);
  string line; // Create a string variable to hold a line

  int n;// value of n
  int totalnumofpermutations;

  file>>n; // First line of file(value of n)
  file>>totalnumofpermutations; // Second line of file

  getline(file, line); //skip the current line
  int * l = new int[n*n]; // Dynamic array of mss * mss(or n^2)

  for(int num=0; num<totalnumofpermutations; num++)
  {
    getline(file, line);
    vector <string> tokens; // This vector of strings will save the elements
    // A vector is an array such that you may continually add new entries to it.

    stringstream my(line); 
    string intermediate; 

    // Tokenizing w.r.t. space ' ' 
    char delimiter=':';
    while(getline(my, intermediate, delimiter)) 
    { 
        tokens.push_back(intermediate);// Adding values to the vector tokens
    }
    stringstream it(tokens[1]); 

    vector <string> elements;

    delimiter=' '; 

    while(getline(it, intermediate, delimiter)) 
    { 
        elements.push_back(intermediate); // Using the push_back function to add elements to vector
    } 

    for(int i = 0; i < elements.size(); i++) 
    {      
      l[i]= atoi(elements[i].c_str());
    }

  square *s = new square(n, l); // l is an array of 
  s -> showme();
  cout << endl;

  if (s -> ismagical()) 
    cout<<"is a magical square"<<endl;
  else
    cout<<"is not a magical square"<<endl;
    
  /*
  // redundant. Counterclockwise can do
  square sn=*s;
  sn.rotatec();
  sn.showme();
  
  sn.rotatec();
  sn.showme();
  
  sn.rotatec();
  sn.showme();
  
  square sn2=*s;

  cout<<"counterclock wise 90"<<endl;
  sn2.rotatecc90();
  sn2.showme();
  cout<<"counterclock wise 180"<<endl;
  sn2.rotatecc90();
  sn2.showme();
  cout<<"counterclock wise 270"<<endl;
  sn2.rotatecc90();
  sn2.showme();

  cout<<"reflected with respect to forward diagnal"<<endl;
  square sn3=*s;
  sn3.reflectdf();
  sn3.showme();
  
  cout<<"reflected with respect to backward diagnal"<<endl;
  square sn4=*s;
  sn4.reflectdb();
  sn4.showme();
  
  cout<<"reflected with respect to horizontal"<<endl;
  square sn5=*s;
  sn5.reflecth();
  sn5.showme();

  cout<<"reflected with respect to vertical"<<endl;
  square sn6=*s;
  sn6.reflectv();
  sn6.showme();
  */

}
delete [] l; // to avoid memory leaking

}

int main(int argc, char* argv[]) {
  string filename = argv[1]; // Read the first command line argument as the file name
  if(filename == "1")
  {
    cout << "There is 1 Magic Square with n = 1" << endl;
    cout << "1" << std::endl;
    return 0;
  }

  if(filename == "2")
  {
    cout << "No Magic Squares with n = 2 exist." << endl;
    return 0;
  }


  if(filename == "3")
  {
    int counter = 0;
    int lineCount = 0;
    int userN = std::stoi(filename);
    int elements[userN*userN];
        int index = 0;
        for(int k = 1; k <= userN*userN; k++){
                elements[index] = k;
                index++;
        }
    int n = sizeof(elements) / sizeof(elements[0]);
    std::vector<int> permuVector = permutations(elements,n);
  
    // outFile creation     
    ofstream outFile;
    outFile.open("p"+to_string(userN)+".txt");
    outFile << userN << std::endl;
    outFile << factorial(userN * userN) << std::endl;
    outFile << lineCount << ":";
    for(int x: permuVector){
      if(counter == userN*userN){
        lineCount++;
        outFile <<  " " << std::endl;
        outFile << lineCount << ":";
        counter = 0;
        }
        outFile <<  x << " ";
        counter ++;
      }
      outFile << " " << std::endl;
      ms::validatelist("p"+to_string(userN)+".txt");
  
  }

  ms::validatelist(filename);
  
  return 0;

}
