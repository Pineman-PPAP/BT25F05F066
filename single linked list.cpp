#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {

    Node* head = nullptr;
    Node* temp;
    Node* newNode;

    int choice, value, position;

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {

        newNode = new Node;

        cout << "Enter data for node " << i << ": ";
        cin >> newNode->data;

        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        }
        else {
            temp = head;

            while (temp->next != nullptr) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }



    do {

        cout << "\n1. Display\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Insert at End\n";
        cout << "4. Insert at Position\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete from Position\n";
        cout << "8. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {


            case 1:

                if (head == nullptr) {
                    cout << "List is empty!";
                }
                else {

                    temp = head;

                    cout << "Linked List: ";

                    while (temp != nullptr) {
                        cout << temp->data << " -> ";
                        temp = temp->next;
                    }

                    cout << "NULL";
                }

                break;



            case 2:

                cout << "Enter value: ";
                cin >> value;

                newNode = new Node;

                newNode->data = value;
                newNode->next = head;

                head = newNode;

                cout << "Node inserted successfully.";

                break;



            case 3:

                cout << "Enter value: ";
                cin >> value;

                newNode = new Node;

                newNode->data = value;
                newNode->next = nullptr;

                if (head == nullptr) {
                    head = newNode;
                }
                else {

                    temp = head;

                    while (temp->next != nullptr) {
                        temp = temp->next;
                    }

                    temp->next = newNode;
                }

                cout << "Node inserted successfully.";

                break;



            case 4:

                cout << "Enter value: ";
                cin >> value;

                cout << "Enter position: ";
                cin >> position;

                newNode = new Node;

                newNode->data = value;

                // Position 1 = beginning
                if (position == 1) {

                    newNode->next = head;
                    head = newNode;
                }

                else {

                    temp = head;

                    // Go to node before required position
                    for (int i = 1; i < position - 1; i++) {

                        if (temp == nullptr) {
                            break;
                        }

                        temp = temp->next;
                    }

                    if (temp == nullptr) {
                        cout << "Invalid position!";
                        delete newNode;
                    }
                    else {

                        newNode->next = temp->next;
                        temp->next = newNode;

                        cout << "Node inserted successfully.";
                    }
                }

                break;


            case 5:

                if (head == nullptr) {
                    cout << "List is empty!";
                }
                else {

                    temp = head;

                    head = head->next;

                    delete temp;

                    cout << "Node deleted successfully.";
                }

                break;




            case 6:

                if (head == nullptr) {
                    cout << "List is empty!";
                }

                // Only one node
                else if (head->next == nullptr) {

                    delete head;
                    head = nullptr;

                    cout << "Node deleted successfully.";
                }

                else {

                    temp = head;

                    // Go to second-last node
                    while (temp->next->next != nullptr) {
                        temp = temp->next;
                    }

                    delete temp->next;

                    temp->next = nullptr;

                    cout << "Node deleted successfully.";
                }

                break;



            case 7:

                cout << "Enter position: ";
                cin >> position;

                if (head == nullptr) {
                    cout << "List is empty!";
                }

                // Delete first node
                else if (position == 1) {

                    temp = head;

                    head = head->next;

                    delete temp;

                    cout << "Node deleted successfully.";
                }

                else {

                    temp = head;

                    // Go to node before the node to delete
                    for (int i = 1; i < position - 1; i++) {

                        if (temp == nullptr) {
                            break;
                        }

                        temp = temp->next;
                    }

                    if (temp == nullptr || temp->next == nullptr) {

                        cout << "Invalid position!";
                    }

                    else {

                        Node* nodeToDelete = temp->next;

                        temp->next = nodeToDelete->next;

                        delete nodeToDelete;

                        cout << "Node deleted successfully.";
                    }
                }

                break;


            case 8:

                cout << "Program ended.";

                break;


            default:

                cout << "Invalid choice!";

        }

    } while (choice != 8);


    return 0;
}