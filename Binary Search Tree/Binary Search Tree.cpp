

#include <iostream>
using namespace std;

class BST
{

    
    struct Tree
    {

        int value;
        Tree* Left=NULL;
        Tree* Right=NULL;


    };
    Tree* Root = NULL;
public:

    void DeleteNode(int num, Tree*& nodePtr);
    void makeDeletion(Tree*& nodePtr);
    void insertNode(int num);
    void remove(int num);
    bool search(int num);
    void displayInOrder(Tree *temp);
    void displayPreOrder(Tree* temp);
    void displayPostOrder(Tree* temp);
    void showInOrder(void);
    void showPreOrder(void);
    void showPostOrder(void);
    
    
};
    void BST::insertNode(int num)
    {
        Tree* Node = new Tree;
        Tree* Ptr = NULL;;
        Node->value = num;
        if (Root == NULL) 
        {
            Root = Node;
            cout << "Node successfull Inserted" << endl;
        }
        else
        {
            Ptr = Root;
            
                while (Ptr!= NULL)
                {
                    if (num < Ptr->value)
                    {
                        if (Ptr->Left != NULL)
                            Ptr= Ptr->Left;
                        else
                        {
                            Ptr->Left = Node;
                            cout << "Node successfull Inserted" << endl;
                            break;
                        }
                    }
                    else if (num > Ptr->value)
                    {
                        if (Ptr->Right)
                            Ptr=Ptr->Right;
                        else
                        {
                            Ptr->Right = Node;
                            cout << "Node successfull Inserted" << endl;
                            break;
                        }
                    }
                    else
                    {
                        cout << "Duplicate value found in tree.\n";
                        break;
                    }
                }
        }
    }


    void BST::remove(int num)
    {

        DeleteNode(num, Root);

    }



    void BST::DeleteNode(int num, Tree*& nodePtr)
    {
        if (num < nodePtr->value)
            DeleteNode(num, nodePtr->Left);
        else if (num > nodePtr->value)
            DeleteNode(num, nodePtr->Right);
        else
            makeDeletion(nodePtr);
    }



    void BST::makeDeletion(Tree*& nodePtr)
    {
        Tree* temp;

        if (nodePtr == NULL)
            cout << "Cannot delete empty node.\n";

        else if (nodePtr->Right == NULL)
        {
            temp = nodePtr;
            nodePtr = nodePtr->Left;
            delete temp;

            cout << "Node Successfully Deleted" << endl;
        }

        else if (nodePtr->Left == NULL)
        {
            temp = nodePtr;
            nodePtr = nodePtr->Right;
            delete temp;

            cout << "Node Successfully Deleted" << endl;
        }

        else
        {
            temp = nodePtr->Right;
            while (temp->Left != NULL)
                temp = temp->Left;

            temp->Left = nodePtr->Left;
            temp = nodePtr;

            nodePtr = nodePtr->Right;

            cout << "Node Successfully Deleted" << endl;
            delete temp;
        }
    }

    void BST::showInOrder(void)
    {


        displayInOrder(Root);



    }


    void BST::displayInOrder(Tree* Temp)
    {
        if (Temp)
        {
            displayInOrder(Temp->Left);
            cout << Temp->value << endl;
            displayInOrder(Temp->Right);
        }



    }
    void BST:: showPreOrder(void)
    {
        displayPreOrder(Root);

        
    }

    void BST:: displayPreOrder(Tree* Temp)
    {
        if (Temp)
        {
            cout << Temp->value << endl;
            displayPreOrder(Temp->Left);
            displayPreOrder(Temp->Right);
        }
    }
    void BST::showPostOrder(void)
    {


        displayPostOrder(Root);

    }
    void BST::displayPostOrder(Tree* Temp)
    {
        if (Temp)
        {
            displayPostOrder(Temp->Left);
            displayPostOrder(Temp->Right);
            cout << Temp->value << endl;
        }
    }




    bool BST:: search(int num)
    {
        Tree* Temp = Root;
        while (Temp)
        {
            if (Temp->value == num)
                return true;
            else if (num < Temp->value)
                Temp=Temp->Left;
            else
                Temp = Temp->Right;
        }
        return false;
    }
int main()
{
    BST T;

    bool Pass = true;

    char choice;

    int num;

    bool exists;
    while (Pass == true)
    {
        cout << endl << endl;
        cout << "1: Insert a Node" << endl;
        cout << "2: Delete a Node" << endl;
        cout << "3:Show Tree Traversal via InOrder" << endl;
        cout << "4:Show Tree Traversal via PreOrder" << endl;
        cout << "5:Show Tree Traversal via PostOrder" << endl;
        cout << "6: Search for a Number" << endl;
        cout << "7: Exit the program" << endl << endl << endl;

        cout << "Enter your choice" << endl;
        cin >> choice;


        switch (choice)
        {

        case '1':
        {

            cout << "Enter Node to be inserted" << endl;
            cin >> num;
            T.insertNode(num);
            break;


        }

        case '2':
        {
            cout << "Enter Node to be Removed" << endl;
            cin >> num;
            T.remove(num);
            break;

        }

        case '3':

        {
            T.showInOrder();
            break;

        }

        case '4':

        {

            T.showPreOrder();
            break;
        }


        case '5':

        {

            T.showPostOrder();
            break;

        }

        case '6':
        {
            cout << "Enter Node to be searched" << endl;
            cin >> num;
            exists= T.search(num);


            if (exists == true)
            {
                cout << "Node Exists" << endl;



            }

            else
                cout << "Node does not exist" << endl;

            break;
        }


        case '7':
        {
            Pass = false;
            break;


        }
        }

        

    }


}
