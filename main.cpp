#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* pNext;
};

Node* initNode(int value)
{
    Node* p = new Node;

    p->data = value;
    p->pNext = NULL;

    return p;
}

struct Stack
{
    Node* pTop;

};

void initStack(Stack& s)
{
    s.pTop = NULL;
}

void printStack(Stack s)
{
    cout << "STACK = Top<  ";
    for(Node* p = s.pTop; p != NULL ; p = p->pNext)
    {
        cout << p->data << "   ";
    }
    cout << ">" << endl;
}

void push(Stack& s, Node* p)
{
    if(s.pTop == NULL)
    {
        s.pTop = p;
    }
    else
    {
        p->pNext = s.pTop;
        s.pTop = p;
    }

}

void pop(Stack& s)
{
    if(s.pTop == NULL)
        return;
    Node* p = s.pTop;
    s.pTop = p->pNext;

    delete p;
}

int diChuyen(Stack& from, Stack& to)
{
    Node* diaDiChuyen = initNode(from.pTop->data);

    push(to, diaDiChuyen);
    pop(from);
    return 1;
}

void diChuyenVaDem(Stack& from, Stack& to, int& dem)
{
    int kq;
    kq = diChuyen(from, to);
    if(kq == 1) dem += 1;
}

int main()
{

    int soTang;
    int dem = 0;
    int chon;

    Stack sA;
    Stack sB;
    Stack sC;
    initStack(sA);
    initStack(sB);
    initStack(sC);

    while(1)
    {
        cout << endl << endl << endl << endl << endl;
        cout << "=========== Demo Stack =============" << endl;
        cout << "        " << "0. Creating Tower." << endl;
        cout << "        " << "1. A -> B" << endl;
        cout << "        " << "2. B -> A" << endl;
        cout << "        " << "3. B -> C" << endl;
        cout << "        " << "4. C -> B" << endl;
        cout << "        " << "5. C -> A" << endl;
        cout << "        " << "6. A -> C" << endl;
        cout << "        " << "7. All: 6 1 4 6 2 3 6" << endl;

        cout << "====================================" << endl;
        cout << "A Tower" << endl;
        printStack(sA);

        cout << "====================================" << endl;
        cout << "B Tower" << endl;
        printStack(sB);

        cout << "====================================" << endl;
        cout << "C Tower" << endl;
        printStack(sC);

        cout << "====================================" << endl;
        cout << "So lan di chuyen: "  << dem << endl;

        cout << "====================================" << endl;
        cout << "        " << "Please input: ";
        cin >> chon;

        switch(chon)
        {
            case 0:
                cout << endl << "        " << "Nhap so tang: " ;
                cin >> soTang;
                if(soTang < 3)
                {
                    cout << "So tang toi thieu la 3. Nhap lai so tang: ";
                    cin >> soTang;
                }
                initStack(sA);
                for(int i=soTang; i > 0; i--)
                {
                    Node* p = initNode(i);
                    push(sA, p);
                }
                break;
            case 1:
                diChuyenVaDem(sA, sB, dem);
                break;
            case 2:
                diChuyenVaDem(sB, sA, dem);
                break;
            case 3:
                diChuyenVaDem(sB, sC, dem);
                break;
            case 4:
                diChuyenVaDem(sC, sB, dem);
                break;
            case 5:
                diChuyenVaDem(sC, sA, dem);
                break;
            case 6:
                diChuyenVaDem(sA, sC, dem);
                break;
            case 7:
                diChuyenVaDem(sA, sC, dem);
                diChuyenVaDem(sA, sB, dem);
                diChuyenVaDem(sC, sB, dem);
                diChuyenVaDem(sA, sC, dem);
                diChuyenVaDem(sB, sA, dem);
                diChuyenVaDem(sB, sC, dem);
                diChuyenVaDem(sA, sC, dem);
                break;
            default:
                cout << "Khong hop le. Chi duoc nhap cac so 0 -> 7";
                break;
        };
    }

    return 0;
}
