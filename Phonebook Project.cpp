#include <iostream>
#include<string>
#include <ctype.h>
using namespace std;


class Contact
{
public:
    string firstName, lastName, number;
    Contact *next, *prev;

    Contact(string firstName, string lastName, string number, Contact* ptr= NULL)
    {
      this->firstName = firstName;
      this->lastName = lastName;
      this->number = number;
      next = prev = ptr;
    }
};

class Phonebook
{
  private:
    Contact *head, *tail;

  public:
    //Constructor
    Phonebook()
    {
      head = tail = NULL;
    }
    ~Phonebook()
    {
        Contact *temp;
        while (head!=NULL)
        {
            temp = head;
            head= head->next;
            delete temp;
        }
        head = tail = NULL;
    }

    //1-Adds contact to phonebook
    void addContact(string firstName, string lastName,string number)
    {
      Contact *newContact = new Contact(firstName, lastName, number);
      if(head == NULL)
        head = tail = newContact;
      else
      {
        tail->next = newContact;
        newContact->prev = tail;
        tail = newContact;
      }
    }

    //2- displays all contacts in phonebook
    void display()
    {
      Contact *p;
      for(p=head;p!= NULL;p=p->next)
      {
        cout << p->firstName<<" "<<p->lastName<<" "<<p->number<<endl;
        if(p == tail)
          break;
      }
    }

    //3-displays all contacts that start with a given letter.
     void displayByLetter(char c)
    {
      cout <<"all contacts that start with a 'c' letter "<<endl;
      Contact *p1;
      for(p1 = head; p1 != NULL; p1=p1->next)
      {
        if(p1->firstName[0] ==  c)
          cout << p1->firstName<<" "<<p1->lastName<<" "<<p1->number<<endl;
      }
    }
    /*//3-displays all contacts that start with a given letter with while loop.
    void displayByLetter(char c)
    {
        cout <<"all contacts that start with a 'c' letter "<<endl;
        Contact *p1;
        p1=head;
        while(p1!=NULL)
        {
            p1=p1->next;
            if(p1->firstName[0] ==  c)
                cout << p1->firstName<<" "<<p1->lastName<<" "<<p1->number<<endl;
        }
    }
    */
    //4-search for a name. by displaying all contacts with a specific first name
    void searchByFirstName(string fName)
    {
      cout <<"search for a name with a specific first name."<<endl;
      Contact *p1;
      for(p1 = head; p1 != NULL; p1=p1->next)
      {
        if(p1->firstName ==  fName)
        {
          cout << p1->firstName<<" "<<p1->lastName<<" "<<p1->number<<endl;
        }
      }
    }
    /*
    //4-search for a name. by displaying all contacts with a specific first name while for loop..
    void searchByFirstName(string fName)
    {
        cout <<"search for a name with a specific first name."<<endl;
        Contact *p1;
        p1=head;
        while(p1!=NULL)
        {
            p1=p1->next;
            if(p1->firstName==fName)
            {
                cout << p1->firstName<<" "<<p1->lastName<<" "<<p1->number<<endl;
            }
        }
    }
    */
    //5-deletes contact with a specfic first name and last name
    void deleteContact(string firstName, string lastName)
    {
      Contact *p1 = head;
      while(p1 != NULL)
      {
        if(p1->firstName ==  firstName && p1->lastName == lastName)
        {
          if(p1->next != NULL)
          {
            p1->next->prev = p1->prev;
          }
          else
          {
            tail = tail->prev;
          }
          if(p1->prev != NULL)
          {
            p1->prev->next = p1->next;
          }
          else
          {
            head = head->next;
          }
          delete p1;
          break;
        }
        p1 = p1->next;
      }
    }

    //6- edits contact number based on first and last names
    void editEntry(string firstName, string lastName, string number)
    {
      Contact *p1;
      for(p1 = head; p1 != NULL; p1=p1->next)
      {
        if(p1->firstName ==  firstName && p1->lastName == lastName)
        {
          p1->number = number;
        }
      }
    }

    //sorts all contacts alphabetically
    void sortAlphabetically()
    {
      Contact *p2 = head;
      for (Contact *p1 = head; p1 != NULL; p1 = p1->next)
      {
        p2 = head;
        while(p2->next != NULL)
        {
           if (isAlphabeticallyLessThan(p2->firstName, p2->next->firstName) == false)
           {
              swap(p2, p2->next);
           }
          p2 = p2->next;
        }
      }
    }

    void swapAdjacent(Contact *p1, Contact *p2)
    {
      if(p1 == head)
      {
        head = p2;
      }
      if(p2==tail)
      {
        tail = p1;
      }

      p1->prev->next = p2;
      p2->next->prev = p1;

      p1->next = p2->next;
      p2->prev = p1->prev;

      p2->next = p1;
      p1->prev = p2;
    }

    //swaps the contents of two contacts
    void swap(Contact *p1, Contact *p2)
    {
      string tempFirstName = p1->firstName;
      string tempLastName = p1->lastName;
      string tempNumber = p1->number;

      p1->firstName = p2->firstName;
      p1->lastName = p2->lastName;
      p1->number = p2->number;

      p2->firstName = tempFirstName;
      p2->lastName = tempLastName;
      p2->number = tempNumber;
    }


    //checks if one word comes alphabetically first than another word
    bool isAlphabeticallyLessThan(string word1, string word2, int index = 0)
    {
      char letter1 = tolower(word1[index]);
      char letter2 = tolower(word2[index]);
      if(index >= word2.length() or int(letter1) > int(letter2))
      {
        return false;
      }
      else if(index >= word1.length() or int(letter1) < int(letter2))
      {
        return true;
      }
      else
      {
        return isAlphabeticallyLessThan(word1, word2, index + 1);
      }
    }
};

int main()
{
    //string name,number;
  string fName1,sName1,number1,fName2,sName2,number2,fName3,sName3,number3,fName4,sName4,number4;
  cout<<"enter a First Name:";
  cin>>fName1;
  cout<<"enter a Second Name:";
  cin>>sName1;
  cout<<"enter a number:";
  cin>>number1;
  cout<<"enter a First Name:";
  cin>>fName2;
  cout<<"enter a Second Name:";
  cin>>sName2;
  cout<<"enter a number:";
  cin>>number2;


  Phonebook phonebook;
  phonebook.addContact(fName1, sName1,number1);
  phonebook.addContact(fName2, sName2,number2);
  phonebook.addContact("Sabry", "Ali","123456");
  phonebook.addContact("Mohab","Yussef","207");
  cout<<"Original phonebook:"<<endl;
  phonebook.display();
  cout<<endl;
  phonebook.addContact("AAres","Dfd","343432");
  cout<<"Phonebpok after addition of contact:"<<endl;
  phonebook.display();
  cout<<endl;
  cout<<"Contacts that start with the letter 'S':"<<endl;
  phonebook.displayByLetter('S');
  cout<<endl<<"Contacts with the first name 'Sabry':"<<endl;
  phonebook.searchByFirstName("Sabry");
  cout<<endl;
  phonebook.deleteContact("Mona", "Hesham");
  cout<<"Phonebook after deletion of contact 'mona hesham':"<<endl;
  phonebook.display();
  phonebook.sortAlphabetically();
  cout<<endl<<"phonebook after being alphabetically sorted:"<<endl;
  phonebook.display();
  phonebook.editEntry("Sabry", "Mohamed", "01123333");
  cout<<endl<<"Phonebook after editing Sabry's number:"<<endl;
  phonebook.display();
  return 0;
}
