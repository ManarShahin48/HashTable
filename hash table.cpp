/*Implementation of HashTable*/
#include <string>
#include <iostream>
using namespace std;
class HashTable
{
private:
	int n, m;
	/*Create node to use it in the linked list*/
	struct Node
	{
		Node* next;
		string data;
		/*constructor of struct*/
		Node(string str)
		{
			next = NULL;
			data = str;
		}
	};
	/*Create the table of single linked list*/
	Node** table;
	/*Method to convert the string to integer number*/
	int prehash(string value)/*Complexity == O(N)*/
	{
		int sum = 0;
		for (int i = 0;i < value.length(); i++)
			sum += value[i];
		return sum;
	}
	/*Method to convert the huge number to number that it is a smaller than the solts*/
	int hash(int num)/*Complexity == O(1)*/
	{
		return num % m;
	}
public:
	/*Constructor of the class to initial the varibles*/
	HashTable()
	{
		m = 16;
		n = 0;
		table = new Node*[m];
		for (int i = 0; i < m; i++)
			table[i] = NULL;
	}
	/*Method to insert strings in the table*/
	void Insert(string str)/*Complexity == O(1)*/
	{
		
		if (n < m)
		{
			int hashvalue = prehash(str);
			int index = hash(hashvalue);
			//create new node
			Node* newnode = new Node(str);
			newnode->next = table[index];
			table[index] = newnode;
			n++;
		}
		//grow the table
	}
	/*Method to search about any string in the table*/
	bool Search(string str)/*Complexity == O(1)*/
	{
		int hashvalue = prehash(str);
		int index = hash(hashvalue);
		Node* it = table[index];
		while (it != NULL)
		{
			if (it->data == str)
			{
				return true;
			}
			it = it->next;
		} 
		return false;
	}
	/*Method to delete srtings in the table*/
	void Delete(string str)/*Complexity == O(1)*/
	{
		int hashvalue = prehash(str);
		int index = hash(hashvalue);
		Node* it = table[index];
		if (it == NULL)
			return;
		if (it->data == str)
		{
			delete it;
			table[index] = NULL;
			return;
		}
		while (it->next != NULL)
		{

			if (it->next->data == str)
			{
				Node* temp = it->next;
				it->next = temp->next;
				delete temp;
				n--;
				return;
			}
			it = it->next;
		}
	}
};
