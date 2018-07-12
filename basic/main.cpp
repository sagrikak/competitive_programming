#include <iostream>
#include <fstream>//for file handling
#include <string>
#include <string.h>
using namespace std;

class pqr
{
	public:
	pqr(string x)
	{
		name=x;
	}
	void prname()
	{
		cout<<name;
	}
	private:
	string name;
};

template <class T, class U> //function templates//creating generic data types//can handle any type of data//if data types of both numbers are same, only one generric data type can be used
T func(T a, U b)//returns the answer in a's data type
{
	return a+b;
}

class ijk
{
	public:
	//virtual void p()=0; //pure virtual function//every inheriting class must have a 'p' function 
	//a class containing a pure virtual function is called an abstract class
	virtual void p()
	{
		cout<<"ijk is base class."<<endl;//prints if inheriting classes do not have a p() function
	}//polymorphism//virtual funtion indicates presence of polymorphism//common function to the classes which inherit ijk//'virtual' keyword allows the use of this funtion using object of ijk for different inheriting classes
	void print()
	{
		cout<<"Inheritence"<<endl;
	}
};

class xyz: public ijk//private by default
{
	public:
	xyz(int a, int b, pqr x)//constructor
	: y(b), pname(x), x(a)//initializing constant variable and object(assigning required value to object of pqr)
	{
		cout<<"constructor of xyz"<<endl;
	}
	~xyz()//deconstructor
	{
		cout<<"deconstructor of xyz"<<endl;
	}
	int print()
	{
		cout<<"what's up ";
		pname.prname();//using other class to print name
		cout<<"?"<<endl;
		cout<<"y="<<y<<endl;
		cout<<"y="<<this->y<<endl;//'this' keyword stored the address of the current object 
		cout<<"y="<<(*this).y<<endl;//'this' acts like a pointer of the object
		return x;
	}
	void p()
	{
		cout<<"ijk is base class. xyz is derived class."<<endl;
	}

	private:
	int x;
	const int y;//constant variable
	pqr pname;//object of another class
};

template <class V>//class template//generic data type
class abc: public ijk//inherits public variables and functions of ijk class//inheriting class also has access to protected variables and functions
{
	public:
	abc(){}//blank constructor to allow creation of blank object
	abc(V x)
	{
		n=x;
	}
	abc operator+(abc ob2)//function for operator overloading//function returns abc object//one object is given as parameter//function name always starts with 'operator' followed by the operator to be overloaded
	{
		abc sum;//creating a blank object to store sum of other two objects//'abc sum(0)' is also an alternative if blank object is not to be created
		sum.n=(n+ob2.n)/2;//assigning value to the n of sum
		return (sum);
	}
	void p()
	{
		cout<<"ijk is base class. abc is derived class."<<endl;
	}
	private:
	V n;

	friend int main();//using keyword 'friend' to access private variable
};
//derived class does not inherit constructor and deconstructor of base class but they still run.
template<>//template specialization
class abc<string>: public ijk//runs when the data type used is string
{
	public:
	abc(){}//blank constructor to allow creation of blank object
	abc(string x)
	{
		n=x;
		n.assign(x);//same as n=x
		cout<<n.at(0)<<endl;//referring to the fourth element of string
	}
	abc operator+(abc ob2)//function for operator overloading//function returns abc object//one object is given as parameter//function name always starts with 'operator' followed by the operator to be overloaded
	{
		abc sum;
		sum.n="abc";
		return (sum);
	}
	void p()
	{
		cout<<"ijk is base class. abc is derived class."<<endl;
	}
	private:
	string n;

	friend int main();//using keyword 'friend' to access private variable
};

int main()
{
	string name;
	cout<<"Enter your name."<<endl;
	cin>>name;
	try//write your code in try to throw errors
	{
		if(name.length()<=1)
			throw 1;//throwing error
		if(name.length()>=10)
			throw 10;
		cout<<name<<endl;
	}
	catch(int x)//use catch(...) for catching multiple data types
	{
		cout<<"Error Number:"<<x<<endl;
	}
	pqr pqrobject(name);
	xyz xyzobject(20, 50, pqrobject);//constructor runs at the creation of object
	xyz *pointer=&xyzobject;//pointer to object of xyz class
	xyzobject.print();//accessing function of a class using object of that class
	int k=pointer->print();//accessing funtions of a class using pointer of object of that class
	cout<<"x="<<k<<endl;

	cout<<"sum="<<func(5, 1.021521)<<endl;//prints sum of any two numbers of any data type//generic data type//using function template
	
	abc <string> aofabc("ax");//using class template//data type needs to be mentioned in '<>'
	abc <string> bofabc("bx");//if data type is string, template specialization works and c="abc"
	abc <string> cofabc;//blank object
	cofabc=aofabc+bofabc;//operator overloading
	cout<<"c="<<cofabc.n<<endl;//accessing private variable of abc
	cofabc.print();//possible because of inheritence
	
	ijk *pointerxyz=&xyzobject;//pointer of ijk type which refers to object of xyz//since xyz inherits ijk, all the funtions of xyz object that belong ijk can be accessed using this pointer
	ijk *pointerabc=&aofabc;//pointer of ijk type which refers to object of abc// 
	pointerxyz->p();//accessing non-inherited funtion of xyz using pointer of ijk//polymorphism//if 'p' funtion is present in xyz class then it will run otherwise the p function of ijk class will run
	pointerabc->p();//'virtual' keyword allows polymorphism//produce different results based on the object they are pointing to

	ifstream file("samplefile.txt");//to read from a file, ifstream is used// creating ifstream object and associating it with a file
	int number;
	string user;
	if(file.is_open())//checks that the file is opened
		cout<<"The file is opened."<<endl;
	else cout<<"File is not opened."<<endl;
	while(file>>number>>user)//stops when end of the file marker is reached
	{
		cout<<number<<", "<<user<<endl;//prints data from file
	}
	//no need to close the file//automatically closes

	ofstream currentFile("samplefile.txt");//creating file object and associating it with a file//if file is not present, a new file of that name is created//ofstream is used when we write into the file
	//currentFile.open("filehandling.txt");//to open a file into file object
	cout<<endl<<"Enter number and name."<<endl;
	cout<<"Press Ctrl+Z to quit."<<endl;//Ctrl+z -> end of file marker//file ends when Ctrl+z is pressed//ends the program
	while(cin>>number>>user)//runs while file is not ended with Ctrl+z
	{
		currentFile<<number<<' '<<user<<endl;//prints data to file
	}
	currentFile.close();//close file to free memory
}//deconstructor runs at the end of the program