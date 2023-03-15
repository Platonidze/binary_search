#include <fstream>
#include <vector>
#include <iterator>
#include <iostream>
#include <cassert>

using namespace std;

vector<int> read_list_from_file(string s)
{
	vector<int> v;
	ifstream fin(s);
	int tmp;
	while(fin >> tmp)
		v.push_back(tmp);
	return v;
}

pair<vector<int>::iterator, int> bin_search(int z, vector<int>::iterator ib, vector<int>::iterator ie)
{
	static int n =0;n++;
	static vector<int>::iterator sie=ie;
	vector<int>::iterator iz = ib+distance(ib,ie)/2;
	if(*iz==z)
		return make_pair(iz, n);
	else if(ib==iz)
                return make_pair(sie, n);
	else if(*iz>z)
		return bin_search(z, ib, iz);
	else return bin_search(z, iz, ie);
}

int main(int c, char* a[])
{
	assert(c==3);
	vector<int>v=read_list_from_file(a[2]);
	/*for (int i=0; i< v.size();i++)
		cout<< v[i] << endl;*/
	//cout<<v[v.size()/2]<<endl;
	
	pair<vector<int>::iterator, int> para = bin_search(stoi(a[1]), v.begin(), v.end());
	if(para.first==v.end())
		cout<<"Es gibt kein "<< a[1] << " in der Liste" << endl;
	else
		cout<<*(para.first-1)<< " " << *para.first << " " << *(para.first+1) << endl << "Rekursionstiefe: " << para.second << endl;
	return 0;
}
