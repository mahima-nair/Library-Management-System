//============================================================================
// Name        : Library Management System.
// Description : Mini Project for PBL
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
const int num = 20;
const int n = 50;
using namespace std;
class library
{
public:
    library()
    {
    }
    void guide(void)
    {
        cout << "\n1.Strict silence, decorum and discipline must be maintained in the library.\n2.Use of cell-phones is also not allowed.\n3.Smoking, eating, sleeping and talking loudly are strictly prohibited in the library.\n4.Documents taken out of the shelves must be left on the table.\n5.Replacing the books on shelves is not encouraged as it may get misplaced.Misplaced book is like a lost book.\n6.A non-member can use the library material on the premises with the permission of the Librarian.\n7.Readers should not mark, underline, dog-ear, write, tear pages or otherwise damage the library documents.\n8.Newspapers, magazines and journals must be read only in the library on specific tables and should not be taken to any other reading areas.\n9.No library material can be taken out of the library without  permission.\n10.Unauthorized removal of anything belonging to the library will be treated as theft and dealt accordingly.\n11.Any one  who  violates  the  rules  and  regulations  of  the  library  would  be  liable  to  lose  the  privilege  of  library membership and may be debarred from using the library facilities.\n12.Suggestions on all aspects,of library services are welcome." << endl;
    }
};
class Book : public library
{
public:
    string title, author, publisher;
    int id, key;
    int price;
    Book()
    {
        price = 0;
        id = key = -1;
    }
    void update(int k, int id1, int p, string t, string a, string publ)
    {
        key = k;
        id = id1;
        price = p;
        title = t;
        author = a;
        publisher = publ;
    }
};
class Student : public library
{
public:
    string title2, studname, branch;
    int id2, key1, roll, isdate, ismon, isyear, redate, retmon, retyear;
    Student()
    {
        id2 = key1 = -1;
    }
    void update(int k, int id1, string t, int isd, int ism, int isy, int red, int rem, int rey, int r, string sname, string b)
    {
        key1 = k;
        id2 = id1;
        title2 = t;
        isdate = isd;
        ismon = ism;
        isyear = isy;
        redate = red;
        retmon = rem;
        retyear = rey;
        roll = r;
        studname = sname;
        branch = b;
    }
};

class hashtable : public Book, public Student
{
	 Book book_table[num];
    Student student_table[n];


public:
      static int count1;
      static int count2;
      static int count;
    int id1;
    int index, ID, i, j, price1;   // book
    int roll1, ID1, index1;        // student
    string title1, author1, publ1; // book
    string stud1, bran1, title2;   // student
    hashtable()
    {
        cout << "Welcome to Pccoe Library" << endl;
    }
    void addbook()
    {
        cout << "Enter Book Id: ";
        cin >> ID;
        cout << endl;
        cout << "Enter Book Title: ";
        cin >> title1;
        cout << endl;
        cout << "Enter Book Author: ";
        cin >> author1;
        cout << endl;
        cout << "Enter Book Publisher: ";
        cin >> publ1;
        cout << endl;
        cout << "Enter Book Price: ";
        cin >> price1;
        cout << endl;
        index = ID % num;
        count = 0;
        int c = 0;
        while (book_table[index].key != -1)
        {
            index = (index + 1) % num;
            c++;
            if (c > num)
            {
                cout << "Table is Full!!" << endl;
                exit(0);
            }
        }
        count2++;
        book_table[index].update(count2, ID, price1, title1, author1, publ1);
    }

    void bookdisplay()
    {
        cout << "Key"<<setw(15)<<"Id"<<setw(15)<<"Price"<<setw(15)<<"Book_Name"<<setw(15)<<"Author"<<setw(15)<<"Publication" <<endl;
        for (i = 0; i < num; i++)
        {
            if (book_table[i].key != -1)
            {
                cout << book_table[i].key <<setw(15)<< book_table[i].id << setw(15)<< book_table[i].price << setw(15) << book_table[i].title << setw(15)<< book_table[i].author << setw(15)<< book_table[i].publisher << endl;
            }
        }
    }

    void booksearch()
    {
        int Id;
        cout << "Enter id of the book you want to check details of: " << endl;
        cin >> Id;
        int flag = 0, count = 0;
        for (j = 0; j < num; j++)
        {
            count++;
            if (Id == book_table[j].id)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            cout << "Book found " << endl;
            cout << "Book Name: " << book_table[j].title << endl;
            cout << "Book Author: " << book_table[j].author << endl;
            cout << "Book publication: " << book_table[j].publisher << endl;
            cout << "Book price: " << book_table[j].price << endl;
        }
        else
        {
            cout << "Book not found" << endl;
        }
    }

    void bookmodify(void)
    {
        int iD;
        string bkname, aname, pubname;
        int pr;
        cout << "Enter the id of the book whose information you want to modify: " << endl;
        cin >> iD;
        for (i = 0; i < num; i++)
        {
            if (iD == book_table[i].id)
            {
                int choice;

                do
                {
                    cout << "Enter 1 to modify Book Name\nEnter 2 to modify Author\nEnter 3 to modify Publisher\nEnter 4 to modify Price\nEnter 0 to stop" << endl;
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                    {

                        cout << "Enter Book Name: ";
                        cin >> bkname;
                        book_table[index].update(count, iD, price1, bkname, author1, publ1);
                        cout << "Key"<<setw(15)<<"Id"<<setw(15)<<"Price"<<setw(15)<<"Book_Name"<<setw(15)<<"Author"<<setw(15)<<"Publication" << endl;
                        bookdisplay();
                        break;
                    }
                    case 2:
                    {
                        cout << "Enter Author Name: ";
                        cin >> aname;
                        book_table[index].update(count, iD, price1, title1, aname, publ1);
                        cout << "Key"<<setw(15)<<"Id"<<setw(15)<<"Price"<<setw(15)<<"Book_Name"<<setw(15)<<"Author"<<setw(15)<<"Publication" << endl;
                        bookdisplay();
                        break;
                    }
                    case 3:
                    {
                        cout << "Enter publisher Name: ";
                        cin >> pubname;
                        book_table[index].update(count, iD, price1, title1, author1, pubname);
                        cout << "Key"<<setw(15)<<"Id"<<setw(15)<<"Price"<<setw(15)<<"Book_Name"<<setw(15)<<"Author"<<setw(15)<<"Publication" << endl;
                        bookdisplay();
                        break;
                    }
                    case 4:
                    {
                        cout << "Enter Price: ";
                        cin >> pr;
                        book_table[index].update(count, iD, pr, title1, author1, pubname);
            cout << "Key"<<setw(15)<<"Id"<<setw(15)<<"Price"<<setw(15)<<"Book_Name"<<setw(15)<<"Author"<<setw(15)<<"Publication" << endl;
                        bookdisplay();
                        break;
                    }
                    }
                } while (choice != 0);
            }
        }
    }

    void issbook()
    {
        cout << "Enter Book id: ";
        cin >> ID1;
        cout << "Enter Book Name: ";
        cin >> title2;
        cout << "Enter book issue date [DD/MM/YY]: " << endl;
        cout << "Enter date: ";
        cin >> isdate;
        cout << "Enter month: ";
        cin >> ismon;
        cout << "Enter year: ";
        cin >> isyear;
        cout << "Enter book should return within this date [DD/MM/YY]: " << endl;
        cout << "Enter date: ";
        cin >> redate;
        cout << "Enter month: ";
        cin >> retmon;
        cout << "Enter year: ";
        cin >> retyear;
        cout << "Enter Student Name: ";
        cin >> stud1;
        cout << "Enter Student Roll No: ";
        cin >> roll1;
        cout << "Enter student branch: ";
        cin >> bran1;

        index1 = (index1) % 5;
        int count1 = 0, c3 = 0;
        while (student_table[index1].key1 != -1)
        {
            index1 = (index1 + 1) % n;
            c3++;
            if (c3 > n)
            {
                cout << "Hashtable Full!!" << endl;
                exit(0);
            }
        }
        count1++;
        student_table[index1].update(count1, ID1, title2, isdate, ismon, isyear, redate, retmon, retyear, roll1, stud1, bran1);
    }

    void isdisplay(void)
    {
            cout << "Key"<<setw(15)<<"Id"<<setw(15)<<"Book_Name"<<setw(15)<<"Issue_Date"<<setw(20)<<"Return_Date"<<setw(20)<<"Student_rollno"<<setw(20)<<"Student_name"<<setw(20)<<"Student_Branch" << endl;

        for (int i = 0; i < n; i++)
        {
            if (student_table[i].key1 != -1)
            {
                cout << student_table[i].key1 << setw(17)<< student_table[i].id2 << setw(15)<< student_table[i].title2 <<setw(12)<< student_table[i].isdate << "/" << student_table[i].ismon << "/" << student_table[i].isyear << setw(12)<< student_table[i].redate << "/" << student_table[i].retmon << "/" << student_table[i].retyear << setw(14)<< student_table[i].roll <<setw(20)<< student_table[i].studname <<setw(20)<< student_table[i].branch << endl;
            }
        }
    }
    void findiss()
    {
        int roll1;
        cout << "Enter the roll number of student you want to find in issue records: ";
        cin >> roll1;
        int found = 0;
        for (int i = 0; i < n; i++)
        {

            if (roll1 == student_table[i].roll)
            {	found=1;
                cout << "Displaying issue student details:" << endl;
                cout << "Student Name: " << student_table[i].studname << endl;
                cout << "Student Roll No: " << student_table[i].roll << endl;
                cout << "Student Branch: " << student_table[i].branch << endl;
                cout << "Issued Date: " << student_table[i].isdate << "/" << student_table[i].ismon << "/" << student_table[i].isyear << endl;
                cout << "Return Within this Date: " << student_table[i].redate << "/" << student_table[i].retmon << "/" << student_table[i].retyear << endl;
                break;
            }
        }
        if(found==0){
        	cout<<"Student Data not found!"<<endl;
        }
    }
    void rebook(void)
    {
        int ro;
        cout << "Enter roll no of the student who want to return book: " << endl;
        cin >> ro;
        for (int i = 0; i < n; i++)
        {
            if (ro == student_table[i].roll)
            {
            	student_table[i].key1 = -1;
            	student_table[i].id2 = -1;
            	student_table[i].branch = " ";
            	student_table[i].studname = " ";
            	student_table[i].title2 = " ";
            	student_table[i].roll = 0;
            }
        }
    }
    void isssearch(void)
    {
        int rl;
        cout << "Enter roll no of the student whose issue student you want: ";
        cin >> rl;
        for (int i = 0; i < n; i++)
        {
            if (rl == student_table[i].roll)
            {
                cout << "Entered Roll No.  found" << endl;
                break;
            }
        }
    }
};
int hashtable::count=0;
int hashtable::count1=0;
int hashtable::count2 = 0;

int main()
{
    int choice;
    library l;
    l.guide();
    fstream file;
    fstream file1;
    hashtable h;
    do
    {
        cout << "**************************** LIBRARY MENU ********************************" << endl;
        cout << "1. Add Books\n2. Display book information\n3. Search Book Information\n4. Modify Book Information\n5. Issue Book\n6. Return Book\n7. Search Issued student\n8. Find issued book details\n9. Display student record\n0. Exit.\n"
             << endl;
        cout << "*********************************************************************************" << endl;
        cout << "Enter your Choice: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            file.open("C:\\Users\\priya\\OneDrive\\Desktop\\file.txt", ios::binary | ios::app);
            h.addbook();
            file.write((char *)&h, sizeof(h));
            file.close();
            break;
        }
        case 2:
        {
            fstream file;
            file.open("C:\\Users\\priya\\OneDrive\\Desktop\\file.txt", ios::binary | ios::in);

            while (file.read((char *)&h, sizeof(h)))
            {
                file.read((char *)&h, sizeof(h));
                h.bookdisplay();
            }
            file.close();
            break;
        }
        case 3:
        {
            h.booksearch();
            break;
        }
        case 4:
        {
            h.bookmodify();
                        cout << "Key"<<setw(15)<<"Id"<<setw(15)<<"Price"<<setw(15)<<"Book_Name"<<setw(15)<<"Author"<<setw(15)<<"Publication" << endl;
            h.bookdisplay();
            break;
        }
        case 5:
        {
             file1.open("C:\\Users\\priya\\OneDrive\\Desktop\\file1.txt", ios::binary | ios::app);
            h.issbook();
            file.write((char *)&h, sizeof(h));
            h.isdisplay();
            file1.close();

            file1.open("C:\\Users\\priya\\OneDrive\\Desktop\\file1.txt",ios::binary|ios::in);
             while (file1.read((char *)&h, sizeof(h)))
            {
                file1.read((char *)&h, sizeof(h));
                h.isdisplay();
            }
            file1.close();
            break;
        }
        case 6:
        {
            file1.open("C:\\Users\\priya\\OneDrive\\Desktop\\file1.txt",ios::binary|ios::in);
            h.rebook();
             while (file1.read((char *)&h, sizeof(h)))
            {
                file1.read((char *)&h, sizeof(h));
                h.isdisplay();
            }
            file1.close();
            h.isdisplay();
            break;
        }
        case 7:
        {
            h.isssearch();
            break;
        }
        case 8:
        {
            h.findiss();
            break;
        }
        case 9:
        {
            h.isdisplay();
            break;
        }
        }
    } while (choice != 0);
    return 0;
}
