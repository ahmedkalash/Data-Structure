#include <iostream>
#include "string"
#include "vector"
#include "cmath"
#include "mergeSort.h"
#include "quickSort.h"
#include "heapSort.h"
#include "kalashMaxHeap.cpp"
#include "kalashGraph.cpp"
#define ss << " " <<
#define nn <<endl

using namespace std;


void moveDisks(int count, int start, int finish, int temp)
{
    if(count > 0) {
        moveDisks(count - 1, start, temp, finish);
        cout << count ss start ss temp  ss finish nn;
        moveDisks(count - 1, temp, finish, start);
    }
}

bool precedenc(char op1, char op2)
{
    if(op1=='$') // $ is the power
        return 1;
    if(op1=='*' ||op1=='/')
        return (op2!='$');
    if(op1=='+' || op1=='-')
        return ((op2!='$') && (op2!='*') && (op2!='/'));
    return 0;

}
void infixToPostFix(const string& inFix, string& postFix)
{
    char curr_operator;
    vector<char> stack;
    for (char i : inFix)
    {
        if(isdigit(i))
            postFix.push_back(i);
        else
        {
            curr_operator = i;
            if(stack.empty())
                stack.push_back(i);
            else
            {
                while (precedenc(*(stack.end()-1), curr_operator) && !stack.empty())
                {
                    postFix.push_back(*(stack.end()-1));
                    stack.pop_back();
                }
                stack.push_back(curr_operator);
            }
        }
    }
    while (!stack.empty())
    {
        postFix.push_back(*(stack.end()-1));
        stack.pop_back();
    }

}

int toDigit(char c)
{
    return (c-48);
}

double evaluat(char sign, double f, double s)
{
    if(sign=='$') return pow(f,s);
    if(sign=='*') return f*s;
    if(sign=='/') return f/s;
    if(sign=='+') return f+s;
    if(sign=='-') return f-s;


}
double evaluatePostfix( string& postFix)
{
    double f,s,value;
    vector<double> stack;
    for (char j : postFix)
    {
        if(isdigit(j))
            stack.push_back(j);
        else
        {
            s=toDigit(*(stack.end()-1));stack.pop_back();
            f= toDigit(*(stack.end()-1));stack.pop_back();
            value= evaluat(j,f, s);
            stack.push_back(value);
        }
    }
    value = *(stack.end()-1);
    return value;

}
bool isOpenPar(char par)
{
    if(par=='['|| par=='{' || par=='(')
        return true;
    return false;

}
bool isCupel(char par1, char par2)
{
    if(par1=='[' && par2==']') return true;
    if(par1=='{' && par2=='}') return true;
    if(par1=='(' && par2==')') return true;
    return false;
}
bool checkParentheses(string s)
{
    vector<char> par;
    for (char & i : s) {
        if(isOpenPar(i))
            par.push_back(i);
        else {
            if (par.empty()) return false;
            else
            if(isCupel(*(par.end()-1),i))
                //cout << *(par.end()-1)<< i;
                par.pop_back();
        }
    }
    if(!par.empty()) return false;
    return true;
}

template<typename T>
void printlist(T item)
{
    cout << item << " ";
}

template<typename T>
void printTree(T item)
{
    cout << item << " ";
}

template<typename T>
void printArray(T array[], int size)
{
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " "  ;
    }
    cout << endl;
}

template<typename GraphItem>
void printGraph(GraphItem item)
{
    cout << item;
}


template<typename PrimitiveType>
bool greaterPriorEqFUN( PrimitiveType p,  PrimitiveType q)
{
    return (p  >= q) ;
}

class greaterPriorEq
{

public:
    template<typename PrimitiveType>
    bool operator()(const PrimitiveType& p, const PrimitiveType& q) const
    {
        return p  >= q ;
    }
};

class lessPriorEq
{

 public:
    template<typename PrimitiveType>
    bool operator()(const PrimitiveType& p, const PrimitiveType& q) const
    {
        return p  <= q ;
    }
};

class comp
{
public:
    bool operator()(int a, int b)
    {
        return (a>=40) ;
    }
};

int main()
{

    /*int arr[9] ={10,5,6,0,7,6,1,9,5};
    mergeSort(arr,0,8);
    cout << " Using merge sort:\n";
    printArray(arr,9);

    cout << "\n\n";

    int arr2[9] ={10,5,6,0,7,6,1,9,5};
    quicksort(arr2,0,8);
    cout << " Using quick sort:\n";
    printArray(arr2,9);

    cout << "\n\n";


    int arr3[9] ={10,5,6,0,7,6,1,9,5};
    kalashMaxHeap<int,greaterPriorEq> pQ(9,arr3);
    pQ.heapSort();
    cout << " Using heap Sort:\n";
    pQ.print();

    cout << "\n\n";


    // ={'z','g','h','a','i','h','a','y','g'};
    int arr4[9]  ={10,5,6,0,7,6,1,9,5};
    cout << " Using heap Sort in place:\n";
    heapSort(arr4,0,8);
    for (auto i:arr4)
        cout << i << " ";*/


/*  kalashGraph<int> graph(10);
  graph.add(0);
  graph.add(1);
  graph.add(2);
  graph.add(3);


    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);

    graph.BFS(2,&printGraph);*/






















}
