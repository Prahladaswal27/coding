#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class sell
{
protected:
    int code; // data memebers of class sell, all are protected
    float price, discount;
    string name;

public:
    void add();
    void search();
    void edit();
    void del();
    void show();
    void list();
    void invoice();
    int is_emp();
};

class supermarket : public sell // Inheritance
{

public:
    void menu();
    void admin();
    void customer();
};

int sell ::is_emp()
{
    char ch;
    cout << "\n\n Is customer a employee: ";
    cin >> ch;

    if (ch == 'Y' || ch == 'y')
        return 1;

    else
        return 0;
}

void supermarket::menu() // Menu method defintion of class bill
{
x:
    system("cls");  // for clear console screen
    int choice;
    char ch;

    string email, pass;
    cout << "\n\n**************************************************************************************************";
    cout << "\n\n\t\t\t\t Control panel"; //  control panel of shop
    cout << "\n\n**************************************************************************************************";
    cout << "\n\n 1. Admin";
    cout << "\n 2. Customer";
    cout << "\n 3. Exit";

    cout << "\n\n Enter the choice(1-3): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        ptr:
        system("cls");
        cout << "\n\n****************************************************************************************";
        cout << "\n\n\t\t\t\t Login System"; // Login system of shop for admin only
        cout << "\n\n****************************************************************************************";
        cout << "\n\n E-mail ID: ";
        cin >> email;

        cout << "\n\n Password: ";
        for (int i = 0; i <= 16; i++)
        {
            ch = getch();

            if (ch == 13)
            {
                break;
            }
            else if (ch == '\b')
            {
                pass.pop_back();
                cout << "\b \b";
            }
            else
            {
                pass += ch;
                cout << "*";
            }

            if (i > 15)
            {
                cout << "\n\n Password must be between 8 to 15 characters";
                getch();
                goto ptr;
            }
        }

        if (email == "psaswal@gmail.com" && pass == "PSA_2002")
        {
            admin();
        }
        else
        {
            cout << "\n\n Invalid E-mail and Password";
            getch();
            goto ptr;
        }
        break;

    case 2:
        customer();

    case 3:
    {
        char a;
        cout << "\n\n\t Do you want to exit from program (Y/N): ";
        cin >> a;

        if (a == 'Y' || a == 'y')
        {
            cout << "\n\n************************************************THANK YOU*************************************************************";
            exit(0);
        }

        goto x;
    }
    default:
        cout << "\n\n Invalid choice....Please try again....";
    }

    getch();
    goto x;
}

void supermarket::admin() // admin function definition of class bill
{
x:
    system("cls");
    int choice;

    cout << "\n\n****************************************************************************************";
    cout << "\n\n\t\t\t\t Admin Panel"; // admin panel of shop
    cout << "\n\n****************************************************************************************";
    cout << "\n\n 1. Add Product";
    cout << "\n 2. Search Product";
    cout << "\n 3. Edit Product";
    cout << "\n 4. Delete Product";
    cout << "\n 5. Show Product";
    cout << "\n 6. Back To Control Panel ";

    cout << "\n\n Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        add(); // add function call for adding the product in shop list
        break;
    case 2:
         edit(); // edit function call for edit the details of specific product
        break;
    case 3:
         search(); // search function call for searching specific product details
        break;
    case 4:
        del(); // delete function call for deleting the specific product from the list of product
        break;
    case 5:
        show(); // show function call for showing the details of all product available in shop list
        break;
    case 6:
        menu();

    default:
        cout << "\n\n Invalid choice...Please try again";
    }

    getch();
    goto x;
}

void supermarket::customer() // customer function definiton of class bill
{
x:
    system("cls");
    int choice;
    cout << "\n\n****************************************************************************************";
    cout << "\n\n\t\t\t\t Customer Panel";
    cout << "\n\n****************************************************************************************";
    cout << "\n\n 1. Sell Product";
    cout << "\n 2. Back to Control Panel";

    cout << "\n\n Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        invoice();
        break;
    case 2:
        menu();
        break;
    default:
        cout << "\n\n Invalid choice... Please try again";
    }

    getch();
    goto x;
}

void sell ::add() //add functions of class bill
{
x: // add product in shop list
    system("cls");

    fstream file;
    int c, found = 0;
    float p, d;
    string n;

    cout << "\n\n****************************************************************************************";
    cout << "\n\n\t\t\t\t Add New Product ";
    cout << "\n\n****************************************************************************************";

    cout << "\n\n Enter Product code: ";
    cin >> code;
    cout << "\n\n Enter Product Name: ";
    cin >> name;
    cout << "\n\n Enter Product Price: ";
    cin >> price;
    cout << "\n\n Discount in %: ";
    cin >> discount;

    file.open("PRODUCT_STORE.txt", ios::in);
    if (!file)
    {
        file.open("PRODUCT_STORE.txt", ios::app | ios::out);
        file << " " << code << "\t\t" << setw(30) << left << name << setw(30) << price << setw(30) << discount << "\n";
        file.close();
    }

    else
    {
        file >> c >> n >> p >> d; // read from file
        while (!file.eof())
        {
            if (c == code || n == name)
            {
                found++;
            }
            file >> c >> n >> p >> d; // read from file
        }

        file.close();
        if (found == 1)
        {
            cout << "\n\n This product no. or product name already exist...Please try again";
            getch();
            goto x;
        }

        else
        {
            file.open("PRODUCT_STORE.txt", ios::app | ios::out);
            // write in file
            file << " " << code << "\t\t" << setw(30) << left << name << setw(30) << price << setw(30) << discount << "\n";
            file.close();
        }
    }

    cout << "\n\n\t\t Record Inserted Successfully...";
}

void sell ::search() // search function of class bill
{                    // search any product details from the shop list
    system("cls");
    fstream file;

    int p_c, found = 0;
    cout << "\n\n****************************************************************************************";
    cout << "\n\n\t\t\t Enter Product code you want to search: ";
    cin >> p_c;

    file.open("PRODUCT_STORE.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File opening error...";
    }
    else
    {
        file >> code >> name >> price >> discount;
        while (!file.eof())
        {
            if (p_c == code)
            {
                system("cls");
                cout << "\n\n\n\n****************************************************************************************";
                cout << "\n\n\t\t\t\t Search record";
                cout << "\n\n****************************************************************************************";
                cout << "\n\n Product code: " << code;
                cout << "\n\n Name: " << name;
                cout << "\n\n Price: " << price;
                cout << "\n\n Discount: " << discount << "%";
                found++;
            }
            file >> code >> name >> price >> discount;
        }

        file.close();
        if (found == 0)
            cout << "\n\n Record Can't found...";
    }
}

void sell ::edit()
{
    system("cls");
    fstream file, file1;
    int p_c, found = 0, c;
    float p, d;
    string n;

    cout << "\n\n\t\t\t\t Edit Record";

    cout << "\n\n****************************************************************************************";
    // cout << "\n\n****************************************************************************************";
    cout << "\n\n\n\t\t\t Products List";
    cout << "\n\n****************************************************************************************";
    file.open("PRODUCT_STORE.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File opening error";
    }
    else
    {
        cout << "\n\n Code\t\t" << setw(30) << left << "Product Name" << setw(30) << "Product Price" << setw(30) << "Discount %";
        file >> code >> name >> price >> discount;

        while (!file.eof())
        {
            cout << "\n " << code << "\t\t" << setw(30) << left << name << setw(30) << price << setw(30) << discount;
            file >> code >> name >> price >> discount;
        }

        file.close();
    }
    cout << "\n\n****************************************************************************************";
    cout << "\n\n Enter Product code you want to edit: ";
    cin >> p_c;

    file.open("PRODUCT_STORE.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File opening error...";
    }

    else
    {
        file1.open("PRODUCT1_STORE.txt", ios::app | ios::out);
        file >> code >> name >> price >> discount;
        while (!file.eof())
        {
            if (p_c == code)
            {
                cout << "\n\n\t\t Enter New details ";
                cout << "\n\n Enter New Product code: ";
                cin >> c;
                cout << "\n\n Enter New Name of product: ";
                cin >> n;
                cout << "\n\n Enter New Price: ";
                cin >> p;
                cout << "\n\n Enter New Discount in %: ";
                cin >> d;
                file1 << " " << c << "\t\t" << setw(30) << left << n << setw(30) << p << setw(30) << d << "\n";
                cout << "\n\n\t\t\tRecord Edit Successfully...";
                found++;
            }

            else
            {
                file1 << " " << code << "\t\t" << setw(30) << left << name << setw(30) << price << setw(30) << discount << "\n";
            }
            file >> code >> name >> price >> discount;
        }
        file.close();
        file1.close();
        remove("PRODUCT_STORE.txt");
        rename("PRODUCT1_STORE.txt", "PRODUCT_STORE.txt");
        if (found == 0)
        {
            cout << "\n\n Record can't found..";
        }
    }
}

void sell::del() // delete function of class sell
{
    system("cls");
    fstream file, file1;
    int p_c, found = 0;

    cout << "\n\n****************************************************************************************";
    cout << "\n\n\t\t\t\t Delete Product";
    cout << "\n\n****************************************************************************************";
    cout << "\n\n Enter Product code you want to delete: ";
    cin >> p_c;

    file.open("PRODUCT_STORE.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File opening error...";
    }

    else
    {
        file1.open("PRODUCT1_STORE.txt", ios::app | ios::out);
        file >> code >> name >> price >> discount;
        while (!file.eof())
        {
            if (code == p_c)
            {
                cout << "\n\n Product Deleted Successfully...";
                found++;
            }

            else
            {
                file1 << " " << code << "\t\t" << setw(30) << left << name << setw(30) << price << setw(30) << discount << "\n";
            }
            file >> code >> name >> price >> discount;
        }
        file.close();
        file1.close();

        remove("PRODUCT_STORE.txt");
        rename("PRODUCT1_STORE.txt", "PRODUCT_STORE.txt");
        if (found == 0)
        {
            cout << "\n\n Record can't found..";
        }
    }
}

void sell ::show() // show function definition of class bill
{
    system("cls");
    fstream file;

    cout << "\n\n****************************************************************************************";
    cout << "\n\n\t\t\t\t Show Products List";
    cout << "\n\n****************************************************************************************";
    file.open("PRODUCT_STORE.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File opening error";
    }
    else
    {
        cout << "\n\n Code\t\t" << setw(30) << left << "Product Name" << setw(30) << "Product Price" << setw(30) << "Discount %";
        file >> code >> name >> price >> discount;

        while (!file.eof())
        {
            cout << "\n " << code << "\t\t" << setw(30) << left << name << setw(30) << price << setw(30) << discount;
            file >> code >> name >> price >> discount;
        }

        file.close();
    }
}

void sell ::list()
{
    fstream file;
    file.open("PRODUCT_STORE.txt", ios::in);
    cout << "\n\n********************************************************************************************\n\n";
    cout << "P.No.\t\t" << setw(20) << left << "PRODUCT NAME" << setw(30) << "PRICE OF PRODUCT" << setw(30) <<"DISCOUNT"<<"\n";
    cout << "\n\n********************************************************************************************\n\n";

    file >> code >> name >> price >> discount;
    while (!file.eof())
    {
        cout << code << "\t\t" << setw(20) << left << name << setw(30) << price << discount<<"\n";
        file >> code >> name >> price >> discount;
    }
    file.close();
}

void sell ::invoice()
{
ptr:
    system("cls");
    fstream file,file2;
    char choice;
    int o_c[50], o_q[50], c = 0,emp = 0;
    float amt = 0, dis = 0, total = 0, r_amo = 0;
    cout << "\n\n\t\t\t\t Invoice Generate";
    file.open("PRODUCT_STORE.txt", ios::in);
    if (!file)
    {
        cout << "\n\n Data Base is Empty...";
    }

    else
    {
        file.close();
        list();
        cout << "\n\n****************************************************************************************";
        cout << "\n\n\t\t\t\t PLACE YOUR ORDER";
        cout << "\n\n****************************************************************************************";

        do
        {
        x:
            cout << "\n\n Enter Product code: ";
            cin >> o_c[c];
            cout << "\n Enter Product quantity: ";
            cin >> o_q[c];
            for (int i = 0; i < c; i++)
            {
                if (o_c[c] == o_c[i])
                {
                    cout << "\n\n Duplicate Product code...";
                    goto x;
                }
            }

            c++;
            cout << "\n\n Do you want Add Another Product (Y,N): ";
            cin >> choice;
        } while (choice == 'Y' || choice == 'y');

        for (int i = 0; i < c; i++)
        {
            file.open("PRODUCT_STORE.txt", ios::in);
            file >> code >> name >> price >> discount;
            while (!file.eof())
            {
                if (code == o_c[i])
                {
                    amt = price * o_q[i];
                    dis = amt - (amt / 100 * discount);
                    total += dis;
                }
                file >> code >> name >> price >> discount;
            }
            file.close();
        }

        if (total == 0)
        {
            cout << "\n\n Product code not found ..... Please try again";
            getch();
            goto ptr;
        }

        if (is_emp() == 1)
        {
            emp = 1;
            total = total - (total * 0.1);
        }
        cout << "\n\n Total Amount: " << total;
        cout << "\n\n Enter Receive Amount: ";
        cin >> r_amo;

        system("cls");
        file2.open("receipt.txt", ios::out);
        cout << "\n\t\t\t\t\t BILL RECEIPT";
        file2 << "\n\n\t\t\t\t BILL RECEIPT";

        cout << "\n\n************************************************************************************************************";
        cout << "\nPr NO.\t\t" << setw(15) << left << "Pr Name" << setw(15) << "Quantity" << setw(15) << "Price" << setw(15) << "Amount" << setw(15)
             << "Amount After Discount";
        cout << "\n\n************************************************************************************************************";

        file2 << "\n\n************************************************************************************************************";
        file2 << "\nPr NO.\t\t" << setw(20) << left << "Pr Name" << setw(20) << "Quantity" << setw(20) << "Price" << setw(20) << "Amount" << setw(20)
              << "total discount  amount";
        file2 << "\n\n************************************************************************************************************";

        for (int i = 0; i < c; i++)
        {
            file.open("PRODUCT_STORE.txt", ios::in);
            file >> code >> name >> price >> discount;
            while (!file.eof())
            {
                if (code == o_c[i])
                {
                    amt = price * o_q[i];
                    dis = amt - (amt / 100 * discount);
                    cout << "\n"
                         << code << "\t\t" << setw(15) << left << name << setw(15) << o_q[i] << setw(15) << price << setw(15)
                         << amt << setw(15) << (amt - total) << "\n";

                    file2 << "\n"
                          << code << "\t\t" << setw(20) << left << name << setw(20) << o_q[i] << setw(20) << price << setw(20)
                          << amt << setw(20) << (amt - total) << "\n";
                }
                file >> code >> name >> price >> discount;
            }
            file.close();
        }
        cout << "\n\n************************************************************************************************************";
        file2 << "\n\n************************************************************************************************************";
        cout << "\n Subtotal: " << total;
        file2 << "\n Subtotal: " << total;
        cout << "\n Receipt total: " << total;
        file2 << "\n Receipt total: " << total;
        cout << "\n\n Total items: " << c;
        file2 << "\n\n Total items: " << c;
        amt = 0;

        for (int i = 0; i < c; i++)
        {
            amt += o_q[i];
        }
        cout << "\n Total Qty sold: " << amt;
        cout << "\n\n Amount Received: " << r_amo;
        cout << "\n Change Given: " << (r_amo - total);
        if(emp == 1)
        cout<<"\t\t\tCONGRALUATION YOU GET 10% EXTRA DISCOUNT";

        cout << "\n\n***********************************THANKS FOR ORDER ****************************************************" << endl;
        file2 << "\n Total Qty sold: " << amt;
        file2 << "\n\n Amount Received: " << r_amo;
        file2 << "\n Change Given: " << (r_amo - total);
        file2<<"\t\t\tCONGRALUATION YOU GET 10% EXTRA DISCOUNT";
        file2 << "\n\n***********************************THANKS FOR ORDER ****************************************************" << endl;
        file2.close();
        
        char more;

        cout << "\nDo you want to buy more products (Y/N): ";
        cin >> more;

        if (more == 'Y' || more == 'y')
        {
            goto ptr;
        }

        else
        {
            if (more == 'N' || 'n')
            {
                cout << "\n\n***********************Press Enter for Return Back to Customer Panel************************************" << endl;
            }
        }
    }
}

int main()
{
    supermarket b;
    b.menu();

    return 0;
    
}
