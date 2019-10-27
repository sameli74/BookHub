#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;

#include "methods.h"


vector<string> parse_input(string message){
	istringstream iss(message);
	vector<string> tokens;
	copy(istream_iterator<string>(iss), istream_iterator<string>(),
		back_inserter(tokens));
	return tokens;
}

int s_to_i(string num){
	int number = 0;
	for (int i = 0; i < num.size(); i++)
	{
		number = number + (num[num.size() - 1 - i] - 48)*pow(10, i);
	}
	return number;
}

string itos(int id){
	string str;
	char buffer[64];				///convert integer to string
	sprintf(buffer, "%d", id);
	for (int i = 0; i < 64; i++)
	{
		if (buffer[i] != '\0')
			str += buffer[i];
		else
			break;
	}								///End of the conversion
	return str;
}

void make_directory(string addr){
	struct stat st = { 0 };
	const char * input = addr.c_str();
	if (stat(input, &st) == -1)
		mkdir(input, 0700);
}

void print_content(std::vector<std::string> content){
	for (int i = 0; i < content.size(); i++) {
		cout << "Line "<< i <<":  "<<content[i]<<endl;
	}
}
std::string replaced_space_with_under(std::string s){
	for (int i = 0; i < s.length(); i++) {
		if(s[i]==' ')
			s[i]='_';
	}
	return s;
}
std::string replaced_under_with_space(std::string s){
	for (int i = 0; i < s.length(); i++) {
		if(s[i]=='_')
			s[i]=' ';
	}
	return s;
}
