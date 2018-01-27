//#include"binarytree.h"
#include"mybinarytree.h"
#include"FileOps.h"
#include<ctime>

int main()
{
	string filename = "bible.txt";
	vector<string> words;
	if (FileOps::readFile(filename, words)) {

		cout << "There are totally " << words.size() << " words in " << filename << endl;

		cout << endl;


		// test BST
		time_t startTime = clock();
		BST<string, int> bst = BST<string, int>();
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
			int *res = bst.search(*iter);
			if (res == NULL)
				bst.insert(*iter, 1);
			else
				(*res)++;
		}

		cout << "god' : " << *bst.search("god") << endl;
		time_t endTime = clock();
		cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

		cout << endl;
	}
	
	return  0;

}