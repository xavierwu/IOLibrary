#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct PersonInfo
{
	string name;
	vector<unsigned long long> phones;
};

int main (int argc, char *argv[])
{
	/* difference among 'endl', 'flush' and 'ends' */
	cout << "hi!" << endl; // writes hi and a newline, then flushes the buffer
	cout << "hi!" << flush; // writes hi, then flushes the buffer; adds no data
	cout << "hi!" << ends; // writes hi and a null, then flushes the buffer
	/* use of 'unitbuf' */
	cout << unitbuf; // all writes to cout after this statement will be flushed immediately
	cout << nounitbuf; // retursn to normal buffering

	cout << endl << endl;

	string fileName;
	ifstream fin;

	/* print a existed file. */
	do {
		cout << "Input a existed file: ";
		cin >> fileName;

		fin.open (fileName, ifstream::in);
		if (fin.is_open ()) {
			string line;
			while (getline (fin, line))
				cout << line << endl;
		} else
			cout << "FILE NOT FOUND!!!" << endl;
	} while (!fin.is_open ());
	fin.close ();

	/* create a file */
	//ofstream fout;
	//bool fileExisted = true;
	//do {
	//	cout << "Input the new file name: ";
	//	cin >> fileName;
	//	fin.open (fileName, ifstream::in);
	//	if (fin.is_open ()) {
	//		fileExisted = true;
	//		cout << "FILE EXISTED!!!" << endl;
	//		fin.close ();
	//	} else {
	//		fileExisted = false;
	//		fout.open (fileName, ofstream::out);
	//		cout << "Write file: (end with a single line \"-*-\" )" << endl;
	//		string line;
	//		while (getline (cin, line)) {
	//			if (line == "-*-")
	//				break;
	//			else
	//				fout << line << endl;
	//		}
	//		fout.close ();
	//	}
	//} while (fileExisted);

	/* using stringstream to read records. */
	do {
		cout << "Input the record file: ";
		cin >> fileName;

		fin.open (fileName, ifstream::in);
		if (!fin.is_open ())
			cout << "FILE NOT FOUND!!!" << endl;
	} while (!fin.is_open ());

	string line;
	vector<PersonInfo> people;
	while (getline (fin, line)) {
		PersonInfo info;
		istringstream record (line);
		record >> info.name;
		unsigned long long word;
		while (record >> word)
			info.phones.push_back (word);
		people.push_back (info);
	}
	fin.close ();

	for (auto curPeople : people) {
		cout << "Name: " << curPeople.name << endl;
		for (auto phone : curPeople.phones)
			cout << phone << endl;
	}
	return 0;
}